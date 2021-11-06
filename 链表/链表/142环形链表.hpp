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
	ListNode* detectCycle(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				ListNode* index1 = fast;
				ListNode* index2 = head;
				while (index1 != index2)
				{
					index1 = index1->next;
					index2 = index2->next;
				}
				return index2; // ���ػ������
			}
		}
		return nullptr;
	}
};