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

//层序遍历---迭代法
class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
		//准备工作(返回值数组、节点队列)
		vector<int> result;
		queue<TreeNode* > que;
		//将根节点存入队列中
		if (root != nullptr) que.push(root); 
		while (!que.empty())
		{
			//记录当前层节点数
			int size = que.size();
			int maxNum = INT_MIN ; //记录最大值
			for (int i = 0 ; i<size ; i++)
			{
				TreeNode* cur = que.front();
				que.pop();
				if (cur->val > maxNum) maxNum = cur->val;
				//将当前层的节点的子节点推入队列
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
			result.push_back(maxNum);
		}
		return result;
	}
};