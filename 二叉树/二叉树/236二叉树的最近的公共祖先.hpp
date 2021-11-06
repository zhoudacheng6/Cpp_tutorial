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

//自底向上查找-----回溯算法
//后序遍历是天然的回溯算法-----左右中
class Solution {
public:
	//返回值  参数
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//终止条件
		if (root == q || root == p || root == nullptr) return root; //发现节点返回节点
		
		//单层逻辑
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);

		//当前节点的左右节点中
		if (left != nullptr && right != nullptr) return root;  //p 、 q 出现在左右子树中
		else if (left == nullptr && right != nullptr) return right;	//左子树中无pq ，右子树中有pq
		else if (left != nullptr && right == nullptr) return left;
		else return nullptr;  //左右节点的返回值均为空
	}
};