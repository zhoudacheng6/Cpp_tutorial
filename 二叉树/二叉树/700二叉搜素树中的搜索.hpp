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

//�ݹ�----ǰ�����
class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == nullptr || root->val == val) return root;
		if (root->val > val) return searchBST(root->left, val);
		if (root->val < val) return searchBST(root->right, val);
		return nullptr;
	}
};

//����----�������
class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		while (root != NULL) {
			if (root->val > val) root = root->left;
			else if (root->val < val) root = root->right;
			else return root;
		}
		return NULL;
	}
};