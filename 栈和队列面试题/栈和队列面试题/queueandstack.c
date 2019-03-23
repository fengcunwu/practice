#include "QueueAndStack.h"

void InitQueue(Queue* q)
{
	assert(q);
	q->back = 0;
	q->front = 0;
	q->count = 0;
}

void PushQueue(Queue* q, DataType data)
{
	assert(q);
	if (q->back == q->front && q->count == MAXSIZE)
	{
		printf("队列已满,无法插入!!!\n");
		return;
	}
	else
	{
		if (q->back == MAXSIZE)
			q->back = 0;
		q->array[q->back] = data;
		q->back++;
		q->count++;
	}
}

void PopQueue(Queue* q)
{	
	assert(q);
	if (q->back == q->front && q->count == 0)
	{
		printf("队列为空,无法删除！！！\n");
		return;
	}
	else
	{
		q->front++;
		q->count--;
	}
}

DataType FrontQueue(Queue* q)
{
	assert(q);
	if (q->back == q->front && q->count == 0)
	{
		printf("队列为空,没有队头元素！！！\n");
		return;
	}
	return q->array[q->front];
}

DataType BackQueue(Queue* q)
{
	assert(q);
	if (q->back == q->front && q->count == 0)
	{
		printf("队列为空,没有队尾元素！！！\n");
		return;
	}
	return q->array[q->back - 1];
}

int SizeQueue(Queue* q)
{
	assert(q);
	return q->count;
}

int IsEmptyQueue(Queue* q)//返回1,说明为空
{
	assert(q);
	return 0 == q->count;
}

void InitStack(Stack* ps)
{
	assert(ps);
	ps->top = 0;
}

void PushStack(Stack* ps, DataType data)
{
	assert(ps);
	if (ps->top == MAXSIZE)
	{
		printf("栈已满，无法插入！！！\n");
		return;
	}
	ps->array[ps->top] = data;
	ps->top++;
}

void PopStack(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
	{
		printf("栈为空，无法出栈！！\n");
		return;
	}
	ps->top--;
}

DataType TopStack(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
	{
		printf("栈为空,没有栈顶元素！！\n");
		return;
	}
	return ps->array[ps->top - 1];
}

int SizeStack(Stack* ps)
{
	assert(ps);
	return ps->top;
}

int IsEmptyStack(Stack* ps)//返回1表示为空
{
	assert(ps);
	return 0 == ps->top;
}

void PushMinStack(MinStack* ps, DataType data)
{
	assert(ps);
	if (ps->data.top == MAXSIZE || ps->Min.top == MAXSIZE)
	{
		printf("栈已满，无法插入！！！\n");
		return;
	}
	PushStack(&(ps->data), data);
	if (IsEmptyStack(&(ps->Min)) || data <= TopStack(&(ps->Min)))
	{
		PushStack(&(ps->Min), data);
	}
}

void PopMinStack(MinStack* ps)
{
	assert(ps);
	if (ps->data.top == 0)
	{
		printf("栈为空,无法出栈!!!\n");
		return;
	}
	if (TopStack(&(ps->data)) == TopStack(&(ps->Min)))
	{
		PopStack(&(ps->data));
		PopStack(&(ps->Min));
	}
	else
		PopStack(&(ps->data));
}

int ReturnMin(MinStack* ps)
{
	assert(ps);
	if (ps->Min.top == 0)
	{
		printf("存放最小值的栈为空，无法返回！！！\n");
		return;
	}
	return TopStack(&(ps->Min));
}

void InitStackByQueue(StackByQueue* q)
{
	assert(q);
	InitStack(&(q->ps1));
	InitStack(&(q->ps2));
}

void PushStackByQueue(StackByQueue* q, DataType data)
{
	assert(q);
	if (q->ps1.top == MAXSIZE)
	{
		printf("队列已满，无法进队");
	}
	else
	{
		PushStack(&(q->ps1), data);
	}
}

