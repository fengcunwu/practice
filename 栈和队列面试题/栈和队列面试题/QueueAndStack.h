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
	int top;//��ʾջ��
}Stack;

typedef struct Queue
{
	DataType array[MAXSIZE];//����,���������ʽ����
	int front;//��ͷ,������,ɾ������
	int back;//��β,��������
	int count;//����,��ס���������ж��ٸ�����
}Queue;

typedef struct MinStack
{
	Stack data;//���ԭ�����ݵ�ջ
	Stack Min;//�����Сֵ��ջ
}MinStack;

typedef struct StackByQueue
{
	Stack ps1;//����У�������ݵ�ջ
	Stack ps2;//�����У���ջ����
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
//���еĽӿ�ʵ��

void InitQueue(Queue* q);
void PushQueue(Queue* q, DataType data);
void PopQueue(Queue* q);
DataType FrontQueue(Queue* q);
DataType BackQueue(Queue* q);
int SizeQueue(Queue* q);
int IsEmptyQueue(Queue* q);//����1��ʾΪ��

/////////////////////////////////////////////////////////////////
//ջ�Ľӿ�ʵ��

void InitStack(Stack* ps);
void PushStack(Stack* ps, DataType data);
void PopStack(Stack* ps);
DataType TopStack(Stack* ps);
int SizeStack(Stack* ps);
int IsEmptyStack(Stack* ps);//����1��ʾΪ��

////////////////////////////////////////////////////////////////
//ջ�Ͷ���������

//ʵ��һ��ջ��Ҫ��ʵ�ֳ�ջ����ջ��������Сֵ��ʱ�临�Ӷ�ΪO(1)

void PushMinStack(MinStack* ps, DataType data);
void PopMinStack(MinStack* ps);
int ReturnMin(MinStack* ps);

//����ջ��ϱ�ɶ���

void InitStackByQueue(StackByQueue* q);
void PushStackByQueue(StackByQueue* q, DataType data);
void PopStackByQueue(StackByQueue* q);
DataType FrontStackByQueue(StackByQueue* q);
DataType BackStackByQueue(StackByQueue* q);
int SizeStackByQueue(StackByQueue* q);
int IsEmptyStackByQueue(StackByQueue* q);

//����������ϱ��һ��ջ

void InitQueueByStack(QueueByStack* ps);
void PushQueueByStack(QueueByStack* ps, DataType data);
void PopQueueByStack(QueueByStack* ps);
DataType TopQueueByStack(QueueByStack* ps);
int SizeQueueByStack(QueueByStack* ps);
int IsEmptyQueueByStack(QueueByStack* ps);

//�����ջ�ͳ�ջ˳��ĺϷ���

int IsStackValid(int* Indix, int Insize, int* Outdix, int Outsize);

//ʵ�ֹ���ջ��һ������Ŀռ䣬���溬������ջ

void InitSharedStack(SharedStack* ps);
void PushSharedStack(SharedStack* ps, DataType data, int flag);
void PopSharedStack(SharedStack* ps, int flag);
DataType TopSharedStack(SharedStack* ps, int flag);
int SizeSharedStack(SharedStack* ps, int flag);
int IsEmptySharedStack(SharedStack* ps, int flag);//����1��ʾΪ��

void Swap(int* left, int* right);


#endif //__QUEUEANDSTACK_H__

