#include "seqlist.h"

void testpush_pop()
{
	seqlist seq;
	Initseqlist(&seq);
	//Pushback(&seq, 1);//β�巨
	//Pushback(&seq, 2);
	//Pushback(&seq, 3);
	//Pushback(&seq, 4);
	//Pushback(&seq, 5);
	//Popback(&seq);//β��ɾ����
	Pushfount(&seq, 5);//ͷ�����뷨
	Pushfount(&seq, 4);
	Pushfount(&seq, 3);
	Pushfount(&seq, 2);
	Pushfount(&seq, 1);
	Popfount(&seq);//ͷ��ɾ����
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
	//ret = find(&seq, 1);//����ָ�����ݣ����ҵ������±ꡣ
	//if (ret != -1)
	//{
	//	printf("�ҵ��ˣ��±�Ϊ%d\n", ret);
	//}
	/*Insert(&seq, 2, 10);*///ָ��λ�ò�������
	/*Erase(&seq, 3);*///ɾ��ָ��λ������
	/*Remove(&seq, 1);*///ɾ��ָ������
	//RemoveALL(&seq, 1);//ɾ����������
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
	printf("˳����СΪ%d\n", ret);*/
	/*ret = Empty(&seq); 
	if (ret == 1)
		printf("˳���Ϊ��!!\n");*/
	Swap(seq.data + 1, seq.data + 2);//��������
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
		printf("�Ҳ�����������\n");
	}
	else
	{
		printf("��Ҫ�ҵ���7�����ҵ����±�Ϊ��%d\n", ret);
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