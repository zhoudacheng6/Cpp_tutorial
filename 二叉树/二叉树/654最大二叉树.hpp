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

class Solution {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.size() == 0) return nullptr;
		return traversal(nums);
	}
	//返回值  参数
	TreeNode* traversal(vector<int>& nums)
	{
		//终止条件
		if (nums.size() == 0) return nullptr;

		//单层逻辑
		//找出最大值位置，并记录
		int max_val= INT_MIN; 
		int max_index = 0;   //最大值索引
		for (int i = 0 ; i<nums.size() ; i++)
		{
			if (nums[i] > max_val) {
				max_index = i;
				max_val = nums[i];
			}
		}
		TreeNode* root = new TreeNode(max_val);
		//分割数组，左侧为左子树，右侧为右子树    *注意此时是左闭右开区间
		vector<int> nums_left(nums.begin(), nums.begin() + max_index);
		vector<int> nums_right(nums.begin() + max_index + 1, nums.end());

		//对左右子树数组递归
		root->left = traversal(nums_left);
		root->right = traversal(nums_right);

		return root;
	}
};


class Solution {
private:
	// 在左闭右开区间[left, right)，构造二叉树
	TreeNode* traversal(vector<int>& nums, int left, int right) {
		if (left >= right) return nullptr;

		// 分割点下表：maxValueIndex
		int maxValueIndex = left;
		for (int i = left + 1; i < right; ++i) {
			if (nums[i] > nums[maxValueIndex]) maxValueIndex = i;
		}

		TreeNode* root = new TreeNode(nums[maxValueIndex]);

		// 左闭右开：[left, maxValueIndex)
		root->left = traversal(nums, left, maxValueIndex);

		// 左闭右开：[maxValueIndex + 1, right)
		root->right = traversal(nums, maxValueIndex + 1, right);

		return root;
	}
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return traversal(nums, 0, nums.size());
	}
};