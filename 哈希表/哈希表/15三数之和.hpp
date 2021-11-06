#include<iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#include <algorithm>

//��ϣ�������ʺϽ�����֮��
class Solution15 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());  //�������������
		for (int i = 0 ; i<nums.size();i++)
		{
			//����֮�������һ��Ԫ���Ѿ�����0����ô�����ܴճ���Ԫ��
			if (nums[i]>0)
			{
				continue;
			}
			if (i>0 && nums[i] == nums[i-1])  //��һ������ͬʱ
			{
				continue;
			}
			unordered_set<int> set;
			for (int j = i+1 ; j<nums.size();j++)
			{
				if (j > i + 2
					&& nums[j] == nums[j - 1]
					&& nums[j - 1] == nums[j - 2]) { // ��Ԫ��Ԫ��bȥ��
					continue;
				}
				int c = 0 - (nums[i] + nums[j]);
				if (set.find(c) != set.end()) {
					result.push_back({ nums[i], nums[j], c });
					set.erase(c);// ��Ԫ��Ԫ��cȥ��
				}
				else {
					set.insert(nums[j]);
				}
			}
		}
		return result;

	}
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // �ҳ�a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // ����֮�������һ��Ԫ���Ѿ������㣬��ô���������϶������ܴճ���Ԫ�飬ֱ�ӷ��ؽ���Ϳ�����
            if (nums[i] > 0) {
                return result;
            }
            // ����ȥ�ط���������©��-1,-1,2 �������
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            // ��ȷȥ�ط���
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                // ȥ�ظ��߼�����������0��0��0 �����������ֱ�ӵ��� right<=left �ˣ��Ӷ�©���� 0,0,0 ������Ԫ��
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // ȥ���߼�Ӧ�÷����ҵ�һ����Ԫ��֮��
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // �ҵ���ʱ��˫ָ��ͬʱ����
                    right--;
                    left++;
                }
            }

        }
        return result;
    }
};
