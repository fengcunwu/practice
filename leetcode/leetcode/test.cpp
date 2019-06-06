#include "PracticeHead.h"

int main()
{
	vector<int> arr1 = { 1, 3, -10, 8 };
	//merge(arr1, arr1.size(), arr2, arr2.size());
	cout << maxSubArray(arr1) << endl;
	searchInsert(arr1, 5);
	system("pause");
	return 0;
}