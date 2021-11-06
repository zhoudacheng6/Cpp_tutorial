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


//�� ����˳�� ���������дӸ��ڵ㵽Ҷ�ӽڵ��·��
//�ݹ�---ǰ�����---��--��--��
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
	//1������ֵ            ����ֵ(�ڵ㡢�ַ�����)
	void getPath(TreeNode* node, vector<string>& result , vector<int>& path)
	{
		path.push_back(node->val);
		//��ֹ����(�����ӽڵ�Ϊ�գ���ΪҶ�ӽڵ�)
		if (node->left == nullptr && node->right == nullptr) {
			//��ֹ�����߼�
			string sPath;
			for (int i = 0; i < path.size() - 1; i++) //��path���¼��·��תΪstring��ʽ
			{
				sPath += to_string(path[i]);
				sPath += "->";
			}
			sPath += to_string(path[path.size() - 1]);  //��¼���һ���ڵ�
			result.push_back(sPath);  //�ռ�һ��·��
			return;
		}

		//����ݹ��߼�
		if (node->left)
		{
			getPath(node->left , result, path);
			path.pop_back(); //����
		}
		if (node->right)
		{
			getPath(node->right, result, path);
			path.pop_back(); //����
		}
	}
};


//��
class Solution {
private:
	void traversal(TreeNode* cur, string path, vector<string>& result) {
		path += to_string(cur->val);  //��
		//��ֹ����
		if (cur->left == nullptr && cur->right == nullptr) //Ҷ�ӽڵ�
		{
			result.push_back(path);
			return;
		}
		//����ݹ��߼�
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