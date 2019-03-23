#ifndef __QUEUEANDSTACK_H__
#define __QUEUEANDSTACK_H__
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef int DataType;
typedef struct Stack
{
	DataType array[MAXSIZE];
	int top;//表示栈顶
}Stack;

typedef struct Queue
{
	DataType array[MAXSIZE];//队列,以数组的形式给出
	int front;//队头,出数据,删除数据
	int back;//队尾,插入数据
	int count;//计数,记住队列里面有多少个数字
}Queue;

typedef struct MinStack
{
	Stack data;//存放原来数据的栈
	Stack Min;//存放最小值的栈
}MinStack;

typedef struct StackByQueue
{
	Stack ps1;//入队列，存放数据的栈
	Stack ps2;//出队列，从栈顶出
}StackByQueue;

typedef struct QueueByStack
{
	Queue q1;
	Queue q2;
}QueueByStack;

typedef struct SharedStack
{
	DataType array[MAXSIZE];
	int top1;
	int top2;
}SharedStack;

/////////////////////////////////////////////////////////////////
//队列的接口实现

void InitQueue(Queue* q);
void PushQueue(Queue* q, DataType data);
void PopQueue(Queue* q);
DataType FrontQueue(Queue* q);
DataType BackQueue(Queue* q);
int SizeQueue(Queue* q);
int IsEmptyQueue(Queue* q);//返回1表示为空

/////////////////////////////////////////////////////////////////
//栈的接口实现

void InitStack(Stack* ps);
void PushStack(Stack* ps, DataType data);
void PopStack(Stack* ps);
DataType TopStack(Stack* ps);
int SizeStack(Stack* ps);
int IsEmptyStack(Stack* ps);//返回1表示为空

////////////////////////////////////////////////////////////////
//栈和队列面试题

//实现一个栈，要求实现出栈，入栈，返回最小值的时间复杂度为O(1)

void PushMinStack(MinStack* ps, DataType data);
void PopMinStack(MinStack* ps);
int ReturnMin(MinStack* ps);

//两个栈组合变成队列

void InitStackByQueue(StackByQueue* q);
void PushStackByQueue(StackByQueue* q, DataType data);
void PopStackByQueue(StackByQueue* q);
DataType FrontStackByQueue(StackByQueue* q);
DataType BackStackByQueue(StackByQueue* q);
int SizeStackByQueue(StackByQueue* q);
int IsEmptyStackByQueue(StackByQueue* q);

//两个队列组合变成一个栈

void InitQueueByStack(QueueByStack* ps);
void PushQueueByStack(QueueByStack* ps, DataType data);
void PopQueueByStack(QueueByStack* ps);
DataType TopQueueByStack(QueueByStack* ps);
int SizeQueueByStack(QueueByStack* ps);
int IsEmptyQueueByStack(QueueByStack* ps);

//检测入栈和出栈顺序的合法性

int IsStackValid(int* Indix, int Insize, int* Outdix, int Outsize);

//实现共享栈，一个数组的空间，里面含有两个栈

void InitSharedStack(SharedStack* ps);
void PushSharedStack(SharedStack* ps, DataType data, int flag);
void PopSharedStack(SharedStack* ps, int flag);
DataType TopSharedStack(SharedStack* ps, int flag);
int SizeSharedStack(SharedStack* ps, int flag);
int IsEmptySharedStack(SharedStack* ps, int flag);//返回1表示为空

void Swap(int* left, int* right);


#endif //__QUEUEANDSTACK_H__

