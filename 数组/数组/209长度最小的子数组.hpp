#include <iostream>
using namespace std;
#include<vector>

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		//双指针法滑动窗口
		int left_index = 0, right_index = 0;
		int sum = nums[left_index];
		int temp =0; //记录长度
		while (right_index <= nums.size()-1)
		{
			//1、求出sum
			/*int sum = 0;
			for (int i = left_index; i <= right_index; i++)
			{
				sum += nums[i];
			}*/
			//判断sum与target
			if (sum < target)
			{
				right_index++;
				if (right_index < nums.size())
				{
					sum += nums[right_index];
				}
			}
			else 
			{
				if (temp == 0)
				{
					temp =  right_index - left_index+1;
				}
				else
				{
					temp = min(temp, right_index - left_index+1);
				}
				sum -= nums[left_index];
				left_index++;
			}
		}
		
		return temp;
	}

};