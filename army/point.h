#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
protected:
    int X;
    int Y;

public:
    Point( int Y = 0, int X = 0);

    void setX(int);
    void setY(int);

    int getX() const ;
    int getY() const ;

    bool operator==( const Point &) const;
    bool operator!=( const Point &) const;
};

std::ostream& operator<<(std::ostream& out, const Point& point);
#endif // POINT_H
