#include "PracticeHead.h"

//无重复字符的最长子串----模拟滑动窗口
void test4_15_1()
{
	string s;
	while (getline(cin, s))
	{
		set<char> str_set;
		int i = 0, j = 0;
		int maxcount = 0;
		while (i < s.size() && j < s.size())
		{
			if (!str_set.count(s[j]))
			{
				str_set.insert(s[j++]);
				maxcount = max(maxcount, str_set.size());
			}
			else
				str_set.erase(s[i++]);
		}
		cout << maxcount << endl;
	}
}

//leetcode --- 4 寻找两个有序数组的中位数
void test4_15_2()
{
	vector<int> nums1 = { 1, 3 };
	vector<int> nums2 = { 2, 4 };
	vector<int> nums(nums1.size() + nums2.size());
	merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());
	double sum = 0;
	if (nums.size() % 2 == 1)
		cout << nums[nums.size() / 2];
	else
	{
		sum = (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2.0;
		cout << sum << endl;
	}
}