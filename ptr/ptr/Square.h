#pragma once
#include <cmath>
class Shape
{
public:
	Shape() {};
	virtual ~Shape() {};
	virtual double GetArea() = 0;
	virtual double GetPerim() = 0;
	int getVertexCount() const;
	
};

class Rectangle:public Shape
{
public:
	Rectangle() {}
	Rectangle(double w,double h):m_width(w),m_height(h) {};
	
	virtual ~Rectangle() {};
	virtual double GetArea() override {
		return m_width*m_height;
	};
	virtual double GetPerim() override {
		return 2.*( m_width+m_height);
	};
private:

	double m_width;
	double m_height;
};
class Circle :public Shape
{
public:
	Circle() {};
	Circle( double r) :m_radius(r) {};
	virtual ~Circle() {};
	virtual double GetArea() override {
		return m_radius*m_radius*pi;
	};
	virtual double GetPerim() override {
		return 2.*pi*m_radius;
	};
private:
	static const double pi;

	double m_radius;

};



class Square:public Rectangle
{
public:
	Square();
	Square(double w):Rectangle(w,w){};
	virtual ~Square();
};

