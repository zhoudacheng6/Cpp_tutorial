#include<iostream>
#include<vector>
#include <stack>
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

//�������-�ݹ�-����
//1������   ����ֵ
//2����ֹ����
//3������ݹ��߼�
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
		return compare(root->left, root->right);
	}
	//ȷ���ݹ麯���Ĳ����ͷ���ֵ
	bool compare(TreeNode* left, TreeNode* right)
	{
		//��ֹ����
		//��ڵ�Ϊ��  �ҽڵ㲻Ϊ�� ���Գƣ�return false 
		if (left == nullptr && right != nullptr) return false;
		//��Ϊ�գ���Ϊ�գ����Գ� return false
		else if (left != nullptr && right == nullptr) return false;
		//���Ҷ�Ϊ�գ��Գƣ�����true
		else if (left == nullptr && right == nullptr) return true;
		//���Ҷ���Ϊ�գ��ȽϽڵ���ֵ������ͬ��return false
		else if (left->val != right->val) return false;

		//����ݹ��߼�
		//�Ƚ϶���������Ƿ�Գƣ����������ڵ�����ӣ��ҽڵ���Һ���
		bool outside = compare(left->left, right->right);
		//�Ƚ��ڲ��Ƿ�Գƣ�������ڵ���Һ��ӣ��ҽڵ������
		bool inside = compare(left->right, right->left);
		//������Ҷ��Գƾͷ���true ����һ�಻�Գƾͷ���false 
		bool isSame = outside && inside;

		//����ֵ
		return isSame;
	}
};


