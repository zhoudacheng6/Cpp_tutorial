#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct  TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};


//≤„–Ú±È¿˙
class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> que;
		if (root == nullptr) return 0;
		que.push(root);
		int result = 0;
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0 ;i<size ; i++)
			{
				TreeNode* cur = que.front();
				que.pop();
				if (cur->right) que.push(cur->right);
				if (cur->left) que.push(cur->left);
				
				if (i==0)  result = cur->val;
			}
		}
		return result;
	}
};


//µ›πÈ
class Solution {
public:
	int maxLen = INT_MIN;
	int maxleftValue;
	void traversal(TreeNode* root, int leftLen) {
		if (root->left == NULL && root->right == NULL) {
			if (leftLen > maxLen) {
				maxLen = leftLen;
				maxleftValue = root->val;
			}
			return;
		}
		if (root->left) {
			leftLen++;
			traversal(root->left, leftLen);
			leftLen--; // ªÿÀ›
		}
		if (root->right) {
			leftLen++;
			traversal(root->right, leftLen);
			leftLen--; // ªÿÀ›
		}
		return;
	}
	int findBottomLeftValue(TreeNode* root) {
		traversal(root, 0);
		return maxleftValue;
	}
};