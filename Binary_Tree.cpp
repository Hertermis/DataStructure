/*笔记：简单实现普通二叉树*/
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;
typedef int ElemType;
typedef struct TreeNode{
	ElemType val;		// 结点数据
	struct TreeNode* left, * right; // 左右孩子指针
}BSTreeNode, *BSTree;

//初始化二叉树
void InitTree(BSTree &T){
	T = NULL;
}

//销毁二叉树
void DestroyTree(BSTree &T){
	if(T){
		DestroyTree(T->left);
		DestroyTree(T->right);
		delete T;
		T = NULL;
	}
}

//获取结点内容
ElemType GetElem(BSTree T){
	return T->val;
}

//前序遍历
void PreOrder(BSTree T){
	if(T){
		cout<<GetElem(T)<<" ";
		PreOrder(T->left);
		PreOrder(T->right);
	}
}

//中序遍历
void InOrder(BSTree T){
	if(T){
		InOrder(T->left);
		cout<<GetElem(T)<<" ";
		InOrder(T->right);
	}
}

//后序遍历
void PostOrder(BSTree T){
	if(T){
		PostOrder(T->left);
		PostOrder(T->right);
		cout<<GetElem(T)<<" ";
	}
}

//层次遍历
void LevelOrder(BSTree T){
	queue<BSTree> Q;
	BSTree p = T;
	Q.push(p);
	while(!Q.empty()){
		p = Q.front();
		Q.pop();
		cout<<GetElem(p)<<" ";
		if(p->left){
			Q.push(p->left);
		}
		if(p->right){
			Q.push(p->right);
		}
	}
}

//判空
bool isEmpty(BSTree T){
	return T == NULL;
}

//获取树的深度
int GetDepth(BSTree T){
	if(!T){
		return 0;
	}
	int ldepth = GetDepth(T->left);
	int rdepth = GetDepth(T->right);
	return ldepth > rdepth ? ldepth + 1 : rdepth + 1;
}

//前序序列化与反序列化-以int为结点数据类型
void serialize(BSTree T, ostringstream& out) {
	if (!T) {
		out << "null,";
		return;
	}
	out << T->val << ",";
	serialize(T->left, out);
	serialize(T->right, out);
}

string serialize(BSTree T) {
	ostringstream out;
	serialize(T, out);
	return out.str();
}

BSTree deserialize(istringstream& in) {
	string val;
	getline(in, val, ',');
	if (val == "null") {
		return nullptr;
	}
	TreeNode* T = new TreeNode;
	T->val = stoi(val);
	T->left = deserialize(in);
	T->right = deserialize(in);
	return T;
}

BSTree deserialize(string data) {
	istringstream in(data);
	return deserialize(in);
}


/*
int main() {
	string data = "1,2,null,null,3,4,null,null,5,null,null,";
	Tree T = deserialize(data);
	cout << "PreOrder: ";
	PreOrder(T);
	cout << endl;
	cout << "InOrder: ";
	InOrder(T);
	cout << endl;
	cout << "PostOrder: ";
	PostOrder(T);
	cout << endl;
	cout << "LevelOrder: ";
	LevelOrder(T);
	cout << endl;
	cout << "Depth: " << GetDepth(T) << endl;
	DestroyTree(T);
	return 0;
}
*/
