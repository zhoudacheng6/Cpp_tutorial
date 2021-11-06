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

//陷阱：不能单纯比较当前节点与左右子节点的大小关系

//递归----中序遍历
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		vec.clear(); 
		traversal(root);
		for (int i = 1; i < vec.size(); i++) {
			// 注意要小于等于，搜索树里不能有相同元素
			if (vec[i] <= vec[i - 1]) return false;
		}
		return true;
	}

private:
	//返回值    参数
	void traversal(TreeNode* root) {
		//终止条件
		if (root == nullptr) return ;
		//单层逻辑
		traversal(root->left);
		vec.push_back(root->val); // 将二叉搜索树转换为有序数组
		traversal(root->right);
	}
	vector<int> vec;
};

class Solution {
public:
	long long maxVal = LONG_MIN; // 因为后台测试数据中有int最小值
	bool isValidBST(TreeNode* root) {
		if (root == NULL) return true;

		bool left = isValidBST(root->left);
		// 中序遍历，验证遍历的元素是不是从小到大
		if (maxVal < root->val) maxVal = root->val;
		else return false;
		bool right = isValidBST(root->right);

		return left && right;
	}
};