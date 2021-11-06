#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++)
		{
			auto iter = map.find(target - nums[i]); //不是在vector中寻找余数，是在新建的unordered_map中寻找
			if (iter != map.end()) //unordered_map中find 的结果不为空
			{
				return { iter->second , i };
			}
			map.insert(pair<int, int>(nums[i], i));
		}
		return {};
	}
};