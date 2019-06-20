#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <windows.h>
#include <mutex>

using namespace std;

///////////////////4_15/////////////////
//���ظ��ַ�����Ӵ�
void test4_15_1();
//leetcode --- 4
void test4_15_2();

///////////////////day5.21////////////////
//leetcode--6
//z�����ַ���
string convert(string s, int numRows);
//leetcode--8
//myAtoi
int myAtoi(string str);
//leetcode--9
//�ж�һ��int�͵����Ƿ��ǻ�����
bool isPalindrome(int x);

///////////////////day5.26////////////////
//leetcode---ʢ���ˮ������
int maxArea(vector<int>& height);
//�ٷ��ⷨ---����ָ��һͷһβ
int maxArea_OP(vector<int>& height);

///////////////////day5.27////////////////
//leetcode -- 14 �����ǰ׺
string longestCommonPrefix(vector<string>& strs);
//leetcode---7 ������ת
//leetcode --- 7 ������ת
int reverse(int x);
//�ⷨ�����������������
int reverse_op(int x);

//leetcode---17�绰�������ĸ���
vector<string> letterCombinations(string digits);
//leetcode---20��Ч������
bool isValid(string s);

///////////////////day5.29////////////////
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//�ϲ�������������
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

// leetcode-- �ϲ�������������
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

//leetcode 88 --- �ϲ�������������
void merge_op(vector<int>& nums1, int m, vector<int>& nums2, int n);

///////////////////day5.30////////////////
//leetcode ---986�����б�Ľ���
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B);

//����һ�仰�����һ�����ʵĳ���
int lengthOfLastWord(string s);

///////////////////day5.31////////////////
//leetcode--24 �������������еĽڵ�
//��ʽһ���ݹ�
ListNode* swapPairs_op(ListNode* head);
//��ʽ����ֱ��ѭ��
ListNode* swapPairs(ListNode* head);

//leetcode 26 -- ɾ������������ظ���
int removeDuplicates(vector<int>& nums);

///////////////////day6.1////////////////
//leetcode 27 --- �Ƴ�Ԫ��
int removeElement(vector<int>& nums, int val);

//leetcode 28 --- ʵ��strstr
int strStr(string haystack, string needle);


///////////////////day6.2////////////////
//leetcode -- 29 �������
int divide(int dividend, int divisor);

//leetcode 35 --- ��������λ��
int searchInsert(vector<int>& nums, int target);

///////////////////day6.5////////////////
//leetcode 38 -- ����
string countAndSay(int n);

//leetcode 53 --- ��������
int maxSubArray_dp(vector<int>& nums);

//leetcode 53 --- ��������
int maxSubArray(vector<int>& nums);

///////////////////day6.9////////////////
// leetcode -- 66 ��һ
vector<int> plusOne(vector<int>& digits);

//leetcode  67 -- ���������
string addBinary(string a, string b);


///////////////////day6.11////////////////
//leetcode --- 69 x��ƽ���� ʵ��sqrt����
int mySqrt(int x);
int mySqrt_op(int x);

//leetcode 70 -- ��¥��-----Ŀǰ��ʱ���ٵĽⷨ
int climbStairs(int n);

// leetcode 83. ɾ�����������е��ظ�Ԫ��
ListNode* deleteDuplicates(ListNode* head);


///////////////////day6.18///////////////
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//leetcode 100 --- ��ͬ����
//�ݹ�ķ�ʽ
bool isSameTree_OP(TreeNode* p, TreeNode* q);
//�ǵݹ�ķ�ʽ
bool isSameTree(TreeNode* p, TreeNode* q);