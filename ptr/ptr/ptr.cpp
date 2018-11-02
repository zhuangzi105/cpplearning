// ptr.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

class A
{

public:
	int add(int a, int  b)
	{
		return a + b;
	}
	int mul(int a, int  b)
	{
		return a *b;
	}
	int& geta()
	{
		//return const_cast<int &> (static_cast<const A*>(this)->geta());
		return m_a;
	}
	
	int m_a=1;
	int m_b=2;
};
class B :public A
{


};
class Counter 
{
public:
	Counter(int c) :count(c) {};
	Counter(const Counter& c) :count(c.count) {};
	~Counter()  {};
	int GetCount() const { return count; };
	Counter operator +(const Counter & c2)
	{
		return Counter(count + c2.GetCount());
	}
	Counter& operator++()
	{
		count++;
		return *this;
	}
	Counter operator++(int)
	{
		Counter c = *this;
		count++;
		return c;
	}
private:
	int count;

};
 ostream& operator<<(ostream& os,Counter & c)
{
	os << c.GetCount();
	return os;

}
#include "Square.h"
int main()
{
	 A a;
	 B b;

	cout << a.geta()<<endl;

	Counter c1(2);

	Counter c2(3);
	cout << (c1 + c2)<<endl;
	cout << c2++ << endl;
	cout << ++c2 << endl;

	Shape * sp[3];
	sp[0]=new Rectangle(2, 3);
	sp[1] = new Circle(4);
	sp[2] = new Square(4);
	
	for (int i = 0; i < 3; i++)
	{

		cout << sp[i]->GetArea() << endl;
		cout << sp[i]->GetPerim() << endl;
		cout <<"VertexCount: "<< sp[i]->getVertexCount() << endl;
	}




	return 0;

}

