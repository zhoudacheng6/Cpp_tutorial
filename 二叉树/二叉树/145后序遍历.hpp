#include<iostream>
#include <vector>
#include<stack>
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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		traversal(root, result);
		return result;
	}
	void traversal(TreeNode* cur, vector<int>& result)
	{
		if (cur == nullptr)  //2、终止条件
		{
			return;
		}
		traversal(cur->left, result);		//左
		traversal(cur->right, result);	//右
		result.push_back(cur->val);	//中

	}
};



//迭代方式
//left root right
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		if (root == NULL) return result;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			result.push_back(node->val);
			if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
			if (node->right) st.push(node->right); // 空节点不入栈
		}
		reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
		return result;
	}
};