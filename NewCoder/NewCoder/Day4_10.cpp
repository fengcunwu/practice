#include "PracticeEveryDay.hpp"

vector<long long> nums(80, 0);
//ţ����-----��������
// 1 1 2 3 5 8 13 
// �����i�쵽��j��ĺ�
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
//����ϵͳջ�Ĵ�С
void Test_Day4_10_2()
{
	isOK();
}
