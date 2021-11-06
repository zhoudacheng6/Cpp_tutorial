#include<iostream>
#include <string>

using namespace std;

class Solution242 {
public:
	bool isAnagram(string s, string t) {
		int record[26] = { 0 };
		for (int i = 0 ; i<s.size() ; i++)
		{
			record[s[i] - 'a']++;
		}
		for (int i = 0 ; i<t.size() ; i++)
		{
			record[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (record[i] != 0) {
				// record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
				return false;
			}
		}
		// record数组所有元素都为零0，说明字符串s和t是字母异位词
		return true;
	}
};