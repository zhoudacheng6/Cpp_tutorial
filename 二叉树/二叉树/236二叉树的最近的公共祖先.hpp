#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<stack>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//�Ե����ϲ���-----�����㷨
//�����������Ȼ�Ļ����㷨-----������
class Solution {
public:
	//����ֵ  ����
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//��ֹ����
		if (root == q || root == p || root == nullptr) return root; //���ֽڵ㷵�ؽڵ�
		
		//�����߼�
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		//��ǰ�ڵ�����ҽڵ���
		if (left != nullptr && right != nullptr) return root;  //p �� q ����������������
		else if (left == nullptr && right != nullptr) return right;	//����������pq ������������pq
		else if (left != nullptr && right == nullptr) return left;
		else return nullptr;  //���ҽڵ�ķ���ֵ��Ϊ��
	}
};