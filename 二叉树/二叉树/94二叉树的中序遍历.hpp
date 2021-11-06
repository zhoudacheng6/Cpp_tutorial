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
//������ʽ
//left root right
//�׶ˣ��޷�ͬʱ������ʽڵ�(�����ڵ�)�ʹ���ڵ�(��Ԫ�طŽ��������)
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;  //����<��>ջ
		vector<int> result;
		TreeNode* cur = root;
		while (cur != nullptr || !st.empty())   //��ǰ�ڵ�ǿ���ջ�зǿ�
		{
			//1��������������ײ�
			if (cur != nullptr)
			{
				st.push(cur);
				cur = cur->left;
			}
			else
			{
				//2����¼�С���
				cur = st.top();
				st.pop();		//��֤ջ���Ѽ�¼ֵ���Ƴ�
				result.push_back(cur->val);    //��
				cur = cur->right;          //��
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
			if (node != nullptr)   //ջ�нڵ�ǿ� 
			{
				st.pop(); //���ýڵ㵯���������ظ�����
				if (node->right) st.push(node->right);  //�ҽڵ���ջ
				st.push(node);		//�нڵ���ջ
				st.push(nullptr);	//�нڵ���ʹ������ǻ���û�д�������սڵ���Ϊ���
				if (node->left) st.push(node->left);		//��ڵ���ջ
			}
			else //ջ�нڵ�Ϊnullptr
			{
				st.pop();  
				node = st.top();
				st.pop();
				result.push_back(node->val);  //���뵽�����
			}
		}
	}
};

