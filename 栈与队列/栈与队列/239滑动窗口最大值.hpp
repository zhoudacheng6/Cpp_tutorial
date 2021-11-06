#include <iostream>
#include <queue>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		MyQueue que;
		vector<int> result;
		//��¼ǰk��Ԫ�����ֵ
		for (int i = 0 ; i<k ; i++)
		{
			que.push(nums[i]);
		}
		result.push_back(que.front());  
		for (int i  = k ; i<nums.size() ; i++)
		{
			que.pop(nums[i - k]); //���������Ƴ����Ԫ�أ������ǰ��Ԫ�ظպ�Ϊ���ֵ���Ƴ���
			que.push(nums[i]);     //�������������Ҳ�Ԫ��
			result.push_back(que.front());
		}
		return result;
	}
private:
	class MyQueue{  //��������(��С����)
	public:
		deque<int> que;  
		void pop(int value) 
		{
			if (!que.empty() && value == que.front())  
			{   //���зǿ��Ҷ�ͷ���ֵΪvalueֵ
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



//˫�����鷨
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {

		vector<int> res;
		deque<int> deque;

		for (int i = 0; i < nums.size(); i++) {

			if (!deque.empty() && deque.front() == i - k)  //�ǿ��ҵ�ǰ�������ֵΪ�����������Ԫ��
			{
				deque.pop_front();
			}
			while (!deque.empty() && nums[i] > nums[deque.back()]) 
			{
				deque.pop_back();
			}
			deque.push_back(i); //�����е����±�

			if (i >= k - 1)
			{
				res.push_back(nums[deque.front()]); //��¼���ֵ
			} 
		}

		return res;
	}
};