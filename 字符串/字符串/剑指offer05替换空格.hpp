#include<iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		//resize 原字符串
		int num = 0;
		for (int i = 0 ; i<s.size();i++)
		{
			if (s[i] == ' ')
			{
				num++;
			}
		}
		int oldlength = s.size();
		s.resize(s.size() +2*num);
		int newlength = s.size();
		//反向赋值
		for (int left = oldlength - 1 , right = newlength - 1; left < right; left--, right--)
		{
			if (s[left] != ' ') {
				s[right] = s[left];
			}
			else
			{
				s[right] = '0';
				s[right - 1] = '2';
				s[right - 2] = '%';
				right -= 2;
			}
		}
		return s;
	}
};

class Solution {
public:
	string replaceSpace(string s) {
		int count = 0; // 统计空格的个数
		int sOldSize = s.size();
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				count++;
			}
		}
		// 扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
		s.resize(s.size() + count * 2);
		int sNewSize = s.size();
		// 从后先前将空格替换为"%20"
		for (int right = sNewSize - 1, left = sOldSize - 1; left < right ; right--, left--) {
			if (s[left] != ' ') {
				s[right] = s[left];
			}
			else {
				s[right] = '0';
				s[right - 1] = '2';
				s[right - 2] = '%';
				right -= 2;
			}
		}
		return s;
	}
};