#pragma once

#include <iostream>

#include "TestObject.h"


/// Klasa reprezentujaca statyczny wektor parametryzowany typem przechowywanych wartosci
/// z zaimplementowanymi podstawowymi operacjami: inicjalizacji, pobierania elementu orazczyszczenia wektora
class Vector {
    public:
    
    /// Szablon funkcji inicjalizujacej wektor, alokuje odpowiedni rozmair pamieci dla <size> elementow o typie T
    template <typename T>
    static void initialise(const int size) {
        m_size = size;
        m_vector = new T[size];
    }
    
    /// Kolejny szablon funkcji inicjalizujacej, dodatkowo wypelnia zaalokowany wektor obiektami podanymi jako drugi argument wywolania
    template <typename T>
    static void initialise(const int size, const T firstObject) {
        m_size = size;
        m_vector = new T[size];
        for (int i = 0; i < size; ++i) {
            static_cast<T*> (m_vector)[i] = firstObject;
        }
            
    }
    
    ///  Szablon umozliwiajacy dostanie sie do elementu wektora o okreslonym indeksie <index>
    template <typename T>
    static T& at(const int index) {
        if (index < 0 || index >= m_size) {
            std::cout << index << " " << m_size << std::endl;
            throw "Odwolanie do indeksu spoza tablicy";
        }
            
        return static_cast<T*> (m_vector)[index];
    }
    
    
    /// Statyczna metoda zwracajaca aktualny rozmiar wektora
    static int size() {
        return m_size;
    }
    
    /// Szablon funkcji resetujacej - zwlaniajacej wektor
    template <typename T>
    static void reset() {
        delete[] static_cast<T*> (m_vector);
        m_vector = nullptr;
    }

    private:

    static int m_size;
    static void* m_vector;
};

void* Vector::m_vector = nullptr;
int Vector::m_size = 0;

