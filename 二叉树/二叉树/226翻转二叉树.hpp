#include<iostream>
#include <vector>
#include<queue>
#include<stack>
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

//前序遍历可，后序遍历可
//层序遍历可

//递归
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr) return root;
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

//迭代--深度优先
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		stack<TreeNode*> st;
		if (root!=nullptr)	st.push(root);
		while (!st.empty())
		{
			TreeNode* node = st.top();
			if (node!= nullptr)
			{
				st.pop();
				if (node->right) st.push(node->right);  // 右
				if (node->left) st.push(node->left);    // 左
				st.push(node);                          // 中
				st.push(nullptr);
			}
			else
			{
				st.pop();
				node = st.top();
				st.pop();
				swap(node->left, node->right);
			}
		}
		return root;
	}
};

//迭代--广度优先
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != nullptr) que.push(root);
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0 ; i<size ; i++)
			{
				TreeNode* node = que.front();
				que.pop();
				swap(node->left, node->right);
				if (node->left) que.push(node->left);    // 左
				if (node->right) que.push(node->right);  // 右

			}
		}
		return root;
	}
};