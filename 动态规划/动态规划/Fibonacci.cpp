#include "DynamicPlanning.h"

//����һ: �ݹ�ⷨ��ʱ�临�Ӷ�O(2^n),�ռ临�Ӷ�Ҳ�ܴ󣬻ᵼ��ջ������ظ��Ĳ���Ҳ�ܶ�
int Fibonacci_01(int n)
{
	if (n == 0)
		return 0;

	if (n == 1 || n == 2)
		return 1;

	return Fibonacci_01(n - 1) + Fibonacci_01(n - 2);
}

//������: ��̬�滮�����������������У�ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
/*
����������̬�滮
״̬��F(n)
״̬���ƣ�F(n)=F(n-1)+F(n-2)
��ʼֵ��F(1)=F(2)=1
���ؽ����F(N)
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


//������: ��̬�滮��˼�룬�������飬��Ϊ���յ�ֵ��ֻ����������ֵ�й�ϵ
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