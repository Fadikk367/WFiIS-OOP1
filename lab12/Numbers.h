#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <array>

#include "Exceptions.h"

class OutOfRange;
class OutOfSize;

/// Klasa reprezentujaca liczbe wraz z nazwa
class Number {
    public:
    Number(std::string name, float value);
    
    /// funkcja wypisujaca informacje o liczbie
    void print() const;
    
    /// funkcja pomijajaca dalsze instrukcje w bloku try
    void Skip() const;
    
    /// funckja ustawiajaca dozwolony przedzial
    static void setRange(float min, float max);
    
    /// funkcja-fabryka dodajaca nwoe punkty do tymczasowego wektora statycznego
    static Number* set(std::string name, float value);
    
    static float rangeMin;
    static float rangeMax;
    static std::vector<Number*> staticNumbers;
    
    ~Number();
    
    protected:
    
    std::string m_name;
    float m_value;
};


/// klasa reprezentujaca tablice liczb
class NumArray {
    public:
    NumArray(int size);
    
    /// funkcja dodajaca do tablicy kolejna liczbe pod zadanym indeksem
    void set(int idx, Number* num);
    
    ~NumArray();
    int getSize(){return m_size;}  //EOM
    Number* getContent(int i){return m_numbers[i];} //EOM
    
    protected:
    
    /// wektor przechowujacy liczby
    std::vector<Number*> m_numbers;
    int m_size;
};