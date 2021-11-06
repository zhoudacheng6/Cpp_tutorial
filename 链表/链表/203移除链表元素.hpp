#pragma once
#include<iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
	int val;
	ListNode* next;
	//三组构造函数
	ListNode() : val(0), next(nullptr) {}  
	ListNode(int x) : val(x), next(nullptr) {} 
	ListNode(int x, ListNode* next) : val(x), next(next) {}  //前插
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummyHead = new ListNode(0);	// 设置一个虚拟头结点
		dummyHead->next = head;	// 将虚拟头结点指向head，这样方面后面做删除操作
		ListNode* cur = dummyHead;
		while (cur->next != NULL )
		{
			if (cur->next->val == val)
			{
				ListNode* deleteNode = cur->next;	//创建专门的“删除节点”指向删除待节点
				cur->next = cur->next->next;
				delete deleteNode;	//删除节点
			}
			else
			{
				cur = cur->next;
			}
		}
		head = dummyHead->next;
		delete dummyHead;
		return head;
    }
};