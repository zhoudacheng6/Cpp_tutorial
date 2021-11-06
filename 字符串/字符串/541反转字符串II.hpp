#include<iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	void reverse(string& s, int start, int end) {
		for (int i = start, j = end; i < j; i++, j--) {
			swap(s[i], s[j]);
		}
	}
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size(); i += (2 * k)) {
			// 1. ÿ�� 2k ���ַ���ǰ k ���ַ����з�ת
			// 2. ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ�
			if (i + k <= s.size()) {
				reverse(s, i, i + k - 1);
				continue;
			}
			// 3. ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
			reverse(s, i, s.size() - 1);
		}
		return s;
	}
};