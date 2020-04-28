#pragma once

#include <iostream>
#include <cmath>

#include "Interfaces.h"

/// Bazowa klasa reprezentująca abstrakcyjny obiekt geometryczny
/// implementacja interfejsow Drawable oraz Transformable pozwala odpowiednio na
/// rysowanie obiektu oraz manipulowanie nim (przesuniecie)
class Shape : public Drawable, public Transformable {
    public:
    virtual ~Shape() = default;
};


/// Klasa rozszerzajaca abstrakcyjna figure zamknieta, ze zdefiniowana funkcja
/// obliczajaca pole tej figury
class ClosedShape : public Shape {
    public:
    /// Funkcja obliczajaca pole figury zamknietej
    virtual double area() const = 0;
    virtual ~ClosedShape() = default;
};


/// Klasa reprezentujaca punkt 2D
/// (zdecydowalem sie na dziedziczenie z Shape zeby umozliwic opracje na punkcie 
///podobne do reszty figur - draw, shift itp, funkcja length zwraca wartosc 0 aby byc w zgodzie
/// z definicja punktu jako obiektu bezwymiarowego)
class Point : public Shape {
    public:
    Point(const double x, const double y) : _x(x), _y(y) {}
    
    double getX() const;
    double getY() const;
    
    void draw() const override;
    void shift(double, double) override;
    
    friend std::ostream& operator<<(std::ostream&, const Point&);
    ~Point() override = default;
    
    protected:
    double _x;
    double _y;
};


/// klasa reprezentujaca odcinek, ktory naturalnie sklada sie z dwoch punktow - poczatku i konca
class Section : public Shape {
    public:
    Section(const Point begin, const Point end) : _begin(begin), _end(end) {}
    Section(const Section& other) : _begin(other.getBegin()), _end(other.getEnd()) {}
        
    Point getBegin() const;
    Point getEnd() const;
    
    void draw() const override;
    double length() const override;
    void shift(double, double) override;
    
    ~Section() override = default;
    
    protected:
    Point _begin;
    Point _end;
};


/// klasa reprezentujaca okrad na plaszczyznie 2D o srodku _center oraz promieniu _r
class Circle : public ClosedShape {
    public:
    Circle(Point p, double r) : _center(p), _r(r) {}
    
    void draw() const override;
    double length() const override;
    void shift(double, double) override;
    double area() const override;
    
    ~Circle() override = default;
    
    protected:
    Point _center;
    double _r;
};


/// klasa reprezentujaca deltoid o wierzcholkach _A, _B, _C, _D
class Deltoid : public ClosedShape {
    public:
    Deltoid(const Point a, const Point b, const Point c, const Point d) 
        : 
        _A(a), 
        _B(b), 
        _C(c), 
        _D(d) 
    {}
    /// Konstruktor tworzacy deltoid na podstawie dwoch przekatnych
    Deltoid(const Section diagE, const Section diagF) 
        :  
        _A(diagE.getBegin()), 
        _B(diagF.getBegin()), 
        _C(diagE.getEnd()), 
        _D(diagF.getEnd()) 
    {}
    
    void draw() const override;
    double length() const override;
    void shift(double, double) override;
    double area() const override;
    
    ~Deltoid() override = default;
    
    protected:
    Point _A;
    Point _B;
    Point _C;
    Point _D;
};