#include "PracticeHead.h"

//leetcode -- 29 �������
int divide(int dividend, int divisor)
{

	if (dividend == 0) return 0;

	//  ת��Ϊlong long�ͼ��㣬��ֹ INT32_MIN / -1 ���
	long long lldividend = dividend, lldivisor = divisor;
	long long cur_bit = 1, result = 0;

	//  ת��Ϊ�������㣬����жϷ���
	lldividend = abs(lldividend);
	lldivisor = abs(lldivisor);

	//  �Ƚ��������Ŵ� cur_bit ��
	//  ����Ҫ��֤������ <= ����
	while (lldividend >= lldivisor << 1) {
		lldivisor <<= 1;
		cur_bit <<= 1;
	}

	//  �������μ�ȥ�������� cur_bit ��
	//  ���� cur_bit ѭ��ִ�м���
	//  ֱ�� ����Ϊ 0 ���� cur_bit == 0
	while (cur_bit > 0 && lldividend > 0) {
		if (lldividend >= lldivisor) {
			lldividend -= lldivisor;
			result += cur_bit;
		}
		cur_bit >>= 1;
		lldivisor >>= 1;
	}

	//  �ж� result ����
	result = (dividend > 0 && divisor < 0 ||
		dividend < 0 && divisor > 0) ? -result : result;

	//  �ж��Ƿ������������ؽ��
	if (result > INT32_MAX) return INT32_MAX;
	return (int)result;
}


//leetcode 35 --- ��������λ��
int searchInsert(vector<int>& nums, int target)
{
	int len = nums.size();
	if (len == 0 || target <= nums[0])
		return 0;
	if (nums[len - 1] < target)
		return len;

	int left = 0;
	int right = len - 1;
	int mid = 0;
	while (right - left > 1)
	{
		mid = left + (right - left) / 2;
		if (target == nums[mid])
			return mid;
		else if (target < nums[mid])
			right = mid;
		else
			left = mid;
	}
	return right;
}
