#include<iostream>
#include <vector>
#include<queue>
using namespace std;	
struct TreeNode {
	 int val;
	 TreeNode *left;  
	 TreeNode *right;     
	 TreeNode() : val(0), left(nullptr), right(nullptr) {}   
	 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  
	 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

//�����������Ӧ����ǰ�����----�С�����
class Solution {
public:
	int result;
	void getDepth(TreeNode* node, int depth)
	{
		result = depth > result ? depth : result;  //��¼������Ϊresult��depth�����ڸ���֮�����
		
		if (node->left == nullptr && node->right == nullptr) return ;//�������򷵻�
		
		if (node->left){ //��
			depth++;   //���+1
			getDepth(node->left, depth);
			depth--;   //���ݣ����-1
		}
		if (node->right) {	//��
			depth++;
			getDepth(node->right, depth);
			depth--;
		}
		return ;
	}
	int maxDepth(TreeNode* root) {
		result = 0;
		if (root == nullptr) return result;
		getDepth(root, 1);
		return result;
	}
};

//���ڵ�ĸ߶Ⱦ���������������ȣ����Բſ���ʹ�ú������
//�������----�����  �����  ��+1
class Solution {
public:
	int maxDepth(TreeNode* root) {
		return getDepth(root);
	}
	int getDepth(TreeNode* node) {
		if (node == nullptr) return 0;
		int leftdepth = getDepth(node->left);       // �����������
		int rightdepth = getDepth(node->right);     // �����������
		int depth = 1 + max(leftdepth, rightdepth); // ��
		return depth;
	}
};