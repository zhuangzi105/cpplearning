#include "stdafx.h"


#include <string>
#include <iostream>
#include <xmemory>

using namespace std;
class Exception {
public:
	Exception(string& s):message(s){};
	virtual ~Exception() {};
	const string& what() const
	{
		return message;
	};
private:
	string message;
};
class OutOfMemory:public Exception {
public:
	OutOfMemory() :Exception(string("内存不足")) {};
	virtual ~OutOfMemory() {};

};
class RangeError :public Exception {
public:
	RangeError() :Exception(string("输入的数不在指定范围内")) {};
	virtual ~RangeError() {};

};
class Demo
{

public:
	Demo() {
		cout << "Demo 默认构造函数" << endl;
	}
	~Demo() {
		cout << "Demo 析构函数" << endl;
	}
	Demo(const Demo &)
	{
		cout << "Demo 拷贝构造函数" << endl;
	}
	Demo & operator=(const Demo &)
	{
		cout << "Demo 赋值构造函数" << endl;
		return *this;
	}
	void dosomething()
	{
		int * cc = new int[100];
		throw OutOfMemory();

	}
	void dosomething2()
	{
		
		throw RangeError();

	}
	void do3() throw(char)
	{
		int * cc = nullptr;
		long long int n =1024ll*1024ll*1024ll*20ll;
		try
		{
			cc = new int[n];
		}
		catch (bad_alloc& e)
		{
			throw char(1);
		}
		delete[] cc;
	
	}
};
int main()
{
	Demo d1;
	try
	{
		//d1.dosomething();
		d1.dosomething2();
	}
	catch (OutOfMemory& e)
	{
		cout << e.what()<<endl;
	}
	catch (RangeError& e)
	{
		cout << e.what() << endl;
	}
	catch (Exception& e)
	{
		cout << e.what() << endl;
	}


	//12-5

	try
	{
		//d1.dosomething();
		d1.do3();
	}
	catch (char& e)
	{
		cout << e << endl;
	}
	Demo *d2 = new Demo();
	Demo *d3 = new Demo();
	Demo *d4 = new Demo();
	auto_ptr<Demo> p2(d2);
	auto_ptr<Demo> p3(d3);
	auto_ptr<Demo> p4(p3);
	p2 = p3;
	p2.reset(d4);
	return 0;
}