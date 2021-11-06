#include<iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

//ͳ��Ԫ�س���Ƶ��----map
//��Ƶ������
//�ҳ�ǰk����ƵԪ��
class Solution {
public:
	//���������  ����
	class mycomparison
	{
	public:
		bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
		{
			return lhs.second > rhs.second;
		}
	};
	
	vector<int> topKFrequent(vector<int>& nums, int k) {
		//ͳ�Ƴ���Ԫ�ص�Ƶ��
		unordered_map<int, int> map;  
		for (int i = 0 ; i<nums.size() ; i++)
		{
			map[nums[i]]++;
		}

		//��Ƶ�ʽ�������
		//����һ�����ȼ�����С���ѣ���СΪk
		//priority_queue<Type, Container, Functional>Type Ϊ�������ͣ� Container Ϊ�������ݵ�������Functional ΪԪ�رȽϷ�ʽ��
		priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que; 

		//�ù̶���СΪk��С���ѣ�ɨ������Ƶ�ʵ���ֵ
		for (unordered_map<int , int>::iterator it = map.begin() ; it!=map.end() ; it++)
		{
			pri_que.push(*it);
			if (pri_que.size() > k)
			{
				pri_que.pop();
			}
		}

		// �ҳ�ǰK����ƵԪ�أ���ΪС�����ȵ���������С�ģ����Ե��������������
		vector<int> result(k);
		for (int i = k-1 ; i>=0 ; i--)
		{
			result[i] = pri_que.top().first;
			pri_que.pop();
		}
		return result;
	}
};