void PopStackByQueue(StackByQueue* q)
{
	assert(q);
	if (IsEmptyStack(&(q->ps1)) && IsEmptyStack(&(q->ps2)))
	{
		printf("该队列为空，无法删除！！！\n");
		return;
	}
	while (IsEmptyStack(&(q->ps2)))
	{
		PushStack(&(q->ps2), TopStack(&(q->ps1)));
		PopStack(&(q->ps1));
	}
	PopStack(&(q->ps2));
}

DataType FrontStackByQueue(StackByQueue* q)
{
	assert(q);
	if (IsEmptyStack(&(q->ps1)) && IsEmptyStack(&(q->ps2)))
	{
		printf("该队列为空，没有队头数据\n");
		return -1;
	}
	while (!IsEmptyStack(&(q->ps1)))
	{
		PushStack(&(q->ps2), TopStack(&(q->ps1)));
		PopStack(&(q->ps1));
	}
	return TopStack(&(q->ps2));
}

DataType BackStackByQueue(StackByQueue* q)
{
	assert(q);
	if (IsEmptyStack(&(q->ps1)) && IsEmptyStack(&(q->ps2)))
	{
		printf("该队列为空，没有队尾数据\n");
		return -1;
	}
	while (!IsEmptyStack(&(q->ps2)))
	{
		PushStack(&(q->ps1), TopStack(&(q->ps2)));
		PopStack(&(q->ps2));
	}
	return TopStack(&(q->ps1));
}

int SizeStackByQueue(StackByQueue* q)
{
	assert(q);
	return (q->ps1.top) + (q->ps2.top);
}

int IsEmptyStackByQueue(StackByQueue* q)
{
	assert(q);
	return 0 == SizeStackByQueue(q);
}

void InitQueueByStack(QueueByStack* ps)
{
	assert(ps);
	InitQueue(&(ps->q1));
	InitQueue(&(ps->q2));
}

void PushQueueByStack(QueueByStack* ps, DataType data)
{
	assert(ps);
	if (ps->q1.count == MAXSIZE)
	{
		printf("栈已满,无法插入!!!\n");
		return;
	}
	PushQueue(&(ps->q1), data);
}

void PopQueueByStack(QueueByStack* ps)
{
	assert(ps);
	if (IsEmptyQueue(&(ps->q1)) && IsEmptyQueue(&(ps->q2)))
	{
		printf("该栈为空，无法删除！！！\n");
		return;
	}
	if (IsEmptyQueue(&(ps->q2)))
	{
		while (SizeQueue(&(ps->q1)) > 1)
		{
			PushQueue(&(ps->q2), FrontQueue(&(ps->q1)));
			PopQueue(&(ps->q1));
		}
		PopQueue(&(ps->q1));
	}
	if (IsEmptyQueue(&(ps->q1)))
	{
		while (SizeQueue(&(ps->q2)) > 1)
		{
			PushQueue(&(ps->q1), FrontQueue(&(ps->q2)));
			PopQueue(&(ps->q2));
		}
		PopQueue(&(ps->q2));
	}
}

DataType TopQueueByStack(QueueByStack* ps)
{
	assert(ps);
	if (IsEmptyQueue(&(ps->q1)) && IsEmptyQueue(&(ps->q2)))
	{
		printf("该栈为空，没有栈顶元素\n");
		return -1;
	}
	if (IsEmptyQueue(&(ps->q1)))
		return BackQueue(&(ps->q2));
	if (IsEmptyQueue(&(ps->q2)))
		return BackQueue(&(ps->q1));
}

int SizeQueueByStack(QueueByStack* ps)
{
	assert(ps);
	return SizeQueue(&(ps->q1)) + SizeQueue(&(ps->q2));
}

int IsEmptyQueueByStack(QueueByStack* ps)//返回1为空
{
	assert(ps);
	return 0 == (SizeQueueByStack(ps));
}

