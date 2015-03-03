#include "Point2f.h"
#include <math.h> 

//--------------------------------------------------------------
//--------------------OPERATORS---------------------------------
//--------------------------------------------------------------
Point2f Point2f::operator+ (const Point2f& a) const
{
	Point2f point;

	point.x = x + a.x;
	point.y = y + a.y;

	return (point);
}

Point2f& Point2f::operator+= (const Point2f& a)
{
	x += a.x;
	y += a.y;

	return(*this);
}

Point2f Point2f::operator- (const Point2f& a) const
{
	Point2f point;

	point.x = x - a.x;
	point.y = y - a.y;

	return (point);
}

Point2f& Point2f::operator-= (const Point2f& a)
{
	x -= a.x;
	y -= a.y;

	return(*this);
}

bool Point2f::operator== (const Point2f& a) const
{
	return(x == a.x && y == a.y);
}

bool Point2f::operator!= (const Point2f& a) const
{
	return(x != a.x || y == a.y);
}

//--------------------------------------------------------------
//------------------MANIPULATE POINTS---------------------------
//--------------------------------------------------------------
void Point2f::setZero()
{
	x = y = 0.0f;
}

bool Point2f::isZero() const
{
	return x == 0.0f && y == 0.0f;
}

void Point2f::negatePos()
{
	x = -x;
	y = -y;
}

float Point2f::DistanceTo(Point2f& a1)
{
	float distance;
	distance = sqrt((a1.x - x)*(a1.x - x) + (a1.y - y)*(a1.y - y));
	return distance;
}