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


//后序遍历----迭代用队列
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		queue<TreeNode*> que;
		int depth = 0;
		que.push(root);
		while ( !que.empty() )
		{
			int size = que.size();
			depth++;
			for (int i = 0 ; i<size ; i++)
			{
				TreeNode* cur = que.front();
				que.pop();
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
				if (!cur->left && !cur->right) return depth;
			}
		}
		return depth;
	}
};

