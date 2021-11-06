#include<iostream>
#include<vector>

//构建二叉树的结构
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


//建立二叉树
void CreateBiTree(TreeNode* T)
{

}

int main()
{

	return 0;
}