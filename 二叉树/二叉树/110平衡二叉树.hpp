#include<iostream>
#include <vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//�ݹ�(����)
//�����ǰ����ڵ�Ϊ���ڵ�Ķ������Ѿ����Ƕ���ƽ����
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return getDepth(root) == -1 ? false : true;
	}

	//1���ݹ麯���Ĳ����ķ���ֵ
	int getDepth(TreeNode* node)
	{
		if (node == nullptr) return 0;

		//����ƽ���������нڵ��Ӧ������Ϊ����ƽ����
		int leftDepth = getDepth(node->left);
		if (leftDepth == -1) return -1;	//˵���������Ѿ����Ƕ���ƽ����
		int rightDepth = getDepth(node->right);
		if (rightDepth == -1) return -1;

		return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + max(leftDepth, rightDepth);
	}
};

//����---����
