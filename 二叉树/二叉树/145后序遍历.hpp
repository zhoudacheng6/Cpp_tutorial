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

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		traversal(root, result);
		return result;
	}
	void traversal(TreeNode* cur, vector<int>& result)
	{
		if (cur == nullptr)  //2����ֹ����
		{
			return;
		}
		traversal(cur->left, result);		//��
		traversal(cur->right, result);	//��
		result.push_back(cur->val);	//��

	}
};



//������ʽ
//left root right
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		if (root == NULL) return result;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			result.push_back(node->val);
			if (node->left) st.push(node->left); // �����ǰ������������һ����ջ˳�� ���սڵ㲻��ջ��
			if (node->right) st.push(node->right); // �սڵ㲻��ջ
		}
		reverse(result.begin(), result.end()); // �������ת֮����������е�˳����
		return result;
	}
};