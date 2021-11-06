#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution349 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> result_set; //存放结果
		unordered_set<int> nums_set(nums1.begin(), nums1.end());
		for (int num : nums2)
		{
			//发现nums2的元素在nums_set中出现过
			if (nums_set.find(num) != nums_set.end() )  //unordered_set的end()函数返回最后一个元素下一个位置的迭代器
			{
				result_set.insert(num);  //将相同的元素放入unordered_set集合中
			}
		}
		return vector<int>(result_set.begin(),result_set.end()); //输出vector数组
	}
};
 
