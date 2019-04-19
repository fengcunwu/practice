#include "Head.hpp"

//ţ����---���ʼ�
/*
��n�����Ԫ�ط���n�����λ�ã�Ԫ�ر����λ�ñ�Ÿ�����Ӧ�ķ�������D(n)��ʾ����ôD(n-1)�ͱ�ʾn-1�����Ԫ�ط���n-1�����λ�ã�������Ӧ�ķ���������������.
��һ�����ѵ�n��Ԫ�ط���һ��λ�ã�����λ��k��һ����n-1�ַ�����
�ڶ������ű��Ϊk��Ԫ�أ���ʱ������������Ű����ŵ�λ��n����ô������ʣ�µ�n-1��Ԫ�أ����ڵ�k��Ԫ�طŵ���λ��n��ʣ��n-2��Ԫ�ؾ���D(n-2)�ַ������Ƶ�k��Ԫ�ز������ŵ�λ��n����ʱ��������n-1��Ԫ�أ���D(n-1)�ַ�����
���ϵõ�
D(n) = (n-1) [D(n-2) + D(n-1)]*/
// write your code here cpp

int retRightNum(int num)
{
	vector<long> arr(21);
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 2;
	for (int i = 4; i < 21; i++)
	{
		arr[i] = (i - 1) * (arr[i - 1] + arr[i - 2]);
	}
	return arr[num];
}

//ţ����----�����������
// 1 1 1 1 1 1 1
// 1 7 3 5 9 4 8 
// 1 2 2 3 4 3 4
// ÿһλ��ʾĿǰ��������еĳ���
size_t retMaxLenght(vector<int>& nums)
{
	int i = 0, j = 0;
	vector<size_t> arr(nums.size(), 1);
	size_t maxSize = 1;
	for (i = 1; i < nums.size(); i++)
	{
		for (j = 0; j < i; j++)
		{
			if (nums[i] > nums[j])
				arr[i] = max(arr[i], arr[j] + 1);
		}
		maxSize = max(arr[i], maxSize);
	}
	return maxSize;
}