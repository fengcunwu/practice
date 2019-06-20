#include "PracticeHead.h"

//leetcode 100 -- 相同的树
//递归的方式
bool isSameTree_OP(TreeNode* p, TreeNode* q)
{
	if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
		return false;
	if (p && q)
	{
		if (p->val == q->val)
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		else
			return false;
	}
	else
		return true;
}


//非递归的方式
bool isSameTree(TreeNode* p, TreeNode* q)
{
	if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
		return false;
	else if (p == NULL && q == NULL)
		return true;
	else
	{
		stack<TreeNode*> sp;
		stack<TreeNode*> sq;
		sp.push(p);
		sq.push(q);
		TreeNode* pCur1 = NULL;
		TreeNode* pCur2 = NULL;
		while (!sq.empty() && !sq.empty())
		{
			pCur1 = sp.top();
			pCur2 = sq.top();
			if (pCur1 && pCur2)
			{
				if (pCur1->val == pCur2->val)
				{
					sp.pop();
					sq.pop();
					sp.push(pCur1->left);
					sq.push(pCur2->left);
					sp.push(pCur1->right);
					sq.push(pCur2->right);
				}
				else
					return false;
			}
			if (pCur1 == NULL || pCur2 == NULL)
				return false;
		}
		if (sq.empty() && sp.empty())
			return true;
		else
			return false;
	}

}