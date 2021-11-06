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

//递归--
class Solution {
public:
	//返回值    参数
	bool isSameTree(TreeNode* p, TreeNode* q) {
		//终止条件
		if (p == nullptr && q != nullptr) return false;
		else if (p != nullptr && q == nullptr) return false;
		else if (p == nullptr && q == nullptr) return true;
		else if (p->val != q->val) return false;

		//单层递归条件
		bool leftSide = isSameTree(p->left, q->left);
		bool rightSide = isSameTree(p->right, q->right);
		return leftSide && rightSide;
	}
};