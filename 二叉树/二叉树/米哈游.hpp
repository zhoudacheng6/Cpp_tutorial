#include<iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int getNodeNum(TreeNode* root)
	{
		stack<TreeNode*> st;
		int result = 1;
		if (root == nullptr) return result;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();                       // 中
			st.pop();
			bool r = isBalanced(node);
			if (r)
			{
				return result;
			}
			else
			{
				if (node->right) st.push(node->right);           // 右（空节点不入栈）
				if (node->left) st.push(node->left);             // 左（空节点不入栈）
			}
			result++;
		}
		return result;
	}
	// 返回以该节点为根节点的二叉树的高度，如果不是二叉搜索树了则返回-1
	int getDepth(TreeNode* node) {
		if (node == NULL) {
			return 0;
		}
		int leftDepth = getDepth(node->left);
		if (leftDepth == -1) return -1; // 说明左子树已经不是二叉平衡树
		int rightDepth = getDepth(node->right);
		if (rightDepth == -1) return -1; // 说明右子树已经不是二叉平衡树
		return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + max(leftDepth, rightDepth);
	}
	bool isBalanced(TreeNode* root) {
		return getDepth(root) == -1 ? false : true;
	}
};

