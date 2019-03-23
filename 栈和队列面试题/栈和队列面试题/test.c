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
	printf("��ͷΪ:%d ��βΪ:%d ���г���Ϊ%d\n", FrontQueue(&q), BackQueue(&q), SizeQueue(&q));
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
	printf("ջ��Ԫ��Ϊ %d ջ�Ĵ�СΪ%d", TopStack(&ps), SizeStack(&ps));
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
	printf("����ջ��Ϊ :%d ��Сջ��Ϊ : %d ��С��ֵΪ �� %d\n",
		TopStack(&(ps.data)), TopStack(&(ps.Min)), ReturnMin(&ps));
	PopMinStack(&ps);
	PopMinStack(&ps);
	PopMinStack(&ps);
	printf("����ջ��Ϊ :%d ��Сջ��Ϊ : %d ��С��ֵΪ �� %d\n", 
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
	printf("���г���Ϊ �� %d\n", SizeStackByQueue(&q));
	if (IsEmptyStackByQueue(&q))
		printf("����Ϊ�գ�����\n");
	else
		printf("���в�Ϊ��!!!\n");

	printf("��ͷΪ��%d ��βΪ��%d", FrontStackByQueue(&q), BackStackByQueue(&q));
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
	printf("ջ��Ԫ��Ϊ ��%d\n", TopQueueByStack(&ps));
	printf("ջ�ĳ���Ϊ��%d\n", SizeQueueByStack(&ps));
	if (IsEmptyQueueByStack(&ps))
		printf("ջΪ�գ�����\n");
	else
		printf("ջ��Ϊ��!!!\n");
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
	PushSharedStack(&ps, 21, 1);//���Σ�ջ�ĵ�ַ��Ԫ�أ�һ�������������ĸ�ջѹ��
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
	printf("ջ1��ջ��Ϊ��%d \n", TopSharedStack(&ps, 1));
	printf("ջ2��ջ��Ϊ��%d \n", TopSharedStack(&ps, 2));
	printf("/////////////////////////////////////\n");
	printf("ջ1�ĳ���Ϊ��%d \n", SizeSharedStack(&ps, 1));
	printf("ջ2�ĳ���Ϊ��%d \n", SizeSharedStack(&ps, 2));
	printf("/////////////////////////////////////\n");

}

void testQuickSort()
{
	int array[] = { 3, 6, 8, 9, 1, 4, 2, 7, 0, 5 };
	int size = sizeof(array) / sizeof(array[0]);
	printf("����ǰ: ");
	PrintArray(array, size);
	QuickSort(array, size);
	printf("�����: ");
	PrintArray(array, size);
}

int main()
{
	//testQueue();
	//testStack();
	//testMinStack();
	//testStackByQueue();//����ջ��ϱ��һ������
	//testQueueByStack();//����������ϱ��һ��ջ
	//testIsStackValid();
	//testSharedStack();//����ջ
	testQuickSort();
	//system("color 36");
	system("pause");
	return 0;
}