int IsStackValid(int* Inarr, int Insize, int* Outarr, int Outsize)
{
	Stack ps;
	int inidx = 0, outidx = 0;
	InitStack(&ps);
	//入栈和出栈元素个数不同
	if (Insize != Outsize)
		return 0;

	while (Outsize > outidx)
	{
		while (IsEmptyStack(&ps) || TopStack(&ps) != Outarr[outidx])
		{
			if (inidx < Insize)
			{
				PushStack(&ps, Inarr[inidx]);
				inidx++;
			}
			else
			{
				printf("入栈和出栈的次序匹配出错！！！\n");
				return 0;
			}
				
		}
		PopStack(&ps);
		outidx++;

		//栈为空 ————> outidx到了边界，次序匹配合法
		//       ————> outidx没有到边界，不能判断次序是否匹配合法
	}
	printf("次序匹配合法！！！\n");
	return 1;
}

void InitSharedStack(SharedStack* ps)
{
	assert(ps);

	ps->top1 = 0;
	ps->top2 = 9;
}

void PushSharedStack(SharedStack* ps, DataType data, int flag)
{
	assert(ps);

	if (flag != 1 && flag != 2)
	{
		printf("参数传输有误！！！\n");
		return;
	}

	if (ps->top1 >= ps->top2)
	{
		printf("该栈已满，无法入栈！！\n");
		return;
	}

	if (flag == 1)
		ps->array[ps->top1++] = data;
	else
		ps->array[ps->top2--] = data;
}

void PopSharedStack(SharedStack* ps, int flag)
{
	assert(ps);

	if (ps->top1 == 0 && ps->top2 == 9)
	{
		printf("该栈为空，无法出栈！！\n");
		return 0;
	}

	if (flag != 1 && flag != 2)
	{
		printf("参数传输有误！！！\n");
		return;
	}

	if (flag == 1)
		ps->top1--;
	else
		ps->top2++;
}

DataType TopSharedStack(SharedStack* ps, int flag)
{
	assert(ps);

	if (ps->top1 == 0 && ps->top2 == 9)
	{
		printf("该栈为空，没有栈顶元素！！\n");
		return 0;
	}

	if (flag != 1 && flag != 2)
	{
		printf("参数传输有误！！！\n");
		return;
	}

	if (flag == 1)
		return ps->array[ps->top1 - 1];
	else
		return ps->array[ps->top2 + 1];
}

int SizeSharedStack(SharedStack* ps, int flag)
{
	assert(ps);

	if (flag != 1 && flag != 2)
	{
		printf("参数传输有误！！！\n");
		return;
	}

	if (flag == 1)
		return ps->top1;
	else
		return ps->top2;
}

int IsEmptySharedStack(SharedStack* ps, int flag)//返回1表示为空
{
	assert(ps);

	if (flag != 1 && flag != 2)
	{
		printf("参数传输有误！！！\n");
		return;
	}

	if (flag == 1)
		return 0 == ps->top1;
	else
		return 0 == ps->top2;
}

int DealArray01(int* array, int left, int right)//找最大和最小值交换
{
	int begin = left;
	int end = right - 1;
	int key = array[right - 1];
	while (begin < end)
	{
		while (begin < end && array[begin] <= key)
			begin++;

		while (end > begin && array[end] >= key)
			end--;

		if (begin != end)
			Swap(&array[begin], &array[end]);
	}

	if (begin != right)
		Swap(&array[begin], &array[right - 1]);

	return begin;
}

void PrintArray(int* array, int size)
{
	int i = 0;
	assert(array);
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");
}

void Swap(int* left, int* right)
{
	int temp = 0;
	assert(left && right);
	temp = *left;
	*left = *right;
	*right = temp;
}

void QuickSort(int* array, int size)
{
	int left = 0; 
	int right = size;
	Stack s;
	assert(array);

	InitStack(&s);
	PushStack(&s, right);
	PushStack(&s, left);

	while (!IsEmptyStack(&s))
	{
		int left = TopStack(&s);
		PopStack(&s);

		int right = TopStack(&s);
		PopStack(&s);

		if (left < right)
		{
			int ret = DealArray01(array, left, right);

			PushStack(&s, right);
			PushStack(&s, ret + 1);

			PushStack(&s, ret);
			PushStack(&s, left);
		}
		
	}
}