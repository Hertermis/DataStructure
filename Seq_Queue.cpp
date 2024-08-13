/*笔记：简单实现顺序队列*/
#include <iostream>
using namespace std;
typedef int ElemType;
#define MAXSIZE 100
typedef struct{
	ElemType data[MAXSIZE];
	int front, rear;
	int length;
} SqQueue;

//初始化队列
void InitQueue(SqQueue &Q){
	Q.front = Q.rear = 0;
	Q.length = 0;
}

//销毁队列
void DestroyQueue(SqQueue &Q){
	Q.front = Q.rear = 0;
	Q.length = 0;
}

//获取队列长度
int QueueLength(SqQueue Q){
	return Q.length;
}

//入队
void PushQueue(SqQueue &Q, ElemType x){
	if(Q.length>=MAXSIZE-1){
		throw runtime_error("Queue is full");
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	Q.length++;
}

//出队
void PopQueue(SqQueue &Q, ElemType &x){
	if(Q.length==0){
		throw runtime_error("Queue is empty");
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	Q.length--;
}

//获取队头元素
void Getfront(SqQueue Q, ElemType& x) {
	if (Q.length == 0) {
		throw runtime_error("Queue is empty");
	}
	x = Q.data[Q.front];
}

//遍历队列
void TraverseQueue(SqQueue Q){
	int i = Q.front;
	while(i!=Q.rear){
		cout << Q.data[i] << " ";
		i = (i + 1) % MAXSIZE;
	}
	cout << endl;
}

//int main() {
//	SqQueue Q;
//	InitQueue(Q);
//	PushQueue(Q, 1);
//	PushQueue(Q, 2);
//	PushQueue(Q, 3);
//	PushQueue(Q, 4);
//	PushQueue(Q, 5);
//	TraverseQueue(Q);
//	int x;
//	cout << "QueueLength：" << QueueLength(Q) << endl;
//	PopQueue(Q, x);
//	cout << "PopQueue：" << x << endl;
//	cout << "QueueLength：" << QueueLength(Q) << endl;
//	TraverseQueue(Q);
//	Getfront(Q, x);
//	cout << "Getfront：" << x << endl;
//	DestroyQueue(Q);
//	cout << "QueueLength：" << QueueLength(Q) << endl;
//	return 0;
//}
