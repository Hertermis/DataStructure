/*笔记：简单实现双向链表（循环表）*/
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct DNode{
	ElemType data;
	DNode* prior;   
	DNode* next; 
}DNode, *DLList;

//初始化双向链表
void InitList(DLList &L){
	L = new DNode;
	if (L == NULL) {
		throw runtime_error("memory allocation failed");
	}
	L->prior = L;
	L->next = L;
}

//销毁双向链表
void DestroyList(DLList &L){
	DNode* cur;
	DNode* next;
	cur = L->next;
	while(cur != L){
		next = cur->next;
		delete cur;
		cur = next;
	}
	delete L;
	L = NULL;
}

//清空双向链表
void ClearList(DLList &L){
	DNode* cur;
	DNode* next;
	cur = L->next;
	while(cur != L){
		next = cur->next;
		delete cur;
		cur = next;
	}
	L->next = L;
	L->prior = L;
}

//判断双向链表是否为空
bool isEmpty(DLList L){
	return L->next == L;
}

//获取链表长度
int getLength(DLList L){
	DNode* cur = L->next;
	int len = 0;
	while(cur != L){
		len++;
		cur = cur->next;
	}
	return len;
}

//尾部插入
void insertListTail(DLList &L, ElemType e){
	DNode* newNode = new DNode;
	if (newNode == NULL) {
		throw runtime_error("memory allocation failed");
	}
	newNode->data = e;
	newNode->next = L;
	newNode->prior = L->prior;
	L->prior->next = newNode;
	L->prior = newNode;
}

//头部插入
void insertListHead(DLList &L, ElemType e){
	DNode* newNode = new DNode;
	if (newNode == NULL) {
		throw runtime_error("memory allocation failed");
	}
	newNode->data = e;
	newNode->next = L->next;
	newNode->prior = L;
	L->next->prior = newNode;
	L->next = newNode;
}

//任意位置插入
void insertList(DLList &L, int i, ElemType e){
	int len = getLength(L);
	if (i < 1||i > len + 1) {
		throw runtime_error("invalid position");
	}
	if(i==len){
		insertListTail(L, e);
		return;
	}
	DNode* cur = L;
	for(int j = 1; j < i; j++){
		cur = cur->next;
	}
	DNode* newNode = new DNode;
	if (newNode == NULL) {
		throw runtime_error("memory allocation failed");
	}
	newNode->data = e;
	newNode->next = cur->next;
	newNode->prior = cur;
	cur->next->prior = newNode;
	cur->next = newNode;
}

//删除指定位置元素并返回
ElemType deletePos(DLList &L, int i){
	int len = getLength(L);
	if (i < 1 || i > len) {
		throw runtime_error("invalid position");
	}
	DNode* cur = L;
	for(int j = 1; j < i; j++){
		cur = cur->next;
	}
	ElemType e = cur->next->data;
	DNode* del = cur->next;
	cur->next = del->next;
	del->next->prior = cur;
	delete del;
	return e;
}

//获取指定位置元素
ElemType getElem(DLList L, int i){
	int len = getLength(L);
	if (i < 1 || i > len) {
		throw runtime_error("invalid position");
	}
	DNode* cur = L->next;
	for(int j = 1; j < i; j++){
		cur = cur->next;
	}
	return cur->data;
}

//查找元素
int locateElem(DLList L, ElemType e){
	DNode* cur = L->next;
	int i = 1;
	while(cur != L && cur->data != e){
		cur = cur->next;
		i++;
	}
	if(cur == L){
		return 0;
	}
	return i;
}

//打印双向链表
void traverseList(DLList L){
	DNode* cur = L->next;
	while(cur != L){
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

/*
int main() {
	DLList L;
	InitList(L);
	cout << "isEmpty: " << isEmpty(L) << endl;
	cout << "getLength: " << getLength(L) << endl;
	insertListTail(L, 1);
	insertListTail(L, 2);
	insertListTail(L, 3);
	cout << "isEmpty: " << isEmpty(L) << endl;
	cout << "getLength: " << getLength(L) << endl;
	insertListHead(L, 0);
	cout << "isEmpty: " << isEmpty(L) << endl;
	cout << "getLength: " << getLength(L) << endl;
	insertList(L, 2, 4);
	cout << "isEmpty: " << isEmpty(L) << endl;
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