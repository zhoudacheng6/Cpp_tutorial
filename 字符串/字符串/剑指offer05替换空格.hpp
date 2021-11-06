#include<iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		//resize ԭ�ַ���
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
		//����ֵ
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
		int count = 0; // ͳ�ƿո�ĸ���
		int sOldSize = s.size();
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				count++;
			}
		}
		// �����ַ���s�Ĵ�С��Ҳ����ÿ���ո��滻��"%20"֮��Ĵ�С
		s.resize(s.size() + count * 2);
		int sNewSize = s.size();
		// �Ӻ���ǰ���ո��滻Ϊ"%20"
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