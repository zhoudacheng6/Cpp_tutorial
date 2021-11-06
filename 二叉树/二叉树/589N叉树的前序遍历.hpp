#include<iostream>
#include<vector>
using namespace std;
class Node {
public:
	int val;  //value 值
	vector<Node*> children;  //children 数组

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	vector<int> preorder(Node* root) {
		vector<int> result;
		Node* cur = root;
		traversal(result, cur);
		return result;
	}
	void traversal(vector<int>& result , Node* cur)
	{
		if (!cur) return;
		result.push_back(cur->val);
		int size = cur->children.size();
		//与二叉树不同 多叉树需要for循环遍历子树
		for (int i = 0; i<size ; i++)
		{
			Node* n = cur->children[i];
			//判定分界符null
			if(n) traversal(result, n);
		}
	}
};