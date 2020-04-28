#pragma once

/// Interfejs umozliwiajacy rysowanie figury oraz obliczenie jej długosci/obwodu
class Drawable {
    public:
    
    /// Funkcja rysujaca obiekt geometryczny
    virtual void draw() const = 0;
    
    /// Funkcja obliczajaca dlugosc/obwod obiektu geometrycznego
    virtual double length() const {
        return 0.0;
    }
    
    virtual ~Drawable() = default;
};

/// Interfejs umozliwiajacy przesuwanie obiektu
class Transformable {
    public:
    
    /// Funkcja przesuwajaca obiekt geometryczny
    /// parametry: offsetX, offsetY
    virtual void shift(double, double) = 0;
    
    virtual ~Transformable() = default;
};