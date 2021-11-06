#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct  TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};


//左叶子：左节点非空，左节点的子节点为空
//前序遍历
class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		int result = 0;
		stack<TreeNode* > st;
		if (root == nullptr) return 0;
		st.push(root);
		while (!st.empty())
		{
			TreeNode* cur = st.top();
			st.pop();
			
			if (cur->left != nullptr && cur->left->left == nullptr && cur->left->right ==nullptr) {
				result += cur->left->val;
			}
			if (cur->left) st.push(cur->left);
			if (cur->right) st.push(cur->right);
		}
		return result;
	}
};