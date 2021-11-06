#include <iostream>
#include<vector>
#include<map>
#include<string>
#include<thread>
using namespace std;

//陷阱一
void myprint1(const int& i, char* pmybuf)
{
    cout << i << endl; //i 并不是mvar的引用，实际是值传递
    cout << pmybuf << endl; //指针在detach子线程时绝对会有问题
    return;
}
//陷阱二
void myprint2(const int& i, const string &pmybuf) 
{
	cout << i << endl; 
	cout << pmybuf.c_str() << endl; //在detach子线程的情况下，存在隐患bug，主线程执行完，mvar的隐性转换没完成
	return;
}

int main()
{
    //一：传递临时对象作为线程参数
    //事实1：只要用临时构造的对象作为参数传递给线程，那么就一定能够在主线程执行完毕前把子线程的参数构造出来，从而确保即便detach()子线程也安全运行
    int mvar = 1;
    int& mvary = mvar;
    char mybuf[] = "this is a test";
    //std::thread mytobj(myprint2 , mvar ,mybuf); //将mvar的值复制给了i
    std::thread mytobj(myprint2, mvar, string(mybuf)); //直接将mybuf转换成string对象，这是一个可以保证在线程中用肯定有效的对象
                                                                                           //在创建线程的同时构造临时对象的方法传递参数是可行的
    mytobj.join();
    //mytobj.detach();//*主线程执行完毕而子线程要调用主线程创建的变量时会出现不可预估的bug

    cout << "主线程结束" << endl;//主线程执行
    return 0;
}