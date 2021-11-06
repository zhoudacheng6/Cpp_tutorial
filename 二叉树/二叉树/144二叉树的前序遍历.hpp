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

//�ݹ鷽ʽ
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		traversal(root, result);
		return result;
	}
	void traversal(TreeNode* cur, vector<int>& result)
	{
		if (cur == nullptr)  //2����ֹ����
		{
			return ;
		}
		result.push_back(cur->val);	//��
		traversal(cur->left , result);		//��
		traversal(cur->right, result);	//��
	}
};

//������ʽ
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
			//1����¼ջͷԪ��
			TreeNode* node = st.top();
			st.pop();
			result.push_back(node->val);

			//2��
			if (node->right) {
				st.push(node->right);   //������������ջ
			}
			if (node->left){
				st.push(node->left);		//������������ջ
			}
		}
		return result;
	}
};