#include<iostream>
#include <vector>
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
//迭代方式
//left root right
//弊端：无法同时解决访问节点(遍历节点)和处理节点(将元素放进结果集中)
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;  //创建<树>栈
		vector<int> result;
		TreeNode* cur = root;
		while (cur != nullptr || !st.empty())   //当前节点非空且栈中非空
		{
			//1、访问左子树最底层
			if (cur != nullptr)
			{
				st.push(cur);
				cur = cur->left;
			}
			else
			{
				//2、记录中、右
				cur = st.top();
				st.pop();		//保证栈中已记录值被推出
				result.push_back(cur->val);    //中
				cur = cur->right;          //右
			}
		}
		return result;
	}
};


class Solution
{
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> st;
		if (root != nullptr)
		{
			st.push(root);
		}
		while (!st.empty())
		{
			TreeNode* node = st.top();
			if (node != nullptr)   //栈中节点非空 
			{
				st.pop(); //将该节点弹出，避免重复操作
				if (node->right) st.push(node->right);  //右节点入栈
				st.push(node);		//中节点入栈
				st.push(nullptr);	//中节点访问过，但是还是没有处理，加入空节点作为标记
				if (node->left) st.push(node->left);		//左节点入栈
			}
			else //栈中节点为nullptr
			{
				st.pop();  
				node = st.top();
				st.pop();
				result.push_back(node->val);  //加入到结果集
			}
		}
	}
};

