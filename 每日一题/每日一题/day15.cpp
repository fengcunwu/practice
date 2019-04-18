#include "Head.hpp"

//�����������1�ĸ���
size_t findNumberOf1(int num)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (num & 1 == 1)
			count++;
		num = num >> 1;
	}
	return count;
}

//ţ����----����
//��Ҫ˼���ǣ���������ȡ��ȫ�����ף�Ȼ������������ȡ��һֻ���׾Ϳ�������Ҫ��ע����ɫΪ0������
size_t findMinimum(int n, vector<int> left, vector<int> right)
{
	int sum = 0;
	int leftSum = 0, rightSum = 0;
	int leftMin = 30, rightMin = 30;
	for (int i = 0; i<n; i++)
	{
		if (left[i] * right[i] == 0)
			sum += (left[i] + right[i]);//ע�����ɫΪ0�����
		else{
			leftSum += left[i];
			rightSum += right[i];
			leftMin = min(leftMin, left[i]);
			rightMin = min(rightMin, right[i]);
		}
	}
	return sum + min(leftSum - leftMin + 1, rightSum - rightMin + 1) + 1;//
}