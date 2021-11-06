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

//ǰ������ɣ����������
//���������

//�ݹ�
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

//����--�������
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
				if (node->right) st.push(node->right);  // ��
				if (node->left) st.push(node->left);    // ��
				st.push(node);                          // ��
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

//����--�������
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
				if (node->left) que.push(node->left);    // ��
				if (node->right) que.push(node->right);  // ��

			}
		}
		return root;
	}
};