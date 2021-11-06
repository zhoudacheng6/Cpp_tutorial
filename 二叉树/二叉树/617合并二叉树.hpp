#include<iostream>
#include<vector>

using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr) return root2;
		if (root2 == nullptr) return root1;
		return traversal(root1, root2);
	}
	//返回值     参数
	TreeNode* traversal(TreeNode* root1, TreeNode* root2)
	{
		//终止条件
		if (root1 == nullptr && root2 == nullptr) return nullptr;

		//单层逻辑
		if (root1 == nullptr)   return root2;//TreeNode* root = new TreeNode(root2->val);
		else if (root2 == nullptr)  return root1; //TreeNode* root = new TreeNode(root1->val );
		
		root1->val += root2->val;
		root1->left = traversal(root1->left, root2->left);
		root1->right = traversal(root1->right, root2->right);
		return root1;
	}
};