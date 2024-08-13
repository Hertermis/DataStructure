/*笔记：简单实现单链表（带头）*/
#include <iostream>
using namespace std;
using ElemType = int;

typedef struct node{
	ElemType data;
	struct node* next;
}Node, *LinkList;

//初始化链表
void InitList(LinkList &L){
	L = new Node;
	if (L == NULL) {
		throw runtime_error("memory allocation failed");
	}
	L->next = NULL;
}

//销毁链表
void DestroyList(LinkList &L){
	Node* cur;
	while(L){
		cur = L;
		L = L->next;
		delete cur;
	}
}

//清空链表
void ClearList(LinkList &L){
	Node* cur;
	Node* next;
	cur = L->next;
	while(cur){
		next = cur->next;
		delete cur;
		cur = next;
	}
	L->next = NULL;
}

//判断链表是否为空
bool isEmpty(LinkList L){
	return L->next == NULL;
}

//尾部插入元素
void insertListTail(LinkList &L, ElemType e){
	Node* cur = L;
	while(cur->next){
		cur = cur->next;
	}
	Node* newNode = new Node;
	if (newNode == NULL) {
		throw runtime_error("memory allocation failed");
	}
	newNode->data = e;
	newNode->next = NULL;
	cur->next = newNode;
}

//头部插入元素
void insertListHead(LinkList &L, ElemType e){
	Node* newNode = new Node;
	if (newNode == NULL) {
		throw runtime_error("memory allocation failed");
	}
	newNode->data = e;
	newNode->next = L->next;
	L->next = newNode;
}

//获取链表长度
int getLength(LinkList L){
	Node* cur = L->next;
	int length = 0;
	while(cur){
		length++;
		cur = cur->next;
	}
	return length;
}

//在指定位置插入元素
void insertList(LinkList &L, int i, ElemType e){
	int len = getLength(L);
	if(i < 1 || i > len + 1){
		throw runtime_error("invalid position");
	}
	if(i == 1){
		insertListHead(L, e);
		return;
	}
	if(i == len + 1){
		insertListTail(L, e);
		return;
	}
	Node* cur = L;
	for(int j = 1; j < i; j++){
		cur = cur->next;
	}
	Node* newNode = new Node;
	if (newNode == NULL) {
		throw runtime_error("memory allocation failed");
	}
	newNode->data = e;
	newNode->next = cur->next;
	cur->next = newNode;
}

//删除指定位置元素并返回
int deletePos(LinkList &L, int i){
	if(i < 1 || i > getLength(L)){
		throw runtime_error("invalid position");
	}
	Node* cur = L;
	for(int j = 1; j < i; j++){
		cur = cur->next;
	}
	Node* delNode = cur->next;
	cur->next = delNode->next;
	int e = delNode->data;
	delete delNode;
	return e;
}

//获取指定位置元素
ElemType getElem(LinkList L, int i){
	if(i < 1 || i > getLength(L)){
		throw runtime_error("invalid position");
	}
	Node* cur = L->next;
	for(int j = 1; j < i; j++){
		cur = cur->next;
	}
	return cur->data;
}

//查找元素
int locateElem(LinkList L, ElemType e){
	Node* cur = L->next;
	int idx = 1;
	while(cur){
		if(cur->data == e){
			return idx;
		}
		cur = cur->next;
		idx++;
	}
	return 0;
}

//遍历链表
void traverseList(LinkList L){
	Node* cur = L->next;
	while(cur){
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

/*
int main(){
	LinkList L;
	InitList(L);
	cout << "isEmpty: " << isEmpty(L) << endl;
	cout << "getLength: " << getLength(L) << endl;
	insertListTail(L, 1);
	insertListTail(L, 2);
	insertListTail(L, 3);
	cout << "isEmpty: " << isEmpty(L) << endl;
	cout << "getLength: " << getLength(L) << endl;
	insertListHead(L, 0);
	cout << "getLength: " << getLength(L) << endl;
	insertList(L, 2, 4);
	cout << "getLength: " << getLength(L) << endl;
	traverseList(L);
	cout << "deletePos: " << deletePos(L, 2) << endl;
	cout << "getElem: " << getElem(L, 2) << endl;
	cout << "locateElem: " << locateElem(L, 3) << endl;
	traverseList(L);
	ClearList(L);
	cout << "isEmpty: " << isEmpty(L) << endl;
	cout << "getLength: " << getLength(L) << endl;
	DestroyList(L);
	return 0;
}
*/