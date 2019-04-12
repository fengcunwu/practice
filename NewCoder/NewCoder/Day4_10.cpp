#include "PracticeEveryDay.hpp"

vector<long long> nums(80, 0);
//牛客网-----客似云来
// 1 1 2 3 5 8 13 
// 计算第i天到第j天的和
void Test_Day4_10_1()
{
	nums[0] = 1;
	nums[1] = 1;
	for (int i = 2; i < 80; i++)
	{
		nums[i] = nums[i - 1] + nums[i - 2];
	}
	int from = 0, to = 0;
	while (cin >> from >> to)
	{
		long sum = 0;
		while (from <= to)
		{
			sum += nums[from - 1];
			from++;
		}
		cout << sum << endl;
	}
}

void isOK(){
	int i = 0;
	cout << &i << endl;
	isOK();
}
//测试系统栈的大小
void Test_Day4_10_2()
{
	isOK();
}
