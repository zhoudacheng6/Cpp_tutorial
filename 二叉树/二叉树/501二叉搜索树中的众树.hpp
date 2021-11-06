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


//非二叉搜索树情况
//递归
//统计每个val的频率
class Solution {
private:
	//遍历记录每个元素
	void searchBST(TreeNode* cur, unordered_map<int, int>& map) 
	{
		if (cur == nullptr) return;
		map[cur->val]++; //统计元素频率
		searchBST(cur->left , map);
		searchBST(cur->right, map);
		return;
	}
	//对map中的value值进行排序
	bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
public:
	vector<int> findMode(TreeNode* root) {
		unordered_map<int , int > map;   //构建unordered_map<key , value>收集val及相关num
		vector<int> result;
		if (root == nullptr) return result;
		searchBST(root, map);
		//对map中元素进行排序
		vector<pair<int, int>> vec(map.begin() , map.end());
		sort(vec.begin(), vec.end(), cmp);  //给频率排序
		//取高频
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
		int max_count = 0;	//最大频率
		int count = 0;	//统计频率
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