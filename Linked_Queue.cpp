/*笔记：简单实现链队*/
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct QNode {
	ElemType data;
	QNode* next;
} QNode, *QueuePtr;

typedef struct {
	QueuePtr front, rear;
	int length;
} LinkQueue;

//初始化队列
void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	Q.length = 0;
}

//销毁队列
void DestroyQueue(LinkQueue& Q) {
	while (Q.front) {
		Q.rear = Q.front->next;
		delete Q.front;
		Q.front = Q.rear;
	}
}

//清空队列
void ClearQueue(LinkQueue& Q) {
	QueuePtr p = Q.front->next;
	while (p) {
		Q.rear = p->next;
		delete p;
		p = Q.rear;
	}
	Q.front->next = NULL;
	Q.rear = Q.front;
	Q.length = 0;
}

//获取队列长度
int QueueLength(LinkQueue Q) {
	return Q.length;
}

//入队
void PushQueue(LinkQueue& Q, ElemType x) {
	QueuePtr p = new QNode;
	p->data = x;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	Q.length++;
}

//出队
void PopQueue(LinkQueue& Q) {
	if (Q.length == 0) {
		throw runtime_error("Queue is empty");
	}
	QueuePtr p = Q.front->next;
	Q.front->next = p->next;
	if (Q.rear == p) {
		Q.rear = Q.front;
	}
	delete p;
	Q.length--;
}

//获取队头元素
void Getfront(LinkQueue Q, ElemType& x) {
	if (Q.front == Q.rear) {
		throw runtime_error("Queue is empty");
	}
	x = Q.front->next->data;
}

//遍历队列
void TraverseQueue(LinkQueue Q) {
	QueuePtr p = Q.front->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
/*
int main() {
	LinkQueue Q;
	InitQueue(Q);
	cout << "QueueLength: " << QueueLength(Q) << endl;
	PushQueue(Q, 1);
	PushQueue(Q, 2);
	PushQueue(Q, 3);
	TraverseQueue(Q);
	cout << "QueueLength: " << QueueLength(Q) << endl;
	int e;
	Getfront(Q, e);
	cout << "Getfront: " << e << endl;
	PopQueue(Q);
	cout << "PopQueue" << endl;
	TraverseQueue(Q);
	cout << "QueueLength: " << QueueLength(Q) << endl;
	PopQueue(Q);
	cout << "PopQueue" << endl;
	TraverseQueue(Q);
	PopQueue(Q);
	cout << "PopQueue" << endl;
	cout << "QueueLength: " << QueueLength(Q) << endl;
	DestroyQueue(Q);
	cout << "QueueLength: " << QueueLength(Q) << endl;
	return 0;
}
*/