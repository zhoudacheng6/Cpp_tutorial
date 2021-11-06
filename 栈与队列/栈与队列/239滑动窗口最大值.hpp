#include <iostream>
#include <queue>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		MyQueue que;
		vector<int> result;
		//记录前k个元素最大值
		for (int i = 0 ; i<k ; i++)
		{
			que.push(nums[i]);
		}
		result.push_back(que.front());  
		for (int i  = k ; i<nums.size() ; i++)
		{
			que.pop(nums[i - k]); //滑动窗口移除左侧元素（如果最前面元素刚好为最大值则移除）
			que.push(nums[i]);     //滑动窗口增加右侧元素
			result.push_back(que.front());
		}
		return result;
	}
private:
	class MyQueue{  //单调队列(从小到大)
	public:
		deque<int> que;  
		void pop(int value) 
		{
			if (!que.empty() && value == que.front())  
			{   //队列非空且队头最大值为value值
				que.pop_front();
			}
		}
		void push(int value)
		{
			while (!que.empty() && value>que.back())
			{
				que.pop_back();
			}
			que.push_back(value);
		}
		int front()
		{
			return que.front();
		}
	};
};



//双端数组法
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {

		vector<int> res;
		deque<int> deque;

		for (int i = 0; i < nums.size(); i++) {

			if (!deque.empty() && deque.front() == i - k)  //非空且当前队列最大值为滑动窗口左端元素
			{
				deque.pop_front();
			}
			while (!deque.empty() && nums[i] > nums[deque.back()]) 
			{
				deque.pop_back();
			}
			deque.push_back(i); //进队列的是下标

			if (i >= k - 1)
			{
				res.push_back(nums[deque.front()]); //记录最大值
			} 
		}

		return res;
	}
};