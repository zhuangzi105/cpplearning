#include "stdafx.h"
#include "Square.h"
#include <typeinfo>
const double Circle::pi = 3.1415926;

int Shape::getVertexCount() const
{
	const Rectangle*p= dynamic_cast< const Rectangle*>(this);
	if (p)
	{
		return 4;
	}
	else
	{
		const Square*p = dynamic_cast< const Square*>(this);
		if (p)
		{
			return 4;
		}
		else
		{
			const Circle*p = dynamic_cast<const Circle*>(this);
			if (p)
			{
				return 0;
			}

		}

	}
	/*if (typeid(*this) == typeid(Rectangle) || typeid(*this) == typeid(Square))
	{
		return 4;
	}
	else if (typeid(*this) == typeid(Circle))
	{
		return 0;
	}*/

}
Square::Square()
{
}


Square::~Square()
{
}
