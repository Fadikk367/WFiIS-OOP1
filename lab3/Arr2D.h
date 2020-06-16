#pragma once 
#include <iostream>


/// Klasa reprezentujaca tablice 2D;
class Arr2D {
public:
    Arr2D(const Arr2D&);
    Arr2D(int n, int m);
    /// Konstruktor wytorzystywany przez metode statyczna adopt, nie alokuje pamieci na dane
    Arr2D(int* data, int n, int m) : _alloc(false), _n(n), _m(m), _tab(data) {};

    /// Statyczna funkcja niealokujaca pamieci dla tablicy, korzysta z przekazanych za pomoca wskaznika danych
    static Arr2D& adopt(int* data, int n, int m);

    /// Operator "[]", umozliwia odwolywanie sie do obiektu klasy jak do zwyklej tablicy dwuwymiarowej
    int* operator[](int) const;
    /// Operator "-", zamienia wymiary tablicy (_n z _m)
    Arr2D& operator-() const;
    Arr2D& operator=(Arr2D&);

    int getN() const;
    int getM() const;
    int* getPtr() const;


    void swapDim();


    friend void operator<<=(std::string, const Arr2D&);
    friend std::ostream& operator<<(std::ostream&, Arr2D&);

    ~Arr2D();

private:

    bool _alloc;
    int _n;
    int _m;
    int* _tab;

};