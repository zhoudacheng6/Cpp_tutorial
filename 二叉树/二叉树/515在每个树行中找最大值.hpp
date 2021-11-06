#include<iostream>
#include <vector>
#include <queue>

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

//�������---������
class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
		//׼������(����ֵ���顢�ڵ����)
		vector<int> result;
		queue<TreeNode* > que;
		//�����ڵ���������
		if (root != nullptr) que.push(root); 
		while (!que.empty())
		{
			//��¼��ǰ��ڵ���
			int size = que.size();
			int maxNum = INT_MIN ; //��¼���ֵ
			for (int i = 0 ; i<size ; i++)
			{
				TreeNode* cur = que.front();
				que.pop();
				if (cur->val > maxNum) maxNum = cur->val;
				//����ǰ��Ľڵ���ӽڵ��������
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
			result.push_back(maxNum);
		}
		return result;
	}
};