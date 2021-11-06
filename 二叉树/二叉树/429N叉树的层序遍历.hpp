#include<iostream>
#include <stack>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

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
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> result;
		queue<Node*> que;
		if (root != nullptr) que.push(root);
		while (!que.empty())
		{
			int size = que.size();	//��¼ÿ�����Ŀ
			Node* record = que.front();
			result.push_back({});
			for (int i = 0; i < size; i++)  //�ѵ�ǰ��ڵ�ȫ������
			{
				Node* cur = que.front();
				que.pop();
				result.back().push_back(cur->val);
				for (auto c: cur->children)// �ѵ�ǰ������нڵ���ӽڵ�������
				{
					que.push(c);
				}
			}
		}
		return result;
	}
};