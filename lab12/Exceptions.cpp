#include "Exceptions.h"

OutOfRange::OutOfRange(std::string numberName, float value, float min, float max, std::vector<Number*>& toDelete) 
    : 
    m_numberName(numberName), 
    m_value(value), 
    m_min(min), 
    m_max(max),
    m_toDelete(toDelete)
    {
        std::cout << "Kontrola zakresu" << std::endl;
        std::cout << "UPS! Mamy problem z zakresem" << std::endl;
        throw *this;
    }
    
std::ostream& operator<<(std::ostream& stream, const OutOfRange& e) {
    std::cout << "Liczba " << e.m_numberName << " ma wartosc " <<  e.m_value <<  " spoza dopuszczalnego zakresu: [" << e.m_min << ", " << e.m_max << "]";
    return stream;
}

OutOfRange::~OutOfRange() {
    for (auto& ptr : m_toDelete) {
        if (ptr != nullptr) {
            delete ptr; 
            ptr = nullptr;
        }
    }
}
    



OutOfSize::OutOfSize(NumArray* arr) : m_arr(arr) {
    std::cout << "Kontrola rozmiaru" << std::endl;
    //std::cout << "UPS! Tablica pelna, koniec zabawy" << std::endl;
}

/// nie wywoluje sie - nie wiem dlaczego
OutOfSize::OutOfSize(const OutOfSize& other) {
    std::cout << "UPS! Tablica pelna, koniec zabawy" << std::endl;
    m_arr = std::move(other.m_arr);
}

OutOfSize::~OutOfSize() {
// for (int i = 0; i < m_arr->getSize(); ++i) //EOM
//        delete m_arr->getContent(i);    //EOM
    delete m_arr;
}
