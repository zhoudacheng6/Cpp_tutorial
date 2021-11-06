#include<iostream>
#include<vector>
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


class Solution {
private:
	vector<int> vec;
	void traversal(TreeNode* root) {
		if (root == NULL) return;
		traversal(root->left);
		vec.push_back(root->val); // 将二叉搜索树转换为有序数组
		traversal(root->right);
	}
public:
	int getMinimumDifference(TreeNode* root) {
		vec.clear();
		traversal(root);
		if (vec.size() < 2) return 0;
		int result = INT_MAX;
		for (int i = 1; i < vec.size(); i++) { // 统计有序数组的最小差值
			result = min(result, vec[i] - vec[i - 1]);
		}
		return result;
	}
};


//中序遍历----迭代
//***二叉线索树的中序遍历即从小到大的遍历顺序
class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
		stack<TreeNode* > st;
		int result = INT_MAX;
		TreeNode* cur = root;
		TreeNode* pre = nullptr;
		while (!st.empty() || cur!=nullptr)
		{
			if (cur!=nullptr)
			{
				st.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = st.top();
				st.pop();

				if (pre!=nullptr)
				{
					result = min(result, cur->val - pre->val);
				}

				pre = cur;
				cur = cur->right;
			}
		}
		return result;
	}
};