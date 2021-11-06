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

//递归
class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
				return traversal(inorder, postorder);
	}
	//返回值  参数
	TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
		//终止条件
		if (postorder.size() == 0) return nullptr;

		//单层逻辑
		//取后序数组的最后一个元素，即当前根节点并创建该根节点
		int root_val = postorder[postorder.size() - 1];
		TreeNode* root = new TreeNode(root_val);

		//利用根节点找到中序数组的切割点
		int index = 0;
		while (inorder[index]!=root_val)
		{
			index++;
		}

		// 切割中序数组，得到 中序左数组和中序右数组
		vector<int> inorder_left(inorder.begin(), inorder.begin()+index);
		vector<int> inorder_right(inorder.begin() + index+1, inorder.end());
		// 切割后序数组，得到 后序左数组和后序右数组
		// postorder 舍弃末尾元素
		postorder.resize(postorder.size() - 1);
		vector<int> postorder_left(postorder.begin(), postorder.begin()+inorder_left.size());
		vector<int> postorder_right(postorder.begin()+inorder_left.size() , postorder.end());

		root->left = traversal(inorder_left, postorder_left);
		root->right = traversal(inorder_right, postorder_right);

		return root;
	}
};