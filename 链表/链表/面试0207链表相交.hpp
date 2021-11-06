#include<iostream>
using namespace std;
#include <string>
#include<vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode* curA = headA;
		ListNode* curB = headB;
		int lengthA = 0;
		int lengthB = 0;
		while (curA!= nullptr)
		{
			lengthA++;
			curA = curA->next;
		}
		while (curB!= nullptr)
		{
			lengthB++;
			curB = curB->next;
		}
		curA = headA;
		curB = headB;
		if (lengthB > lengthA)
		{
			swap(lengthA, lengthB);
			swap(curA, curB);
		}

		int gap = lengthA - lengthB;
		while (gap--)
		{
			curA = curA->next;
		}

		while (curA != nullptr)
		{
			if (curA == curB)
			{
				return curA;
			}
			curA = curA->next;
			curB = curB->next;
		}
		return nullptr;
	}
};