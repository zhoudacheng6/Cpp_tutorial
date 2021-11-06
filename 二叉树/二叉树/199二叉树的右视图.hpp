#include<iostream>
#include <vector>
#include<queue>
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
 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
		queue<TreeNode* > que;
		if (root != nullptr) que.push(root);
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0 ; i<size ; i++)
			{
				
				TreeNode* cur = que.front();
				que.pop();
				if (i == size - 1) result.push_back(cur->val);
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
		}
		return result;
    } 
};