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
	//����ֵ   ����
	bool traversal(TreeNode* cur, int count)
	{
		//��ֹ����
		//success
		if (!cur->left && !cur->right && count == 0) return true;
		//defeat
		if (!cur->left && !cur->right) return false;

		//����ݹ��߼�
		//����Ҷ�ӽڵ㷵��true �� ��ֱ�ӷ���true
		if (cur->left) if (traversal(cur->left, count - cur->left->val)) return true;
		if (cur->right) 	if (traversal(cur->right, count - cur->right->val)) return true;
		//����Ҷ�ӽڵ㷵��false �� ��ֱ�ӷ���false
		return false;
	}
};


//����
class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr) return false;
		// ��ʱջ��Ҫ�ŵ���pair<�ڵ�ָ�룬·����ֵ>
		stack<pair<TreeNode*, int>> st;
		st.push(pair<TreeNode*, int>(root, root->val));
		while (!st.empty()) {
			pair<TreeNode*, int> node = st.top();
			st.pop();
			// ����ýڵ���Ҷ�ӽڵ���
			//ͬʱ�ýڵ��·����ֵ����sum����ô�ͷ���true
			if (!node.first->left && !node.first->right && sum == node.second) return true;

			// �ҽڵ㣬ѹ��ȥһ���ڵ��ʱ�򣬽��ýڵ��·����ֵҲ��¼����
			if (node.first->right) {
				st.push(pair<TreeNode*, int>(node.first->right, node.second + node.first->right->val));
			}

			// ��ڵ㣬ѹ��ȥһ���ڵ��ʱ�򣬽��ýڵ��·����ֵҲ��¼����
			if (node.first->left) {
				st.push(pair<TreeNode*, int>(node.first->left, node.second + node.first->left->val));
			}
		}
		return false;
	}
};