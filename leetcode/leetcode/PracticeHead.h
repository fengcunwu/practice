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
//无重复字符的最长子串
void test4_15_1();
//leetcode --- 4
void test4_15_2();

///////////////////day5.21////////////////
//leetcode--6
//z字形字符串
string convert(string s, int numRows);
//leetcode--8
//myAtoi
int myAtoi(string str);
//leetcode--9
//判断一个int型的数是否是回文数
bool isPalindrome(int x);

///////////////////day5.26////////////////
//leetcode---盛最多水的容器
int maxArea(vector<int>& height);
//官方解法---两个指针一头一尾
int maxArea_OP(vector<int>& height);

///////////////////day5.27////////////////
//leetcode -- 14 最长公共前缀
string longestCommonPrefix(vector<string>& strs);
//leetcode---7 整数翻转
//leetcode --- 7 整数翻转
int reverse(int x);
//解法二，处理了溢出问题
int reverse_op(int x);

//leetcode---17电话号码的字母组合
vector<string> letterCombinations(string digits);
//leetcode---20有效的括号
bool isValid(string s);

///////////////////day5.29////////////////
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//合并两个有序链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

// leetcode-- 合并两个有序数组
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

//leetcode 88 --- 合并两个有序数组
void merge_op(vector<int>& nums1, int m, vector<int>& nums2, int n);

///////////////////day5.30////////////////
//leetcode ---986区间列表的交集
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B);

//返回一句话的最后一个单词的长度
int lengthOfLastWord(string s);

///////////////////day5.31////////////////
//leetcode--24 两两交换链表中的节点
//方式一：递归
ListNode* swapPairs_op(ListNode* head);
//方式二：直接循环
ListNode* swapPairs(ListNode* head);

//leetcode 26 -- 删除排序数组的重复项
int removeDuplicates(vector<int>& nums);

///////////////////day6.1////////////////
//leetcode 27 --- 移除元素
int removeElement(vector<int>& nums, int val);

//leetcode 28 --- 实现strstr
int strStr(string haystack, string needle);


///////////////////day6.2////////////////
//leetcode -- 29 两数相除
int divide(int dividend, int divisor);

//leetcode 35 --- 搜索插入位置
int searchInsert(vector<int>& nums, int target);

///////////////////day6.5////////////////
//leetcode 38 -- 报数
string countAndSay(int n);

//leetcode 53 --- 最大子序和
int maxSubArray_dp(vector<int>& nums);

//leetcode 53 --- 最大子序和
int maxSubArray(vector<int>& nums);

///////////////////day6.9////////////////
// leetcode -- 66 加一
vector<int> plusOne(vector<int>& digits);

//leetcode  67 -- 二进制求和
string addBinary(string a, string b);


///////////////////day6.11////////////////
//leetcode --- 69 x的平方根 实现sqrt函数
int mySqrt(int x);
int mySqrt_op(int x);

//leetcode 70 -- 爬楼梯-----目前耗时最少的解法
int climbStairs(int n);

// leetcode 83. 删除排序链表中的重复元素
ListNode* deleteDuplicates(ListNode* head);


///////////////////day6.18///////////////
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//leetcode 100 --- 相同的树
//递归的方式
bool isSameTree_OP(TreeNode* p, TreeNode* q);
//非递归的方式
bool isSameTree(TreeNode* p, TreeNode* q);