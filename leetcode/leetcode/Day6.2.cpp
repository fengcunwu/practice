#include "PracticeHead.h"

//leetcode -- 29 两数相除
int divide(int dividend, int divisor)
{

	if (dividend == 0) return 0;

	//  转换为long long型计算，防止 INT32_MIN / -1 溢出
	long long lldividend = dividend, lldivisor = divisor;
	long long cur_bit = 1, result = 0;

	//  转换为整数计算，最后判断符号
	lldividend = abs(lldividend);
	lldivisor = abs(lldivisor);

	//  先将被除数放大 cur_bit 倍
	//  但是要保证被除数 <= 除数
	while (lldividend >= lldivisor << 1) {
		lldivisor <<= 1;
		cur_bit <<= 1;
	}

	//  除数依次减去被除数的 cur_bit 倍
	//  右移 cur_bit 循环执行减法
	//  直到 除数为 0 或者 cur_bit == 0
	while (cur_bit > 0 && lldividend > 0) {
		if (lldividend >= lldivisor) {
			lldividend -= lldivisor;
			result += cur_bit;
		}
		cur_bit >>= 1;
		lldivisor >>= 1;
	}

	//  判断 result 符号
	result = (dividend > 0 && divisor < 0 ||
		dividend < 0 && divisor > 0) ? -result : result;

	//  判断是否会溢出，并返回结果
	if (result > INT32_MAX) return INT32_MAX;
	return (int)result;
}


//leetcode 35 --- 搜索插入位置
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
