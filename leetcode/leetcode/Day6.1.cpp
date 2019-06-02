#include "PracticeHead.h"

//leetcode 27 --- ÒÆ³ıÔªËØ
int removeElement(vector<int>& nums, int val) 
{
	vector<int>::iterator it = nums.begin();
	while (it != nums.end())
	{
		if (*it == val)
			it = nums.erase(it);
		else
			++it;
	}
	return nums.size();
}

//leetcode 28 --- ÊµÏÖstrstr
int strStr(string haystack, string needle) 
{
	if (needle.size() == 0)
		return 0;
	if (haystack.size() == 0)
		return -1;
	//return haystack.find(needle);
	int i = 0, j = 0;
	int result = 0;
	while (i < haystack.size() && j < needle.size())
	{
		if (haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		else
		{
			result++;
			j = 0;
			i = result;
		}
	}
	if (j == needle.size())
		return result;
	else
		return -1;
}