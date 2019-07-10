#include "DynamicPlanning.h"

//方法一: 递归解法，时间复杂度O(2^n),空间复杂度也很大，会导致栈溢出，重复的步骤也很多
int Fibonacci_01(int n)
{
	if (n == 0)
		return 0;

	if (n == 1 || n == 2)
		return 1;

	return Fibonacci_01(n - 1) + Fibonacci_01(n - 2);
}

//方法二: 动态规划，用数组来呈现数列，时间复杂度O(n),空间复杂度O(n)
/*
方法二：动态规划
状态：F(n)
状态递推：F(n)=F(n-1)+F(n-2)
初始值：F(1)=F(2)=1
返回结果：F(N)
*/

int Fibonacci_02(int n)
{
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	vector<int> arr(n + 1, 0);
	arr[0] = 1;//arr[0] = 0;
	arr[1] = 1;//arr[1] = 1;
	for (int i = 2; i <= n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	return arr[n - 1];//arr[n];
}


//方法三: 动态规划的思想，不用数组，因为最终的值，只和它后两个值有关系
int Fibonacci_03(int n)
{
	if (0 == n)
		return 0;
	if (1 == n || 2 == n)
		return	1;

	int result = 0;
	int f1 = 1;
	int f2 = 1;

	for (int i = 3; i <= n; i++)
	{
		result = f2 + f1;
		f1 = f2;
		f2 = result;
	}

	return result;
}