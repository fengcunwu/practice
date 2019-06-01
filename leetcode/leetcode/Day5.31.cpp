#include "PracticeHead.h"

//leetcode--24 �������������еĽڵ�
//��ʽһ���ݹ�
ListNode* swapPairs_op(ListNode* head) 
{
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode *p1 = head;
	ListNode *p2 = p1->next;

	p1->next = swapPairs(p2->next);
	p2->next = p1;

	return p2;
}
//��ʽ����ֱ��ѭ��
ListNode* swapPairs(ListNode* head) 
{
	if (head == nullptr || head->next == nullptr) {
		return head;
	}

	ListNode tempNode(-1);
	tempNode.next = head;
	ListNode*p = &tempNode;
	ListNode *p1 = nullptr;
	ListNode *p2 = nullptr;
	while (p->next && p->next->next){
		p1 = p->next;
		p2 = p1->next;

		p1->next = p2->next;
		p2->next = p1;
		p->next = p2;

		p = p1;
	}
	return tempNode.next;
}

//leetcode 26 -- ɾ������������ظ���
int removeDuplicates(vector<int>& nums) 
{
	if (nums.size() == 0)
		return 0;
	int i = 0;
	for (int j = 0; j < nums.size(); j++)
	{
		if (nums[i] != nums[j])
			i++;
		nums[i] = nums[j];
	}
	return i + 1;
}