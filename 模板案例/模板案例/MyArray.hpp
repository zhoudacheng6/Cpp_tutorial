#pragma once
#include<iostream>
#include <string>
using namespace std;

//�������װ
//����������ʵ��һ��ͨ�õ������࣬Ҫ�����£�
//1�����Զ��������������Լ��Զ����������͵����ݽ��д洢
//2���������е����� �洢������
//3�����캯���п��Դ������������
//4���ṩ��Ӧ�Ŀ������캯���Լ�operator = ��ֹǳ��������
//5���ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
//6������ͨ���±�ķ�ʽ���������е�Ԫ��
//7�����Ի�ȡ�����е�ǰԪ�ظ��������������

template<class T>
class MyArray
{
public:
//���캯��
	MyArray(int capacity)
	{
		cout << "MyArray�вι��캯������" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[capacity];  //���鴴��������
	}
//��������
	MyArray(const MyArray& arr)
	{
		cout << "MyArray�������캯���ĵ���" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		
		//���
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
//operator=��ֵ��������� ��ֹǳ��������
	MyArray& operator = (const MyArray& arr)
	{
		cout << "operator=�ĵ���" << endl;
		//���жϵ�ǰ�����Ƿ������ݣ���������ͷ�
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
//β�巨
	void Push_Back(const T& val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
//βɾ��
	void Pop_Back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->pAddress[this->m_Size - 1] = NULL;
	}
//ͨ���±�ķ�ʽ���������е�Ԫ��
	T& operator[] (int index)
	{
		return this->pAddress[index];
	}
//�������������
	int GetCapacity()
	{
		return this->m_Capacity;
	}
//���������С
	int getSize()
	{
		return this->m_Size;
	}
//��������
	~MyArray()
	{
		cout << "������������" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;   //����T����ָ�����pAddress
	int m_Capacity;
	int m_Size;
};