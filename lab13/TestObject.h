#pragma once 

#include <iostream>


/// Prosta klasa testowa, przechowujaca jedynie pole id, udostepnia operacje przypisanie id oraz wypisania informacji o obiekcie
class TestObject {
    public:
    
    TestObject() = default;
    TestObject(const int id) : m_id(id) {}
    
    /// Metoda ustawiajaca id obiektu
    void set(const int id) {
        m_id = id;
    }
    
    /// Metoda wypisujaca informacje o obiekcie
    void print() const {
        std::cout << "Obiekt o identyfikatorze ID=" << m_id << std::endl;
    }
    
    ~TestObject() = default;
    
    protected:
    int m_id;
};



