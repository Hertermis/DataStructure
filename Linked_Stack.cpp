/*笔记：简单实现链栈*/
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	LNode* next;
}LNode, *LinkStack;

//初始化链栈
void InitStack(LinkStack &S){
	S = NULL;
}

//销毁链栈
void DestroyStack(LinkStack &S){
	LNode* cur;
	while(S){
		cur = S;
		S = S->next;
		delete cur;
	}
}

//清空链栈
void ClearStack(LinkStack &S){
	LNode* cur;
	LNode* next;
	cur = S;
	while(cur){
		next = cur->next;
		delete cur;
		cur = next;
	}
	S = NULL;
}

//判断链栈是否为空
bool isEmpty(LinkStack S){
	return S == NULL;
}

//获取链栈长度
int getLength(LinkStack S){
	LNode* cur = S;
	int len = 0;
	while(cur){
		len++;
		cur = cur->next;
	}
	return len;
}

//入栈
void push(LinkStack &S, ElemType e){
	LNode* newNode = new LNode;
	if (newNode == NULL) {
		throw runtime_error("memory allocation failed");
	}
	newNode->data = e;
	newNode->next = S;
	S = newNode;
}

//出栈
void pop(LinkStack &S, ElemType &e){
	if (S == NULL) {
		throw runtime_error("stack underflow");
	}
	LNode* cur = S;
	e = cur->data;
	S = S->next;
	delete cur;
}

//获取栈顶元素
void getTop(LinkStack S, ElemType &e){
	if (S == NULL) {
		throw runtime_error("stack is empty");
	}
	e = S->data;
}

/*
int main(){
	LinkStack S;
	InitStack(S);
	cout << "isEmpty: " << isEmpty(S) << endl;
	cout << "getLength: " << getLength(S) << endl;
	push(S, 1);
	push(S, 2);
	push(S, 3);
	cout << "isEmpty: " << isEmpty(S) << endl;
	cout << "getLength: " << getLength(S) << endl;
	int e;
	getTop(S, e);
	cout << "getTop: " << e << endl;
	pop(S, e);
	cout << "pop: " << e << endl;
	cout << "getLength: " << getLength(S) << endl;
	ClearStack(S);
	cout << "isEmpty: " << isEmpty(S) << endl;
	cout << "getLength: " << getLength(S) << endl;
	DestroyStack(S);
	return 0;
}
*/