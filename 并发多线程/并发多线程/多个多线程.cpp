#include <iostream>
#include<vector>
#include<map>
#include<string>
#include<thread>
using namespace std;

void MyPrint(int inum)
{
	cout << "MyPrint子线程开始执行，线程编号=" << inum << endl;



}

int main()
{
	//1、创建多个线程
	vector<thread> MyThreads;
	//创建十个线程
	for (int i = 0; i < 10; i++)
	{
		MyThreads.push_back(thread(MyPrint, i));
	}
	for (auto iter = MyThreads.begin() ; iter != MyThreads.end() ; iter++)
	{
		iter->join();  //等待10个
	}
	return 0;
}