#ifndef 2DPointTemplate_H
#define 2DPointTemplate_H
#include <math.h> 

template <class TYPE>

class 2DPointTemplate
{
public:

	TYPE x, y;

	2DPointTemplate operator+ (const 2DPointTemplate& a) const
	{
		2DPoint point;

		point.x = x + a.x;
		point.y = y + a.y;

		return (point);
	}

	2DPointTemplate& operator+= (const 2DPointTemplate& a)
	{
		x += a.x;
		y += a.y;

		return(*this);
	}

	2DPointTemplate operator- (const 2DPointTemplate& a) const
	{
		2DPoint point;

		point.x = x - a.x;
		point.y = y - a.y;

		return (point);
	}

	2DPointTemplate& operator-= (const 2DPointTemplate& a)
	{
		x -= a.x;
		y -= a.y;

		return(*this);
	}

	bool operator== (const 2DPointTemplate& a) const
	{
		return(x == a.x && y == a.y);
	}

	bool operator!= (const 2DPointTemplate& a) const
	{
		return(x != a.x || y == a.y);
	}

	void setZero()
	{
		x = y = 0;
	}

	bool isZero() const
	{
		return x == 0 && y == 0;
	}

	void negatePos()
	{
		x = -x;
		y = -y;
	}

	TYPE DistanceTo(2DPointTemplate& a1)
	{
		TYPE distance;
		distance = sqrt((a1.x - x)*(a1.x - x) + (a1.y - y)*(a1.y - y));
		return distance;
	}
};

#endif 2DPointTemplate_H