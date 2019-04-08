#include "Practice.hpp"

using namespace std;

int main()
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
	return 0;
}