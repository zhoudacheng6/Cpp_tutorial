#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct  TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) return false;
		return traversal(root, targetSum - root->val);
	}
	//返回值   参数
	bool traversal(TreeNode* cur, int count)
	{
		//终止条件
		//success
		if (!cur->left && !cur->right && count == 0) return true;
		//defeat
		if (!cur->left && !cur->right) return false;

		//单层递归逻辑
		//遇到叶子节点返回true ， 则直接返回true
		if (cur->left) if (traversal(cur->left, count - cur->left->val)) return true;
		if (cur->right) 	if (traversal(cur->right, count - cur->right->val)) return true;
		//遇到叶子节点返回false ， 则直接返回false
		return false;
	}
};


//迭代
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr) return false;
		// 此时栈里要放的是pair<节点指针，路径数值>
		stack<pair<TreeNode*, int>> st;
		st.push(pair<TreeNode*, int>(root, root->val));
		while (!st.empty()) {
			pair<TreeNode*, int> node = st.top();
			st.pop();
			// 如果该节点是叶子节点了
			//同时该节点的路径数值等于sum，那么就返回true
			if (!node.first->left && !node.first->right && sum == node.second) return true;

			// 右节点，压进去一个节点的时候，将该节点的路径数值也记录下来
			if (node.first->right) {
				st.push(pair<TreeNode*, int>(node.first->right, node.second + node.first->right->val));
			}

			// 左节点，压进去一个节点的时候，将该节点的路径数值也记录下来
			if (node.first->left) {
				st.push(pair<TreeNode*, int>(node.first->left, node.second + node.first->left->val));
			}
		}
		return false;
	}
};