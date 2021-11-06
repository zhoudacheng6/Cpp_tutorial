#include<iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

//统计元素出现频率----map
//对频率排序
//找出前k个高频元素
class Solution {
public:
	//运算符重载  排序
	class mycomparison
	{
	public:
		bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
		{
			return lhs.second > rhs.second;
		}
	};
	
	vector<int> topKFrequent(vector<int>& nums, int k) {
		//统计出现元素的频率
		unordered_map<int, int> map;  
		for (int i = 0 ; i<nums.size() ; i++)
		{
			map[nums[i]]++;
		}

		//对频率进行排序
		//定义一个优先级队列小顶堆，大小为k
		//priority_queue<Type, Container, Functional>Type 为数据类型， Container 为保存数据的容器，Functional 为元素比较方式。
		priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que; 

		//用固定大小为k的小顶堆，扫面所有频率的数值
		for (unordered_map<int , int>::iterator it = map.begin() ; it!=map.end() ; it++)
		{
			pri_que.push(*it);
			if (pri_que.size() > k)
			{
				pri_que.pop();
			}
		}

		// 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒叙来输出到数组
		vector<int> result(k);
		for (int i = k-1 ; i>=0 ; i--)
		{
			result[i] = pri_que.top().first;
			pri_que.pop();
		}
		return result;
	}
};