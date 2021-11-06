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

//后序遍历-递归-回溯
//1、参数   返回值
//2、终止条件
//3、单层递归逻辑
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
		return compare(root->left, root->right);
	}
	//确定递归函数的参数和返回值
	bool compare(TreeNode* left, TreeNode* right)
	{
		//终止条件
		//左节点为空  右节点不为空 不对称，return false 
		if (left == nullptr && right != nullptr) return false;
		//左不为空，右为空，不对称 return false
		else if (left != nullptr && right == nullptr) return false;
		//左右都为空，对称，返回true
		else if (left == nullptr && right == nullptr) return true;
		//左右都不为空，比较节点数值，不相同就return false
		else if (left->val != right->val) return false;

		//单层递归逻辑
		//比较二叉树外侧是否对称：传入的是左节点的左孩子，右节点的右孩子
		bool outside = compare(left->left, right->right);
		//比较内侧是否对称：传入左节点的右孩子，右节点的左孩子
		bool inside = compare(left->right, right->left);
		//如果左右都对称就返回true ，有一侧不对称就返回false 
		bool isSame = outside && inside;

		//返回值
		return isSame;
	}
};


