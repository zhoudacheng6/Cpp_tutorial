#include<iostream>
#include<stack>
#include<string>
#include <sstream>
#include<vector>
using namespace std;
class Solution {
public:
	string simplifyPath(string path) {
		stringstream ss; //创建流
		ss << path;		//向流中传值
		string readache;
		vector<string> filename;
		while (getline(ss,readache,'/'))   //basic_istream &  getline ( char_type * s , std :: streamsize count , char_type delim ) ;从流中提取字符直到行尾或指定的分隔符delim。
		{
			if (readache == ""){
				continue;
			}
			else if(readache == "."){
				continue;
			}
			else if(readache == ".."){
				if (filename.size()>0){
					filename.pop_back();
				}
			}
			else {
				filename.push_back(readache);
			}
		}
		string result = "";
		for (int i = 0 ; i<filename.size() ; i++)
		{
			result.append("/" + filename[i]);
		}
		if (result == "")
		{
			return "/";
		}
		return result;
	}
};