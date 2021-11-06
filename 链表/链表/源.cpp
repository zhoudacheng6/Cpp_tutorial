#include "206·´×ªÁ´±í.hpp"
using namespace std;
int main()
{
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2, a);
	ListNode* c = new ListNode(3, b);
	ListNode* d = new ListNode(4, c);
	ListNode* e = new ListNode(5, d);

	Solution s;
	ListNode* ans = s.reverseList(e);
	system("pause");
	return 0;
}