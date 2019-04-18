#include "Head.hpp"

//计算二进制中1的个数
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

//牛客网----手套
//主要思想是，在左手套取出全部手套，然后在右手套里取出一只手套就可以满足要求，注意颜色为0的手套
size_t findMinimum(int n, vector<int> left, vector<int> right)
{
	int sum = 0;
	int leftSum = 0, rightSum = 0;
	int leftMin = 30, rightMin = 30;
	for (int i = 0; i<n; i++)
	{
		if (left[i] * right[i] == 0)
			sum += (left[i] + right[i]);//注意该颜色为0的情况
		else{
			leftSum += left[i];
			rightSum += right[i];
			leftMin = min(leftMin, left[i]);
			rightMin = min(rightMin, right[i]);
		}
	}
	return sum + min(leftSum - leftMin + 1, rightSum - rightMin + 1) + 1;//
}