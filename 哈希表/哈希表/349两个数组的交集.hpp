#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution349 {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> result_set; //��Ž��
		unordered_set<int> nums_set(nums1.begin(), nums1.end());
		for (int num : nums2)
		{
			//����nums2��Ԫ����nums_set�г��ֹ�
			if (nums_set.find(num) != nums_set.end() )  //unordered_set��end()�����������һ��Ԫ����һ��λ�õĵ�����
			{
				result_set.insert(num);  //����ͬ��Ԫ�ط���unordered_set������
			}
		}
		return vector<int>(result_set.begin(),result_set.end()); //���vector����
	}
};
 
