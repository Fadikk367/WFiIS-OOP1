#include "Shapes.h"

std::ostream& operator<<(std::ostream& stream, const Point& p) {
    stream << "(" << p._x << ", " << p._y << ")";
    return stream;
}


double Point::getX() const {
    return _x;
}

double Point::getY() const {
    return _y;
}

void Point::draw() const {
    std::cout << "Rysujemy punkt (" << _x << ", " << _y << ")" << std::endl;
}

void Point::shift(double offsetX, double offsetY) {
    _x += offsetX;
    _y += offsetY;
}



Point Section::getBegin() const {
    return _begin;
}

Point Section::getEnd() const {
    return _end;
}
    

void Section::draw() const {
    std::cout << "Rysujemy odcinek od " << _begin << " do " << _end << std::endl;
}

double Section::length() const {
    double length = sqrt(powf(_end.getX() - _begin.getX(), 2) + powf(_end.getY() - _begin.getY(), 2));
    return length;
}

void Section::shift(double offsetX, double offsetY) {
    _begin.shift(offsetX, offsetY);
    _end.shift(offsetX, offsetY);
}




void Circle::draw() const {
    std::cout << "Rysujemy kolo o srodku " << _center << " i promieniu " << _r << std::endl;
}

double Circle::length() const {
    return 2 * M_PI * _r;
}

void Circle::shift(double offsetX, double offsetY) {
    _center.shift(offsetX, offsetY);
}

double Circle::area() const {
    return M_PI * _r * _r;
}





void Deltoid::draw() const {
    std::cout << "Rysujemy deltoid o wierzcholkach " << _A << ", " << _B << ", " << _C << ", " << _D<< std::endl;
}

double Deltoid::length() const {
    double circumference = 0;
    circumference += Section(_A, _B).length();
    circumference += Section(_B, _C).length();
    return 2 * circumference;
}

void Deltoid::shift(double offsetX, double offsetY) {
    _A.shift(offsetX, offsetY);
    _B.shift(offsetX, offsetY);
    _C.shift(offsetX, offsetY);
    _D.shift(offsetX, offsetY);
}
    
double Deltoid::area() const {
    return Section(_A, _C).length() * Section(_B, _D).length();
}

