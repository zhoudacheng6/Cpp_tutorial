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
			//不匹配
			while (j >= 0 && haystack[i]!=needle[j+1])
			{
				j = next[j];
			}
			//匹配
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
	
	//求取前缀表
	//1、初始化
	//2、前后缀不相同
	//3、前后缀相同
	//4、next
	void getNext(int* next, const string& s)
	{
		int j = -1; //1、前缀末尾   2、代表i之前的最长相等前后缀的长度
		next[0] = j;
		for (int i = 1; i<s.size() ; i++)
		{
			//前后缀不同
			while ( j >= 0 && s[i] != s[j+1])
			{
				j = next[j]; //向前回退
			}
			//前后缀相同
			if (s[i] == s[j+1])
			{
				j++;
			}
			next[i] = j;
		}
	}
};