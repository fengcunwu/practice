#include"Head.hpp"

//牛客网----数组中出现次数超过一半的数字
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	//map的使用方法
	int size = numbers.size();
	map<int, size_t> arr;
	for (int i = 0; i < size; i++)
		arr[numbers[i]]++;//[]实际上是插入
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > size / 2)
			return i;
	}
	return -1;
}