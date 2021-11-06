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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummyhead = new ListNode(0);
		dummyhead->next = head;
		ListNode* right = dummyhead;
		ListNode* left = dummyhead;
		while (n--)
		{
			right = right->next;
		}
		while (right->next != nullptr)
		{
			right = right->next;
			left = left->next;
		}
		left->next = left->next->next;
		return dummyhead->next;
	}
};
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* slow = dummyHead;
		ListNode* fast = dummyHead;
		while (n-- && fast != nullptr) {
			fast = fast->next;
		}
		fast = fast->next; // fast����ǰ��һ������Ϊ��Ҫ��slowָ��ɾ���ڵ����һ���ڵ�
		while (fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return dummyHead->next;
	}
};