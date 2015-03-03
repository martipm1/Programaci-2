#ifndef _Point2f_H_
#define _Point2f_H_


class Point2f
{
public:

	float x, y;

public:

	//Operators
	Point2f operator+ (const Point2f& a) const;

	Point2f& operator+= (const Point2f& a);

	Point2f operator- (const Point2f& a) const;

	Point2f& operator-= (const Point2f& a);

	bool operator== (const Point2f& a) const;

	bool operator!= (const Point2f& a) const;

	//Manipulate points
	void setZero();

	bool isZero() const;

	void negatePos();

	float DistanceTo(Point2f&);
};

#endif _Point2f_H_