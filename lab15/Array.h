#pragma once
#include <iostream>
#include <stdexcept>


/// Szablon reprezentujacy tablice statyczna o zadanym rozmiarze, parametryzowana typem T
template <int size, typename T>
class Array {
    public:
    
    Array();
    
    /// Przeciazony operator "[]", umozliwiajacy korzystanie z notacji tablicowej
    T& operator[](int idx);
    
    /// Przeciazony operator "<<", wymaga od typu "T" zdefiniowanego operatora "<<"
    friend std::ostream& operator<<(std::ostream& stream, const Array<size, T>& arr) {
        for (const auto& item : arr.m_arr)
            stream << item << " ";
        return stream;
    }
    
    ~Array() = default;
    
    protected:
    int m_size{size};
    T m_arr[size] = {T()};
};

template <int size, typename T>
Array<size, T>::Array() {
    std::cout << "---Tworze wersje T" << std::endl;
}


template <int size, typename T>
T& Array<size, T>::operator[](int i) {
    if (i < 0 || i >= m_size) {
        throw std::invalid_argument("Indeks poza zakresem");
    }
    return m_arr[i];
}



/// Specjalizacja poprzedniego szablonu Array dla typu wskaznikowego
template <int size, typename T>
class Array<size, T*> {
    public:

    Array();
    
    /// Przeciazony operator "[]", umozliwiajacy korzystanie z notacji tablicowej
    T*& operator[](int idx);
    
    /// Przeciazony operator "<<", wymaga od typu "T" zdefiniowanego operatora "<<"
    friend std::ostream& operator<<(std::ostream& stream, const Array<size, T*>& arr) {
        for (const auto& item : arr.m_arr) {
            if (item != nullptr) {
                stream << *item << " ";
            }
        }
        return stream;
    }
    
    ~Array();
    
    protected:
    int m_size{size};
    T* m_arr[size] = {nullptr};
};


template <int size, typename T>
Array<size, T*>::Array() {
    std::cout << "---Tworze wersje T*" << std::endl;
}

template <int size, typename T>
T*& Array<size, T*>::operator[](int i) {
    if (i < 0 || i >= m_size) {
        throw std::invalid_argument::invalid_argument();
    }
    return m_arr[i];
}

template <int size, typename T>
Array<size, T*>::~Array() {
    for (const T* item : m_arr)
        delete item;
    std::cout << "---Usuwam wersje T*" << std::endl;
}
