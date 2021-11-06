#include<iostream>
#include <vector>
#include<stack>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//递归方式
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		traversal(root, result);
		return result;
	}
	void traversal(TreeNode* cur, vector<int>& result)
	{
		if (cur == nullptr)  //2、终止条件
		{
			return ;
		}
		result.push_back(cur->val);	//中
		traversal(cur->left , result);		//左
		traversal(cur->right, result);	//右
	}
};

//迭代方式
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		if (root == nullptr)
		{
			return result;
		}
		st.push(root);
		while (!st.empty())
		{
			//1、记录栈头元素
			TreeNode* node = st.top();
			st.pop();
			result.push_back(node->val);

			//2、
			if (node->right) {
				st.push(node->right);   //右子树先推入栈
			}
			if (node->left){
				st.push(node->left);		//左子树后推入栈
			}
		}
		return result;
	}
};