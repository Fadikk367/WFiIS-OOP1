#pragma once
#include <iostream>
#include <string>

/// Dwie trywialne testowe klasy sluzace sprawdzeniu dzialania szablonu Array dla wlasnych typow
/// kalsy przechowuja jedynie pojedynczy napis i wypisuja informacje w konstruktorzch i desktruktorach

class X {
    public:

    X(std::string name) : m_name(name) {
        std::cout << "Tworze X " << m_name << std::endl;
    }
    
    /// przeciazony operator "<<" wymagany przez szablon Array w celu uniwersalnego wypisywania
    friend std::ostream& operator<<(std::ostream& stream, const X& obj) {
        return stream << obj.m_name;
    }
    
    virtual ~X() {
        std::cout << "Usuwam X " << m_name << std::endl;
    }
    
    protected:
    
    std::string m_name;
};

class Y : public X {
    public:
    
    Y(std::string name) : X(name) {
        std::cout << "Tworze Y " << name << std::endl;
    }
    
    ~Y() override {
        std::cout << "Usuwam Y " << m_name << std::endl;
    }
};