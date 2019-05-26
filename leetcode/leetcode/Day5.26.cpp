#include "PracticeHead.h"

using namespace std;

//leetcode---盛最多水的容器
//自己的解法---超出时间限制
int maxArea(vector<int>& height) 
{
	int len = height.size();
	set<int> arr;
	int i = 0;
	int j = 0;
	int sum = 0;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			//sum = min(height[i], height[j]) * (j - i);
			//arr.insert(sum);
			sum = max(min(height[i], height[j]) * (j - i), sum);
		}
	}
	//auto it = arr.end();
	//return *(--it);
	return sum;
}

//官方解法---两个指针一头一尾
int maxArea_OP(vector<int>& height)
{
	if (height.size() <= 1)
		return -1;
	int i = 0, j = height.size() - 1, res = 0;
	while (i < j){
		int h = min(height[i], height[j]);
		res = max(res, h * (j - i));
		if (height[i] < height[j])
			++i;
		else
			--j;
	}
	return res;
}