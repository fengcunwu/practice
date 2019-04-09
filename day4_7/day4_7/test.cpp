#include "Practice.hpp"

using namespace std;

void Test1()
{
	int year = 0;
	/*int a = 3;
	char b = a + '0';
	cout << b << endl;*/
	while (cin >> year)
	{
		if (year < 2000 || year > 9999)
			break;
		vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (IsLeapYear(year))
			months[2] = 29;
		int WeedDay_CurYear = ReturnWeedDay(year);//得到当前年份一月一日是星期几
		Print(year, months, WeedDay_CurYear);
	}
}

void Test2()
{
	int num = 0; 
	while (cin >> num)
	{
		PrintPrime(num);
		cout << num << " = ";
		while (num != 1)
		{
			for (int i = 2; i <= num; i++)
			{
				if (IsPrime(i) && num % i == 0)
				{
					cout << i;
					num = num / i;
					if (num != 1)
						cout << " * ";
					i = 1;
				}
			}
		}
		cout << endl;
	}
}

void Test3()
{
	vector<int> arr;
	int temp = 0;
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	int year_sum = arr[3] - arr[0];
	int sum_money = 0;
	vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (i = arr[0]; i < arr[3]; i++)
	{
		if (IsLeapYear(i))
			sum_money += 580;
		else
			sum_money += 579;
	}
	if (IsLeapYear(arr[3]))
		months[2] = 29;
	for (i = arr[1]; i < arr[4]; i++)
	{
		if (IsPrime(i))
		{
			if (i == arr[1])
			{
				sum_money += (months[i] - arr[2] + 1);
			}
			else
				sum_money += months[i];
		}
		else
		{
			if (i == arr[1])
			{
				sum_money += (months[i] - arr[2] + 1) * 2;
			}
			else
				sum_money += (months[i] * 2);
		}
	}
	if (IsPrime(arr[4]))
		sum_money += (arr[5]);
	else
		sum_money += ((arr[5]) * 2);

	cout << sum_money << endl;
}
int main()
{
	//Test1();//美国节日
	//Test2();//分解因数
	//Test3();//淘宝网店
	test3();
	system("pause");
	return 0;
}