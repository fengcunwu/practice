#include "PracticeHead.h"

int main()
{
	vector<int> arr1 = { 9, 9, 9, 9 };
	vector<int> ret = plusOne(arr1);
	for (auto & e : ret)
		cout << e << endl;
	searchInsert(arr1, 5);
	system("pause");
	return 0;
}