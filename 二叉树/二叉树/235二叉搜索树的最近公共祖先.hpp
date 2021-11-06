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

//�ݹ�----�������----����
//������������ p.val <��������
class Solution {
public:
	//����ֵ����ǰroot�Ƿ���pq֮��       ���������ڵ㣬��Ѱ�ҵ�p��q�ӽڵ�
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//��ֹ����
		// root Ϊ nullptr ʱ
		if (root == nullptr) return root;

		//�����߼�
		if (root->val > p->val && root->val > q->val)
		{
			TreeNode* left = lowestCommonAncestor(root->left, p, q);
			if (left != nullptr){
				return left;
			}
		}
		else if (root->val<p->val && root->val > q->val)
		{
			TreeNode* right = lowestCommonAncestor(root->left, p, q);
			if (right != nullptr) {
				return right;
			}
		}
		else
		{
			return root;
		}
	}
};