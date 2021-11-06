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

//递归----后序遍历----回溯
//二叉搜索树中 p.val <公共祖先
class Solution {
public:
	//返回值：当前root是否在pq之间       参数：树节点，待寻找的p、q子节点
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//终止条件
		// root 为 nullptr 时
		if (root == nullptr) return root;

		//单层逻辑
		if (root->val > p->val && root->val > q->val)
		{
			TreeNode* left = lowestCommonAncestor(root->left, p, q);
			if (left != nullptr){
				return left;
			}
		}
		else if (root->val<p->val && root->val > q->val)
		{
			TreeNode* right = lowestCommonAncestor(root->left, p, q);
			if (right != nullptr) {
				return right;
			}
		}
		else
		{
			return root;
		}
	}
};