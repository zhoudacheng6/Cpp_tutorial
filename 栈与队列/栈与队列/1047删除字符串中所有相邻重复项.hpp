#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	string removeDuplicates(string s) {
		stack<char> st;
		for (int i = 0 ; i<s.size() ; i++)
		{
			if (st.empty() || s[i] != st.top())
			{
				st.push(s[i]);
			}
			else
			{
				st.pop();
			}
		}
		string result = "";
		while (!st.empty())
		{
			result += st.top();
			st.pop();
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

//˫ָ�뷨
class Solution {
public:
	string removeDuplicates(string s) {
		int top = 0;
		for (char ch : s)
		{
			if (top == 0 || s[top - 1] != ch)
			{
				s[top++] = ch;
			}
			else
			{
				top--;
			}
		}
		s.resize(top);
		return s;
	}
};
