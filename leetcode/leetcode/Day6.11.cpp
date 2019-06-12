#include "PracticeHead.h"

//leetcode --- 69 x的平方根 实现sqrt函数
int mySqrt(int x) 
{
	if (x == 0)
		return 0;
	long i = 0;
	for (i = 1; i * i < x; i++)
	{
	}

	if (i * i == x)
		return i;
	else
		return i - 1;
}

int mySqrt_op(int x)
{
	if (x == 0 || x == 1)
		return x;

	int mid = x >> 2;
	int i = 0;
	for (i = mid; i < x; i++)
	{
		if (i * i >= x)
			break;
	}

	if (i*i == x)
		return i;
	else
		return i - 1;
}

//leetcode 70 -- 爬楼梯(每次爬1或2)-----目前耗时最少的解法
int climbStairs(int n) 
{
	if (n < 4)
		return n;

	int ans = 1;
	int temp = 0;
	while (n != 0)
	{
		ans += temp;
		temp = ans - temp;
		n--;
	}
	return ans;
}

// leetcode 83. 删除排序链表中的重复元素
ListNode* deleteDuplicates(ListNode* head)
{
	ListNode* pCur = head;
	if (head == NULL || head->next == NULL)
		return head;
	while (pCur != NULL && pCur->next != NULL)
	{
		if (pCur->next->val == pCur->val)
		{
			//删除
			pCur->next = pCur->next->next;
		}
		else
			pCur = pCur->next;
	}

	return head;
}