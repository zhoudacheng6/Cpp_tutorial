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

//�ݹ�
class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
				return traversal(inorder, postorder);
	}
	//����ֵ  ����
	TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
		//��ֹ����
		if (postorder.size() == 0) return nullptr;

		//�����߼�
		//ȡ������������һ��Ԫ�أ�����ǰ���ڵ㲢�����ø��ڵ�
		int root_val = postorder[postorder.size() - 1];
		TreeNode* root = new TreeNode(root_val);

		//���ø��ڵ��ҵ�����������и��
		int index = 0;
		while (inorder[index]!=root_val)
		{
			index++;
		}

		// �и��������飬�õ� ���������������������
		vector<int> inorder_left(inorder.begin(), inorder.begin()+index);
		vector<int> inorder_right(inorder.begin() + index+1, inorder.end());
		// �и�������飬�õ� ����������ͺ���������
		// postorder ����ĩβԪ��
		postorder.resize(postorder.size() - 1);
		vector<int> postorder_left(postorder.begin(), postorder.begin()+inorder_left.size());
		vector<int> postorder_right(postorder.begin()+inorder_left.size() , postorder.end());

		root->left = traversal(inorder_left, postorder_left);
		root->right = traversal(inorder_right, postorder_right);

		return root;
	}
};