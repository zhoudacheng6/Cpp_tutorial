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
	//���鹹�캯��
	ListNode() : val(0), next(nullptr) {}  
	ListNode(int x) : val(x), next(nullptr) {} 
	ListNode(int x, ListNode* next) : val(x), next(next) {}  //ǰ��
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummyHead = new ListNode(0);	// ����һ������ͷ���
		dummyHead->next = head;	// ������ͷ���ָ��head���������������ɾ������
		ListNode* cur = dummyHead;
		while (cur->next != NULL )
		{
			if (cur->next->val == val)
			{
				ListNode* deleteNode = cur->next;	//����ר�ŵġ�ɾ���ڵ㡱ָ��ɾ�����ڵ�
				cur->next = cur->next->next;
				delete deleteNode;	//ɾ���ڵ�
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