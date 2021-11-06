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

//ǰ�����---�������ǳ������㣩�����㷨����
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		int sum;
		if (root == nullptr) return result;
		stack<pair<TreeNode*, int>> st;
		st.push(pair<TreeNode* , int>(root , root->val));
		while (!st.empty())
		{
			pair<TreeNode*, int> p = st.top();
			st.pop();
			sum += p.second;
			path.push_back(p.second);
			//�����ǰ�ڵ���Ҷ�ӽڵ�
			if (p.first->left==nullptr &&p.first->right==nullptr)
			{
				if (sum==targetSum)
				{
					result.push_back(path);
				}
				path.pop_back();
				sum -= p.second;
			}
			//��Ҷ�ӽڵ�
			if (p.first->right != nullptr) st.push(pair<TreeNode*, int>(p.first->right, p.first->right->val));
			if (p.first->left != nullptr) st.push(pair<TreeNode*, int>(p.first->left, p.first->left->val));
			
		}
		return result;
	}

private:
	vector<vector<int>> result;
	vector<int> path;
};

//ǰ�����---�ݹ�
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		result.clear();
		path.clear();
		if (root == nullptr) return result;
		path.push_back(root->val);
		traversal(root, targetSum - root->val);
		return result;
	}

private:
	//����ֵ ����
	void traversal(TreeNode* cur, int count)
	{
		//��ֹ����---Ҷ�ӽڵ�
		// ������Ҷ�ӽڵ����ҵ��˺�Ϊsum��·��
		if (!cur->left && !cur->right && count == 0) { 
			result.push_back(path);
			return;
		}
		// ����Ҷ�ӽڵ��û���ҵ����ʵıߣ�ֱ�ӷ���
		if (!cur->left && !cur->right) return; 

		//�����߼�
		if (cur->left){
			path.push_back(cur->left->val);
			count -= cur->left->val;
			traversal(cur->left, count);
			count += cur->left->val;   //*����
			path.pop_back();
		}
		if (cur->right) { // �� ���սڵ㲻������
			path.push_back(cur->right->val);
			count -= cur->right->val;
			traversal(cur->right, count);   // �ݹ�
			count += cur->right->val;       // ����
			path.pop_back();                // ����
		}
		return;
	}
	vector<vector<int>> result;
	vector<int> path;
};