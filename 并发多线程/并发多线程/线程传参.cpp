#include <iostream>
#include<vector>
#include<map>
#include<string>
#include<thread>
using namespace std;

//����һ
void myprint1(const int& i, char* pmybuf)
{
    cout << i << endl; //i ������mvar�����ã�ʵ����ֵ����
    cout << pmybuf << endl; //ָ����detach���߳�ʱ���Ի�������
    return;
}
//�����
void myprint2(const int& i, const string &pmybuf) 
{
	cout << i << endl; 
	cout << pmybuf.c_str() << endl; //��detach���̵߳�����£���������bug�����߳�ִ���꣬mvar������ת��û���
	return;
}

int main()
{
    //һ��������ʱ������Ϊ�̲߳���
    //��ʵ1��ֻҪ����ʱ����Ķ�����Ϊ�������ݸ��̣߳���ô��һ���ܹ������߳�ִ�����ǰ�����̵߳Ĳ�������������Ӷ�ȷ������detach()���߳�Ҳ��ȫ����
    int mvar = 1;
    int& mvary = mvar;
    char mybuf[] = "this is a test";
    //std::thread mytobj(myprint2 , mvar ,mybuf); //��mvar��ֵ���Ƹ���i
    std::thread mytobj(myprint2, mvar, string(mybuf)); //ֱ�ӽ�mybufת����string��������һ�����Ա�֤���߳����ÿ϶���Ч�Ķ���
                                                                                           //�ڴ����̵߳�ͬʱ������ʱ����ķ������ݲ����ǿ��е�
    mytobj.join();
    //mytobj.detach();//*���߳�ִ����϶����߳�Ҫ�������̴߳����ı���ʱ����ֲ���Ԥ����bug

    cout << "���߳̽���" << endl;//���߳�ִ��
    return 0;
}