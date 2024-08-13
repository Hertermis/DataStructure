/*笔记：简单实现前缀树*/
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Trie {
    struct Node {
        int pass;
        int end;
        unordered_map<int, Node*> next;
        Node() : pass(0), end(0) {};
    };
    Node* head;
public:
    Trie() : head(new Node()) {}

    //在前缀树中插入一个单词
    void insert(string word) {
        if (word.length() < 1) {
            head->end++;
            return;
        }
        Node* cur = head;
        cur->pass++;
        for (int i = 0; i < word.length(); i++) {
            if (cur->next.find(word[i]) == cur->next.end()) {
                cur->next.insert(make_pair(word[i], new Node()));
            }
            cur = cur->next[word[i]];
            cur->pass++;
        }
        cur->end++;
    }

    //返回前缀树中等于word的单词数量
    int countWordsEqualTo(string word) {
        Node* cur = head;
        for (int i = 0; i < word.length(); i++) {
            if (cur->next.find(word[i]) == cur->next.end()) {
                return 0;
            }
            cur = cur->next[word[i]];
        }
        return cur->end;
    }

    //返回前缀树中以prefix为前缀的单词数量
    int countWordsStartingWith(string prefix) {
        Node* cur = head;
        for (int i = 0; i < prefix.length(); i++) {
            if (cur->next.find(prefix[i]) == cur->next.end()) {
                return 0;
            }
            cur = cur->next[prefix[i]];
        }
        return cur->pass;
    }

    //在前缀树中删除一个单词
    void erase(string word) {
        if (countWordsEqualTo(word) == 0) {
            return;
        }
        if (word.length() == 0) {
            head->end--;
            head->pass--;
            return;
        }
        Node* cur = head, * pre;
        cur->pass--;
        for (int i = 0; i < word.length(); i++) {
            pre = cur;
            cur = cur->next[word[i]];
            cur->pass--;
            if (cur->pass == 0) {
                pre->next.erase(word[i]);
            };
        }
        cur->end--;
    }
};

/*
int main() {
	Trie trie;
    trie.insert("apple");
    trie.insert("adpe");
    trie.insert("aple");
    trie.insert("");
    trie.insert("e");
    trie.insert("eea");
    trie.insert("ae");
    trie.insert("apple");
    trie.insert("apple");
    cout << "countWordsEqualTo:\"ap\"     " << trie.countWordsEqualTo("ap") << endl;
    cout << "countWordsEqualTo:\"apple\"     " << trie.countWordsEqualTo("apple") << endl;
    cout << "countWordsStartingWith:\"\"     " << trie.countWordsStartingWith("") << endl;
    cout << "countWordsStartingWith:\"a\"     " << trie.countWordsStartingWith("a") << endl;
    cout << "erase one \"apple\"" << endl;
    trie.erase("apple");
    cout << "countWordsEqualTo:\"apple\"     " << trie.countWordsEqualTo("apple") << endl;
	return 0;
}
*/