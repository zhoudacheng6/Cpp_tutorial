#include<iostream>
#include <vector>

using namespace std;
class Node {
public:
	int val;  //value ֵ
	vector<Node*> children;  //children ����

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
	vector<int> postorder(Node* root) {
		vector<int> result;
		Node* cur = root;
		traversal(result, cur);
		return result;
	}
	void traversal(vector<int>& result, Node* cur)
	{
		if (!cur) return;
		int v = cur->val;  //��¼���ӽڵ�
		int size = cur->children.size();
		//���������ͬ �������Ҫforѭ����������
		for (int i = 0; i < size; i++)
		{
			Node* n = cur->children[i];
			//�ж��ֽ��null
			if (n) traversal(result, n);
		}

		result.push_back(cur->val);
	}
};