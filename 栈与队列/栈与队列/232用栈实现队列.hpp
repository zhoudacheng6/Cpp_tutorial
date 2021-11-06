#include<iostream>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
public:
    stack<int> stIn; //stl ��ջ��
    stack<int> stOut;
    /** Initialize your data structure here. */
    MyQueue() {

    }

    void push(int x) {
        stIn.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // ֻ�е�stOutΪ�յ�ʱ���ٴ�stIn�ﵼ�����ݣ�����stInȫ�����ݣ�
        if (stOut.empty())
        {
            // ��stIn��������ֱ��stInΪ��
            while (!stIn.empty())
            {
                stOut.push(stIn.top()); //��stIn�����ݵ���stOut
                stIn.pop();                    //��stIn���Ѿ��������������
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    int peek() {
		int res = this->pop(); // ֱ��ʹ�����е�pop����
		stOut.push(res); // ��Ϊpop����������Ԫ��res����������ӻ�ȥ
		return res;
    }

    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */