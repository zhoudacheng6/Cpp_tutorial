#include<iostream>
#include <stack>
#include <queue>

using namespace std;
class MyStack {
public:
    queue<int> que1;
    queue<int> que2;  //用来备份数据

    MyStack() {

    }

    void push(int x) {
        que1.push(x);
    }

    int pop() {
        int size = que1.size();
        size--;
        while (size--)
        {
            que2.push(que1.front());
            que1.pop();
        }
        int result = que1.front();
        que1.pop();
        while (!que2.empty())
        {
            que2.pop();
        }
        return result;
    }

    int top() {
        return que1.back();
    }

    bool empty() {
        return que1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */