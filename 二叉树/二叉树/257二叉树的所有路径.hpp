#include<iostream>
#include<vector>
#include <stack>
#include<queue>
#include<string>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


//按 任意顺序 ，返回所有从根节点到叶子节点的路径
//递归---前序遍历---中--左--右
class Solution {
public:
	vector<string > binaryTreePaths(TreeNode* root){
		vector<string> str;
		vector<int> path;
		if (root == nullptr) return str;
		getPath(root, str ,path);
		return str;
	}

private:
	//1、返回值            输入值(节点、字符串组)
	void getPath(TreeNode* node, vector<string>& result , vector<int>& path)
	{
		path.push_back(node->val);
		//终止条件(左右子节点为空，则为叶子节点)
		if (node->left == nullptr && node->right == nullptr) {
			//终止处理逻辑
			string sPath;
			for (int i = 0; i < path.size() - 1; i++) //将path里记录的路径转为string格式
			{
				sPath += to_string(path[i]);
				sPath += "->";
			}
			sPath += to_string(path[path.size() - 1]);  //记录最后一个节点
			result.push_back(sPath);  //收集一个路径
			return;
		}

		//单层递归逻辑
		if (node->left)
		{
			getPath(node->left , result, path);
			path.pop_back(); //回溯
		}
		if (node->right)
		{
			getPath(node->right, result, path);
			path.pop_back(); //回溯
		}
	}
};


//简化
class Solution {
private:
	void traversal(TreeNode* cur, string path, vector<string>& result) {
		path += to_string(cur->val);  //中
		//终止条件
		if (cur->left == nullptr && cur->right == nullptr) //叶子节点
		{
			result.push_back(path);
			return;
		}
		//单层递归逻辑
		if (cur->left)
		{
			traversal(cur->left, path+ "->", result);
		}
		if (cur->right)
		{
			traversal(cur->right, path+"->", result);
		}
	}
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		string path;
		if (root == nullptr) return result;
		traversal(root, path, result);
		return result;
	}
};