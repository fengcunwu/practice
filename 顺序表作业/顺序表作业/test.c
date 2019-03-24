#include "seqlist.h"

void testpush_pop()
{
	seqlist seq;
	Initseqlist(&seq);
	//Pushback(&seq, 1);//尾插法
	//Pushback(&seq, 2);
	//Pushback(&seq, 3);
	//Pushback(&seq, 4);
	//Pushback(&seq, 5);
	//Popback(&seq);//尾部删除法
	Pushfount(&seq, 5);//头部插入法
	Pushfount(&seq, 4);
	Pushfount(&seq, 3);
	Pushfount(&seq, 2);
	Pushfount(&seq, 1);
	Popfount(&seq);//头部删除法
	Printflist(&seq);
}

void testremove_find()
{
	int ret = 0;
	seqlist seq;
	Initseqlist(&seq);
	Pushback(&seq, 1);
	Pushback(&seq, 2);
	Pushback(&seq, 3);
	//Pushback(&seq, 4);
	Pushback(&seq, 1);
	Printflist(&seq);
	//ret = find(&seq, 1);//查找指定数据，能找到返回下标。
	//if (ret != -1)
	//{
	//	printf("找到了，下标为%d\n", ret);
	//}
	/*Insert(&seq, 2, 10);*///指定位置插入数据
	/*Erase(&seq, 3);*///删除指定位置数据
	/*Remove(&seq, 1);*///删除指定数据
	//RemoveALL(&seq, 1);//删除所有数据
	/*RemoveALL_OP(&seq, 1);*/
	Printflist(&seq);
}

testassist()
{
	int ret = 0;
	seqlist seq;
	Initseqlist(&seq);
	Pushback(&seq, 1);
	Pushback(&seq, 2);
	Pushback(&seq, 3);
	Pushback(&seq, 4);
	Pushback(&seq, 1);
	Printflist(&seq);
	/*ret = Size(&seq);
	printf("顺序表大小为%d\n", ret);*/
	/*ret = Empty(&seq); 
	if (ret == 1)
		printf("顺序表不为空!!\n");*/
	Swap(seq.data + 1, seq.data + 2);//交换函数
	Printflist(&seq);
}

testsort()
{
	int i = 0;
	int ret = 0;
	seqlist seq;
	Initseqlist(&seq);
	/*for (i = 1; i <= MAX; i++)
	{
		Pushback(&seq, i);
	}*/
	for (i = MAX; i > 0; i--)
	{
		Pushfount(&seq, i);
	}
	Printflist(&seq);
	/*Bubblesort(&seq);*/
	/*Selectsort(&seq);*/
	ret = Binarysearch(&seq, 7);
	/*ret = Binarysearch_R(&seq, 0, seq.sz - 1, 19);*/
	if (ret == -1)
	{
		printf("找不到！！！！\n");
	}
	else
	{
		printf("我要找的是7，能找到，下标为：%d\n", ret);
	}
	Printflist(&seq);
}

void test()
{
	seqlist seq;
	int i = 0;
	int ret = 0;
	Initseqlist(&seq);
	for (i = 1; i < 6; i++)
	{
		Pushback(&seq, i);
	}
	Printflist(&seq);
	ret = find(&seq, 2);
	Insert(&seq, ret, 29);
	Printflist(&seq);
}

int main()
{
	/*testpush_pop();*/
	/*testremove_find();*/
	/*testassist();*/
	/*testsort();*/
	test();
	system("pause");
	return 0;
}