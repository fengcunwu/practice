#include"Head.hpp"

//ţ����----�����г��ִ�������һ�������
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	//map��ʹ�÷���
	int size = numbers.size();
	map<int, size_t> arr;
	for (int i = 0; i < size; i++)
		arr[numbers[i]]++;//[]ʵ�����ǲ���
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > size / 2)
			return i;
	}
	return -1;
}