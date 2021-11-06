#include<iostream>
using namespace std;
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
    ListNode* reverseList(ListNode* head) {
		ListNode* cur = head;
		ListNode* temp = head;
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		else
		{
			head = head->next;
		}
		temp->next = nullptr;
		while (head != nullptr)
		{
			temp = head;
			head = head->next;
			temp->next = cur;
			cur = temp;
		}
		return temp;
	}
};