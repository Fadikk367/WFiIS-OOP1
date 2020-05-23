#include "Numbers.h"

float Number::rangeMin = 0.0;
float Number::rangeMax = 100.0;
std::vector<Number*> Number::staticNumbers = {};

static std::vector<Number*> tmpNumbers = {};


Number::Number(std::string name, float value) : m_name(name), m_value(value) {
    std::cout << "Tworzymy liczbe " << value << std::endl;
}

    
void Number::print() const {
    std::cout << m_name << " = " << m_value << std::endl;
}
    
void Number::Skip() const {
    throw  1.0;
}
    
void Number::setRange(float min, float max) {
    rangeMin = min;
    rangeMax = max;
}

Number* Number::set(std::string name, float value) {
    auto newNumber = new Number(name, value);
    tmpNumbers.emplace_back(newNumber);
    if (value < rangeMin || value > rangeMax) {
        throw OutOfRange(name, value, rangeMin, rangeMax, tmpNumbers);
    }
    return newNumber;
}

Number::~Number() {
    std::cout << "Usuwamy liczbe " << m_value << std::endl;    
}


NumArray::NumArray(int size) : m_numbers(std::vector<Number*>(size)), m_size(size) {
    for (auto& ptr : m_numbers)
        ptr = nullptr;
}
    
void NumArray::set(int idx, Number* num) {
    if ((idx > m_size || idx < 0) || m_numbers[idx] != nullptr) {
  //    OutOfSize problem(this); delete num; throw OutOfSize(problem) ;//EOM
    throw OutOfSize(this);
    }
    else {
        // delete m_numbers[idx];
        m_numbers[idx] = num;
    }    
}
    
NumArray::~NumArray() {
    for (auto ptr : m_numbers)
        delete ptr;
    delete this;
}

    


