#include<iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char>  sta;
		for (int i = 0 ; i<s.size() ; i++)
		{
			switch (s[i])
			{
			case '(':
				sta.push('(');
				break;
			case '[':
				sta.push('[');
				break;
			case '{':
				sta.push('{');
				break;
			case ')':
				if (sta.empty()  || sta.top() != '(' )
				{
					return false;
				}
				else
				{
					sta.pop();
				}
				break;
			case ']':
				if (sta.empty() || sta.top() != '[')
				{
					return false;
				}
				else
				{
					sta.pop();
				}
				break;
			case '}':
				if (sta.empty() || sta.top() != '{')
				{
					return false;
				}
				else
				{
					sta.pop();
				}
				break;
			}
		}
		return sta.empty();
	}
};