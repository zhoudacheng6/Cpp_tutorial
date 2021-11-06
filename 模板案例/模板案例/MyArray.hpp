#pragma once
#include<iostream>
#include <string>
using namespace std;

//数组类封装
//案例描述：实现一个通用的数组类，要求如下：
//1、可以对内置数据类型以及自定义数据类型的数据进行存储
//2、将数组中的数据 存储到堆区
//3、构造函数中可以传入数组的容量
//4、提供对应的拷贝构造函数以及operator = 防止浅拷贝问题
//5、提供尾插法和尾删法对数组中的数据进行增加和删除
//6、可以通过下标的方式访问数组中的元素
//7、可以获取数组中当前元素个数和数组的容量

template<class T>
class MyArray
{
public:
//构造函数
	MyArray(int capacity)
	{
		cout << "MyArray有参构造函数调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[capacity];  //数组创建到堆区
	}
//拷贝构造
	MyArray(const MyArray& arr)
	{
		cout << "MyArray拷贝构造函数的调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		
		//深拷贝
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
//operator=赋值运算符重载 防止浅拷贝问题
	MyArray& operator = (const MyArray& arr)
	{
		cout << "operator=的调用" << endl;
		//先判断当前堆区是否有数据，如果有先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
//尾插法
	void Push_Back(const T& val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
//尾删法
	void Pop_Back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->pAddress[this->m_Size - 1] = NULL;
	}
//通过下标的方式访问数组中的元素
	T& operator[] (int index)
	{
		return this->pAddress[index];
	}
//返回数组的容量
	int GetCapacity()
	{
		return this->m_Capacity;
	}
//返回数组大小
	int getSize()
	{
		return this->m_Size;
	}
//析构函数
	~MyArray()
	{
		cout << "析构函数调用" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;   //创建T类型指针变量pAddress
	int m_Capacity;
	int m_Size;
};