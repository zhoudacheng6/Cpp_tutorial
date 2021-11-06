#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int strStr(string& haystack, string& needle) {
		if (needle.size() == 0)
		{
			return 0;
		}
		int next[needle.size()] ;
		getNext(next, needle);
		int j = -1;
		for (int i = 0 ; i<haystack.size() ; i++)
		{
			//��ƥ��
			while (j >= 0 && haystack[i]!=needle[j+1])
			{
				j = next[j];
			}
			//ƥ��
			if (haystack[i] == needle[j+1])
			{
				j++;
			}
			if (j == (needle.size()-1))
			{
				return (i - needle.size() + 1);
			}
		}
		return -1;
	}
	
	//��ȡǰ׺��
	//1����ʼ��
	//2��ǰ��׺����ͬ
	//3��ǰ��׺��ͬ
	//4��next
	void getNext(int* next, const string& s)
	{
		int j = -1; //1��ǰ׺ĩβ   2������i֮ǰ������ǰ��׺�ĳ���
		next[0] = j;
		for (int i = 1; i<s.size() ; i++)
		{
			//ǰ��׺��ͬ
			while ( j >= 0 && s[i] != s[j+1])
			{
				j = next[j]; //��ǰ����
			}
			//ǰ��׺��ͬ
			if (s[i] == s[j+1])
			{
				j++;
			}
			next[i] = j;
		}
	}
};