#include<iostream>
#include<vector>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//�ݹ�--
class Solution {
public:
	//����ֵ    ����
	bool isSameTree(TreeNode* p, TreeNode* q) {
		//��ֹ����
		if (p == nullptr && q != nullptr) return false;
		else if (p != nullptr && q == nullptr) return false;
		else if (p == nullptr && q == nullptr) return true;
		else if (p->val != q->val) return false;

		//����ݹ�����
		bool leftSide = isSameTree(p->left, q->left);
		bool rightSide = isSameTree(p->right, q->right);
		return leftSide && rightSide;
	}
};