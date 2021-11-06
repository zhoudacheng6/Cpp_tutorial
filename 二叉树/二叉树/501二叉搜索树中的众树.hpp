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


//�Ƕ������������
//�ݹ�
//ͳ��ÿ��val��Ƶ��
class Solution {
private:
	//������¼ÿ��Ԫ��
	void searchBST(TreeNode* cur, unordered_map<int, int>& map) 
	{
		if (cur == nullptr) return;
		map[cur->val]++; //ͳ��Ԫ��Ƶ��
		searchBST(cur->left , map);
		searchBST(cur->right, map);
		return;
	}
	//��map�е�valueֵ��������
	bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
public:
	vector<int> findMode(TreeNode* root) {
		unordered_map<int , int > map;   //����unordered_map<key , value>�ռ�val�����num
		vector<int> result;
		if (root == nullptr) return result;
		searchBST(root, map);
		//��map��Ԫ�ؽ�������
		vector<pair<int, int>> vec(map.begin() , map.end());
		sort(vec.begin(), vec.end(), cmp);  //��Ƶ������
		//ȡ��Ƶ
		result.push_back(vec[0].first);
		for (int i = 1 ; i< vec.size() ;i++)
		{
			if (vec[i].second == vec[0].second)
			{
				result.push_back(vec[i].first);
			}
			else break;
		}
		return result;
	}
};

class Solution {
public:
	vector<int> findMode(TreeNode* root) {
		stack<TreeNode*> st;
		TreeNode* cur = root;
		TreeNode* pre = nullptr;
		int max_count = 0;	//���Ƶ��
		int count = 0;	//ͳ��Ƶ��
		vector<int> result;
		while (!st.empty() || cur != nullptr)
		{
			if (cur!= nullptr){
				st.push(cur);
				cur = cur->left;
			}
			else {
				cur = st.top();
				st.pop();

				//**************
				if (pre ==nullptr){
					count = 1;
				}
				else if (pre->val == cur->val){
					count++;
				}
				else {
					count = 1;
				}
				if (count == max_count)
				{
					result.push_back(cur->val);
				}
				if (count>max_count)
				{
					max_count = count;
					result.clear();
					result.push_back(cur->val);
				}
				//**************

				pre = cur;
				cur = cur->right;
			}
		}
		return result;
	}
};