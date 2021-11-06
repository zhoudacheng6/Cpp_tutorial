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
			auto iter = map.find(target - nums[i]); //������vector��Ѱ�������������½���unordered_map��Ѱ��
			if (iter != map.end()) //unordered_map��find �Ľ����Ϊ��
			{
				return { iter->second , i };
			}
			map.insert(pair<int, int>(nums[i], i));
		}
		return {};
	}
};