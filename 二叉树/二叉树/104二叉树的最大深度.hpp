#include<iostream>
#include <vector>
#include<queue>
using namespace std;	
struct TreeNode {
	 int val;
	 TreeNode *left;  
	 TreeNode *right;     
	 TreeNode() : val(0), left(nullptr), right(nullptr) {}   
	 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  
	 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

//二叉树的深度应当是前序遍历----中、左、右
class Solution {
public:
	int result;
	void getDepth(TreeNode* node, int depth)
	{
		result = depth > result ? depth : result;  //记录最大深度为result，depth用于在各层之间遍历
		
		if (node->left == nullptr && node->right == nullptr) return ;//无子树则返回
		
		if (node->left){ //左
			depth++;   //深度+1
			getDepth(node->left, depth);
			depth--;   //回溯，深度-1
		}
		if (node->right) {	//右
			depth++;
			getDepth(node->right, depth);
			depth--;
		}
		return ;
	}
	int maxDepth(TreeNode* root) {
		result = 0;
		if (root == nullptr) return result;
		getDepth(root, 1);
		return result;
	}
};

//根节点的高度就是这颗树的最大深度，所以才可以使用后序遍历
//后序遍历----左深度  右深度  中+1
class Solution {
public:
	int maxDepth(TreeNode* root) {
		return getDepth(root);
	}
	int getDepth(TreeNode* node) {
		if (node == nullptr) return 0;
		int leftdepth = getDepth(node->left);       // 左子树的深度
		int rightdepth = getDepth(node->right);     // 右子树的深度
		int depth = 1 + max(leftdepth, rightdepth); // 中
		return depth;
	}
};