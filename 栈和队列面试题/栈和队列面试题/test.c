#include "QueueAndStack.h"

void test()
{
	Queue q;
	InitQueue(&q);
	PushQueue(&q, 1);
	PushQueue(&q, 24); 
	PushQueue(&q, 45);
	PushQueue(&q, 165);
	PushQueue(&q, 577);
	//PopQueue(&q);
	printf("队头为:%d 队尾为:%d 队列长度为%d\n", FrontQueue(&q), BackQueue(&q), SizeQueue(&q));
}

void testStack()
{
	Stack ps;
	InitStack(&ps);
	PushStack(&ps, 1);
	PushStack(&ps, 325);
	PushStack(&ps, 52);
	PushStack(&ps, 3252);
	PushStack(&ps, 10000);
	PopStack(&ps);
	printf("栈顶元素为 %d 栈的大小为%d", TopStack(&ps), SizeStack(&ps));
}

void testMinStack()
{
	MinStack ps;
	InitStack(&(ps.data));
	InitStack(&(ps.Min));
	// 2 3 4 1 2 0 6
	PushMinStack(&ps, 2);
	PushMinStack(&ps, 3);
	PushMinStack(&ps, 4);
	PushMinStack(&ps, 1);
	PushMinStack(&ps, 0);
	PushMinStack(&ps, 6);
	printf("数据栈顶为 :%d 最小栈顶为 : %d 最小数值为 ： %d\n",
		TopStack(&(ps.data)), TopStack(&(ps.Min)), ReturnMin(&ps));
	PopMinStack(&ps);
	PopMinStack(&ps);
	PopMinStack(&ps);
	printf("数据栈顶为 :%d 最小栈顶为 : %d 最小数值为 ： %d\n", 
		TopStack(&(ps.data)), TopStack(&(ps.Min)), ReturnMin(&ps));
}

testStackByQueue()
{
	StackByQueue q;
	InitStackByQueue(&q);
	//2 3 4 1 2 0 6
	/*PushStackByQueue(&q, 2);
	PushStackByQueue(&q, 3);
	PushStackByQueue(&q, 4);
	PushStackByQueue(&q, 1);
	PushStackByQueue(&q, 2);
	PushStackByQueue(&q, 0);
	PushStackByQueue(&q, 6);
	PopStackByQueue(&q);
	PopStackByQueue(&q);*/
	printf("队列长度为 ： %d\n", SizeStackByQueue(&q));
	if (IsEmptyStackByQueue(&q))
		printf("队列为空！！！\n");
	else
		printf("队列不为空!!!\n");

	printf("队头为：%d 队尾为：%d", FrontStackByQueue(&q), BackStackByQueue(&q));
}

testQueueByStack()
{
	QueueByStack ps;
	InitQueueByStack(&ps);
	//2 3 4 1 2 0 6
	/*PushQueueByStack(&ps, 2);
	PushQueueByStack(&ps, 3);
	PushQueueByStack(&ps, 4);
	PushQueueByStack(&ps, 1);
	PushQueueByStack(&ps, 2);
	PushQueueByStack(&ps, 0);
	PushQueueByStack(&ps, 6);*/
	//PopQueueByStack(&ps);
	printf("栈顶元素为 ：%d\n", TopQueueByStack(&ps));
	printf("栈的长度为：%d\n", SizeQueueByStack(&ps));
	if (IsEmptyQueueByStack(&ps))
		printf("栈为空！！！\n");
	else
		printf("栈不为空!!!\n");
}

void testIsStackValid()
{
	int Inarr[] = { 1, 2, 3, 4, 5 };
	int Outarr[] = { 3, 4, 2, 1, 5 };
	IsStackValid(Inarr, 5, Outarr, 5);
}

void testSharedStack()
{
	SharedStack ps;
	InitSharedStack(&ps);
	PushSharedStack(&ps, 21, 1);//传参，栈的地址，元素，一个计数器检查给哪个栈压入
	PushSharedStack(&ps, 42, 1); 
	PushSharedStack(&ps, 56, 1);
	PushSharedStack(&ps, 153, 1);
	PushSharedStack(&ps, 74, 2);
	PushSharedStack(&ps, 2876, 2);
	PushSharedStack(&ps, 236, 2);
	PushSharedStack(&ps, 770, 2);
	PushSharedStack(&ps, 2435, 2);
	PushSharedStack(&ps, 65, 2);
	PopSharedStack(&ps, 1);
	PopSharedStack(&ps, 2);
	/*PopSharedStack(&ps, 2);
	PopSharedStack(&ps, 1);*/
	printf("栈1的栈顶为：%d \n", TopSharedStack(&ps, 1));
	printf("栈2的栈顶为：%d \n", TopSharedStack(&ps, 2));
	printf("/////////////////////////////////////\n");
	printf("栈1的长度为：%d \n", SizeSharedStack(&ps, 1));
	printf("栈2的长度为：%d \n", SizeSharedStack(&ps, 2));
	printf("/////////////////////////////////////\n");

}

void testQuickSort()
{
	int array[] = { 3, 6, 8, 9, 1, 4, 2, 7, 0, 5 };
	int size = sizeof(array) / sizeof(array[0]);
	printf("排序前: ");
	PrintArray(array, size);
	QuickSort(array, size);
	printf("排序后: ");
	PrintArray(array, size);
}

int main()
{
	//testQueue();
	//testStack();
	//testMinStack();
	//testStackByQueue();//两个栈组合变成一个队列
	//testQueueByStack();//两个队列组合变成一个栈
	//testIsStackValid();
	//testSharedStack();//共享栈
	testQuickSort();
	//system("color 36");
	system("pause");
	return 0;
}