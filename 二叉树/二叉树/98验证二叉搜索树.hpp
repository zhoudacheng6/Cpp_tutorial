#include<iostream>
#include<vector>

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

//���壺���ܵ����Ƚϵ�ǰ�ڵ��������ӽڵ�Ĵ�С��ϵ

//�ݹ�----�������
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		vec.clear(); 
		traversal(root);
		for (int i = 1; i < vec.size(); i++) {
			// ע��ҪС�ڵ��ڣ��������ﲻ������ͬԪ��
			if (vec[i] <= vec[i - 1]) return false;
		}
		return true;
	}

private:
	//����ֵ    ����
	void traversal(TreeNode* root) {
		//��ֹ����
		if (root == nullptr) return ;
		//�����߼�
		traversal(root->left);
		vec.push_back(root->val); // ������������ת��Ϊ��������
		traversal(root->right);
	}
	vector<int> vec;
};

class Solution {
public:
	long long maxVal = LONG_MIN; // ��Ϊ��̨������������int��Сֵ
	bool isValidBST(TreeNode* root) {
		if (root == NULL) return true;

		bool left = isValidBST(root->left);
		// �����������֤������Ԫ���ǲ��Ǵ�С����
		if (maxVal < root->val) maxVal = root->val;
		else return false;
		bool right = isValidBST(root->right);

		return left && right;
	}
};