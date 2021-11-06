#include<iostream>
#include <vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//递归(回溯)
//如果当前传入节点为根节点的二叉树已经不是二叉平衡树
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return getDepth(root) == -1 ? false : true;
	}

	//1、递归函数的参数的返回值
	int getDepth(TreeNode* node)
	{
		if (node == nullptr) return 0;

		//二叉平衡树下所有节点对应的树都为二叉平衡树
		int leftDepth = getDepth(node->left);
		if (leftDepth == -1) return -1;	//说明左子树已经不是二叉平衡树
		int rightDepth = getDepth(node->right);
		if (rightDepth == -1) return -1;

		return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + max(leftDepth, rightDepth);
	}
};

//迭代---不佳
