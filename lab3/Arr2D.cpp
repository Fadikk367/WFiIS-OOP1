#include "Arr2D.h"


Arr2D::Arr2D(int n, int m) : _n(n), _m(m) {
    _alloc = true;
    _tab = new int[n*m];
}

Arr2D::Arr2D(const Arr2D& arr) {
    _alloc = true;
    _n = arr.getN();
    _m = arr.getM();
    _tab = new int[_n*_m];
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _m; j++) {
            (*this)[i][j] = arr[i][j];
        }
    }
    
}

Arr2D& Arr2D::adopt(int* data, int n, int m) {
    Arr2D* tmp = new Arr2D(data, n, m);
    return *tmp;
}

int Arr2D::getN() const {
    return _n;
}

int Arr2D::getM() const {
    return _m;
}

int* Arr2D::getPtr() const {
    return _tab;
}

int* Arr2D::operator[](int i) const {
    return &(_tab[i*(this->getN())]);
}

Arr2D& Arr2D::operator-() const {
    Arr2D* tmp = new Arr2D(*this);
    tmp->swapDim();
    return *tmp;
}

Arr2D& Arr2D::operator=(Arr2D& arr) {
    if (this->_tab != nullptr) {
        delete _tab;
    }
    this->_tab = arr.getPtr();
    this->_n = arr.getN();
    this->_m = arr.getM();
    return *this;
    // return Arr2D(arr);
}


void operator<<=(std::string str, const Arr2D& arr) {
    std::cout << str << std::endl;
    for (int i = 0; i < arr.getN(); i++) {
        for (int j = 0; j < arr.getM(); j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }  
    std::cout << str << std::endl; 
}

void Arr2D::swapDim() {
    int tmp = this->_n;
    this->_n = this->_m;
    this->_m = tmp;
}


Arr2D::~Arr2D() {
    if(_alloc) {
        delete _tab;
    }
}

std::ostream& operator<<(std::ostream& stream, Arr2D& arr) {
    stream << "[";
    for (int i = 0; i < arr.getN(); i++) {
        stream << "[";
        for (int j = 0; j < arr.getM(); j++) {
            stream << arr[i][j];
            if ( j != arr.getM() - 1) {
                stream << ", ";
            }
        }
        stream << "],";
    }
    stream << "]" << std::endl;
    return stream;
}