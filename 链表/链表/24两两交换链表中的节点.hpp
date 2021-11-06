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
    ListNode* swapPairs(ListNode* head) {
		ListNode* dummyhead = new ListNode(0);
		dummyhead->next = head;
		ListNode* cur = dummyhead;
		while (cur->next!= nullptr && cur->next->next != nullptr)
		{
			ListNode* temp = cur->next;
			
			cur->next = cur->next->next;  //将头结点的值赋予dummyhead
			temp->next = cur->next->next;
			cur->next->next = temp;
			cur = cur->next->next;
		}
		return dummyhead->next;
    }
};