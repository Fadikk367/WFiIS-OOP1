#pragma once

#include <string>
#include <iostream>
#include <utility>

class Number;
class NumArray;

#include "Numbers.h"

/// Wyjatek przekroczenai zakresu, rzucany gdzy probujemy stworzyc Number a wartosc z poza przedzialu
class OutOfRange {
    public:
    OutOfRange(std::string numberName, float value, float min, float max, std::vector<Number*>& toDelete);
    
    /// szczegoly wyrzuconego wyjatku
    friend std::ostream& operator<<(std::ostream& stream, const OutOfRange& e);
    
    ~OutOfRange();
    
    protected:
    std::string m_numberName;
    float m_value;
    float m_min;
    float m_max;
    std::vector<Number*>& m_toDelete;
};


/// wyjatek przekroczenia rozmiaru tablicy, rzucany gdy nastapila proba wstawienia liczby na indeks wiekszy niz rozmiar tablicy
class OutOfSize {
    public:
    OutOfSize(NumArray* arr);
    OutOfSize(const OutOfSize& other);
    ~OutOfSize();

    NumArray* m_arr;
};

