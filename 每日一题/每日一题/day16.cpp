#include "Head.hpp"

//�걸��----����num��Χ���걸���ĸ��� 28���ڵ�6 �� 28
size_t retPerfectNum(int num)
{
	int count = 0;
	int sum = 0;
	for (int i = 2; i <= num; i++)
	{
		sum = 0;
		for (int j = 1; j <= i / 2; j++)
		{
			if (i % j == 0)
				sum += j;
		}
		if (sum == i)
			count++;
	}
	return count;
}