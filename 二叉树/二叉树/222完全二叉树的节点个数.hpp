#include<iostream>
#include <vector>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


//ºóÐò±éÀú---µÝ¹é
class Solution {
public:
	int countNodes(TreeNode* root) {
		return getNodesNum(root);
	}
	int getNodesNum(TreeNode* cur) {
		if (cur == nullptr) return 0;
		int leftNum = getNodesNum(cur->left);
		int rightNum = getNodesNum(cur->right);
		int treeNum = leftNum + rightNum + 1;
		return treeNum;
	}
};

//²ãÐò±éÀú---µü´ú
class Solution {
public:
	int countNodes(TreeNode* root) {
		queue<TreeNode*> que;
		int result = 0;
		if (root != nullptr) que.push(root);
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0 ; i<size ; i++)
			{
				TreeNode* node = que.front();
				que.pop();
				result++;
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return result;
	}
};