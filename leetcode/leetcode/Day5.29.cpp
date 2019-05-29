#include "PracticeHead.h"

//合并两个有序链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	ListNode* h1 = l1;
	ListNode* h2 = l2;
	ListNode* pNewHead = NULL;
	ListNode* pTail = NULL;
	if (h1->val < h2->val)
	{
		pNewHead = h1;
		h1 = h1->next;
	}
	else
	{
		pNewHead = h2;
		h2 = h2->next;
	}

	pTail = pNewHead;
	while (h1 && h2)
	{
		if (h1->val < h2->val)
		{
			pTail->next = h1;
			h1 = h1->next;
		}
		else
		{
			pTail->next = h2;
			h2 = h2->next;
		}
		pTail = pTail->next;
	}
	if (h1)
		pTail->next = h1;
	if (h2)
		pTail->next = h2;

	return pNewHead;
}


// leetcode-- 合并两个有序数组
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	vector<int> result;
	int len1 = 0;
	int len2 = 0;
	while (len1 < m && len2 < n)
	{
		if (nums1[len1] < nums2[len2])
		{
			result.push_back(nums1[len1]);
			++len1;
		}
		else
		{
			result.push_back(nums1[len2]);
			++len2;
		}
	}
	while (len1 < m)
	{
		result.push_back(nums1[len1]);
		++len1;
	}

	while (len2 < n)
	{
		result.push_back(nums1[len2]);
		++len2;
	}

	for (auto & e : result)
		cout << e << ' ';
	cout << endl;
	//reverse(result.begin(), result.end());
}

//leetcode 88 --- 合并两个有序数组
void merge_op(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	for (int i = m; i < nums1.size(); i++)
	{
		nums1[i] = nums2[i - m];
	}

	sort(nums1.begin(), nums1.end());
	for (auto& e : nums1)
		cout << e << ' ';
	cout << endl;
}