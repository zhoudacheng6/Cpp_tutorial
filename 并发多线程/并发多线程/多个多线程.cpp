#include <iostream>
#include<vector>
#include<map>
#include<string>
#include<thread>
using namespace std;

void MyPrint(int inum)
{
	cout << "MyPrint���߳̿�ʼִ�У��̱߳��=" << inum << endl;



}

int main()
{
	//1����������߳�
	vector<thread> MyThreads;
	//����ʮ���߳�
	for (int i = 0; i < 10; i++)
	{
		MyThreads.push_back(thread(MyPrint, i));
	}
	for (auto iter = MyThreads.begin() ; iter != MyThreads.end() ; iter++)
	{
		iter->join();  //�ȴ�10��
	}
	return 0;
}