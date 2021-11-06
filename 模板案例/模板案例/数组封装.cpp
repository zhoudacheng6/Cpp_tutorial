#include <iostream>
using namespace std;
#include "MyArray.hpp"

class Person
{
public:
	Person() {};
	Person(string name, int age)
	{
		this->m_Name = name;
	}
	int m_Age;
	string m_Name;
private:
	int m_Id;
};

void test01()
{
	MyArray<Person>arr (3);
	Person p1("孙悟空", 999);
	Person p2("rancho", 24);
	//将数据插入数组中
	arr.Push_Back(p1);
	arr.Push_Back(p2);
}


int main()
{

	system("paused");
	return 0;
}