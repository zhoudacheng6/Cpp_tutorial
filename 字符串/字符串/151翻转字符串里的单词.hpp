#include<iostream>
#include <string>
#include <vector>
using namespace std;

//split �⺯�������ַ����ָ��һ����Ƭ��......��
//˫ָ�뷨
class Solution {
public:
	void reverse(string s, int start, int end)
	{
		for (int i = start, j = end; start < end; i--, j--)
		{
			swap(s[start], s[end]);
		}
	}
	void removeExtraSpace(string& s)
	{
		int left = 0, right = 0;
		//1��ȥ���ַ���ǰ��ո�
		while (s.size() > 0 && right < s.size() && s[right]==' ')
		{
			right++;
		}
		for ( ; right < s.size() ; right++)
		{
			if (right>1 && s[right] == s[right-1] && s[right] == ' ')
			{
				continue;
			}
			else
			{
				s[left++] = s[right];
			}
		}

		if (left >1  && s[left-1] == ' ')
		{
			s.resize(left-1);
		}
		else
		{
			s.resize(left);
		}
	}

	string reverseWords(string s) {
		removeExtraSpace(s);
		reverse(s, 0, s.size() - 1);
		for (int i = 0; i < s.size(); i++) {
			int j = i;
			// ���ҵ��ʼ�Ŀո񣬷�ת����
			while (j < s.size() && s[j] != ' ')  j++;
			reverse(s, i, j - 1);
			i = j;
		}
		return s;
	}
	
};