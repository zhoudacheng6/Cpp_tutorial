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

//前序遍历---迭代（非常不方便）下述算法错误
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		int sum;
		if (root == nullptr) return result;
		stack<pair<TreeNode*, int>> st;
		st.push(pair<TreeNode* , int>(root , root->val));
		while (!st.empty())
		{
			pair<TreeNode*, int> p = st.top();
			st.pop();
			sum += p.second;
			path.push_back(p.second);
			//如果当前节点是叶子节点
			if (p.first->left==nullptr &&p.first->right==nullptr)
			{
				if (sum==targetSum)
				{
					result.push_back(path);
				}
				path.pop_back();
				sum -= p.second;
			}
			//非叶子节点
			if (p.first->right != nullptr) st.push(pair<TreeNode*, int>(p.first->right, p.first->right->val));
			if (p.first->left != nullptr) st.push(pair<TreeNode*, int>(p.first->left, p.first->left->val));
			
		}
		return result;
	}

private:
	vector<vector<int>> result;
	vector<int> path;
};

//前序遍历---递归
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		result.clear();
		path.clear();
		if (root == nullptr) return result;
		path.push_back(root->val);
		traversal(root, targetSum - root->val);
		return result;
	}

private:
	//返回值 参数
	void traversal(TreeNode* cur, int count)
	{
		//终止条件---叶子节点
		// 遇到了叶子节点且找到了和为sum的路径
		if (!cur->left && !cur->right && count == 0) { 
			result.push_back(path);
			return;
		}
		// 遇到叶子节点而没有找到合适的边，直接返回
		if (!cur->left && !cur->right) return; 

		//单层逻辑
		if (cur->left){
			path.push_back(cur->left->val);
			count -= cur->left->val;
			traversal(cur->left, count);
			count += cur->left->val;   //*回溯
			path.pop_back();
		}
		if (cur->right) { // 右 （空节点不遍历）
			path.push_back(cur->right->val);
			count -= cur->right->val;
			traversal(cur->right, count);   // 递归
			count += cur->right->val;       // 回溯
			path.pop_back();                // 回溯
		}
		return;
	}
	vector<vector<int>> result;
	vector<int> path;
};