/*笔记：简单实现顺序栈*/
#include <iostream>
using namespace std;
typedef int ElemType;
#define MAXSIZE 100
typedef struct {
	ElemType data[MAXSIZE];
	int top;
}SqStack;

//初始化栈
void InitStack(SqStack &S){
	S.top = -1;
}

//销毁栈
void DestroyStack(SqStack &S){
	S.top = -1;
}

//清空栈
void ClearStack(SqStack &S){
	S.top = -1;
}

//判断栈是否为空
bool isEmpty(SqStack S){
	return S.top == -1;
}

//获取栈长度
int getLength(SqStack S){
	return S.top + 1;
}

//入栈
void push(SqStack &S, ElemType e){
	if (S.top == MAXSIZE - 1) {
		throw runtime_error("stack overflow");
	}
	S.data[++S.top] = e;
}

//出栈
void pop(SqStack &S, ElemType &e){
	if (S.top == -1) {
		throw runtime_error("stack underflow");
	}
	e = S.data[S.top--];
}

//获取栈顶元素
void getTop(SqStack S, ElemType &e){
	if (S.top == -1) {
		throw runtime_error("stack is empty");
	}
	e = S.data[S.top];
}

/*
int main(){
	SqStack S;
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
	DestroyStack(S);
	cout << "isEmpty: " << isEmpty(S) << endl;
	cout << "getLength: " << getLength(S) << endl;
	return 0;
}
*/