#include <iostream>
#include<vector>
#include<map>
#include<string>
#include<thread>
using namespace std;

class TA
{
public:
    TA(int& i) :m_i(i) {}
    void operator() ()
    {
        cout << "我的线程开始执行" << endl;//主线程执行
        cout << "m_i的值为：" << m_i << endl;
        cout << "m_i的值为：" << m_i << endl;
        cout << "m_i的值为：" << m_i << endl;
        cout << "m_i的值为：" << m_i << endl;
        cout << "m_i的值为：" << m_i << endl;
        cout << "m_i的值为：" << m_i << endl;
        cout << "我的线程执行完毕" << endl;//主线程执行
    }
public:
    int& m_i; //成员变量是引用
};

//int main()
//{
//    int my_i = 6;
//    TA ta(my_i);
//    std::thread mytobj(ta);//创建了线程，线程执行起点(入口)myprint();myprint()开始执行
//    //mytobj.join();//主线程阻塞到这里等待子线程myprint()执行完
//
//    mytobj.detach();//*主线程执行完毕而子线程要调用主线程创建的变量时会出现不可预估的bug
//    
//    cout << "主线程结束" << endl;//主线程执行
//    return 0;
//}