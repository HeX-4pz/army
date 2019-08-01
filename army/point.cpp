#include "point.h"

Point::Point(int Y, int X) {
    this->X = X;
    this->Y = Y;
}

void Point::setX(int x) {
    this->X = x;
}

void Point::setY(int y) {
    this->Y = y;
}

int Point::getX() const {
    return this->X;
}

int Point::getY() const {
    return this->Y;
}

bool Point::operator==( const Point & point) const {
    if ( this->X == point.getX() && this->Y == point.getY() ) {
        return  true;
    }
    return false;
}

bool Point::operator!=( const Point & point) const {
    if ( this->X == point.getX() && this->Y == point.getY() ) {
        return  false;
    }
    return true;
}

std::ostream &operator<<(std::ostream &out, const Point &point)
{
    out << point.getY() << " " << point.getX();
}
