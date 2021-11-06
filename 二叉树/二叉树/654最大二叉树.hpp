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
	//����ֵ  ����
	TreeNode* traversal(vector<int>& nums)
	{
		//��ֹ����
		if (nums.size() == 0) return nullptr;

		//�����߼�
		//�ҳ����ֵλ�ã�����¼
		int max_val= INT_MIN; 
		int max_index = 0;   //���ֵ����
		for (int i = 0 ; i<nums.size() ; i++)
		{
			if (nums[i] > max_val) {
				max_index = i;
				max_val = nums[i];
			}
		}
		TreeNode* root = new TreeNode(max_val);
		//�ָ����飬���Ϊ���������Ҳ�Ϊ������    *ע���ʱ������ҿ�����
		vector<int> nums_left(nums.begin(), nums.begin() + max_index);
		vector<int> nums_right(nums.begin() + max_index + 1, nums.end());

		//��������������ݹ�
		root->left = traversal(nums_left);
		root->right = traversal(nums_right);

		return root;
	}
};


class Solution {
private:
	// ������ҿ�����[left, right)�����������
	TreeNode* traversal(vector<int>& nums, int left, int right) {
		if (left >= right) return nullptr;

		// �ָ���±�maxValueIndex
		int maxValueIndex = left;
		for (int i = left + 1; i < right; ++i) {
			if (nums[i] > nums[maxValueIndex]) maxValueIndex = i;
		}

		TreeNode* root = new TreeNode(nums[maxValueIndex]);

		// ����ҿ���[left, maxValueIndex)
		root->left = traversal(nums, left, maxValueIndex);

		// ����ҿ���[maxValueIndex + 1, right)
		root->right = traversal(nums, maxValueIndex + 1, right);

		return root;
	}
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return traversal(nums, 0, nums.size());
	}
};