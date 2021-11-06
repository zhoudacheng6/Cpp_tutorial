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
		fast = fast->next; // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
		while (fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return dummyHead->next;
	}
};