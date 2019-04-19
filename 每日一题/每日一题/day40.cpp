#include "Head.hpp"

//牛客网---发邮件
/*
当n个编号元素放在n个编号位置，元素编号与位置编号各不对应的方法数用D(n)表示，那么D(n-1)就表示n-1个编号元素放在n-1个编号位置，各不对应的方法数，其它类推.
第一步，把第n个元素放在一个位置，比如位置k，一共有n-1种方法；
第二步，放编号为k的元素，这时有两种情况：⑴把它放到位置n，那么，对于剩下的n-1个元素，由于第k个元素放到了位置n，剩下n-2个元素就有D(n-2)种方法；⑵第k个元素不把它放到位置n，这时，对于这n-1个元素，有D(n-1)种方法；
综上得到
D(n) = (n-1) [D(n-2) + D(n-1)]*/
// write your code here cpp

int retRightNum(int num)
{
	vector<long> arr(21);
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 2;
	for (int i = 4; i < 21; i++)
	{
		arr[i] = (i - 1) * (arr[i - 1] + arr[i - 2]);
	}
	return arr[num];
}

//牛客网----最长上升子序列
// 1 1 1 1 1 1 1
// 1 7 3 5 9 4 8 
// 1 2 2 3 4 3 4
// 每一位表示目前最大子序列的长度
size_t retMaxLenght(vector<int>& nums)
{
	int i = 0, j = 0;
	vector<size_t> arr(nums.size(), 1);
	size_t maxSize = 1;
	for (i = 1; i < nums.size(); i++)
	{
		for (j = 0; j < i; j++)
		{
			if (nums[i] > nums[j])
				arr[i] = max(arr[i], arr[j] + 1);
		}
		maxSize = max(arr[i], maxSize);
	}
	return maxSize;
}