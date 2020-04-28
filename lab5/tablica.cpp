#include "tablica.h"

Tablica::Tablica() {
  _ptr = nullptr;
  _len = 0;
}

Tablica::Tablica(int* data, int len) : _len(len) {
  _ptr = new int[len];
  for (int i = 0; i < len; i++) {
    _ptr[i] = data[i];
  }
}

Tablica::Tablica(const Tablica& tab) {
  _len = tab._len;
  _ptr = new int[_len];
  for (int i = 0; i < _len; i++) {
    _ptr[i] = tab._ptr[i];
  }
}

Tablica& Tablica::operator=(const Tablica& tab) {
  if (_ptr == tab._ptr) {
    return *this;
  } else if (_len != 0) {
    delete[] _ptr;
  }
  _len = tab._len;
  _ptr = new int[_len];
  for (int i = 0; i < _len; i++) {
    _ptr[i] = tab._ptr[i];
  }
  return *this;
}

Tablica Tablica::operator+(int el) const {
  int* tmpData = new int[_len + 1];
  for (int i = 0; i < _len; i++)
    tmpData[i] = _ptr[i];
  tmpData[_len] = el;
  Tablica tmp(tmpData, _len + 1);
  delete[] tmpData;
  return tmp;
}

int& Tablica::operator()(int i) const {
  return _ptr[i];
}

Tablica Tablica::operator-(int num) const {
  int idx = -1;
  for (int i = 0; i < _len; i++) {
    if (_ptr[i] == num) {
      idx = i;
      break;
    }
  }

  if (idx != -1) {                                              
    int* tmpData = new int[_len - 1];
    for (int i = 0; i < idx; i++) 
      tmpData[i] = _ptr[i];
    for (int i = idx; i < _len - 1; i++)
      tmpData[i] = _ptr[i + 1];

    Tablica tmp(tmpData, _len - 1);
    delete[] tmpData;
    return tmp;
  } 
  return *this;
}

Tablica Tablica::operator-=(int num) {
  int count = 0;
  for (int i = 0; i < _len; i++) {
    if (_ptr[i] == num) {
      count++;
    }
  }

  if (count != 0) {
    int* tmpData = new int[_len - count];
    int offset = 0;
    for (int i = 0; i < _len - count; i++) {
      while (_ptr[i + offset] == num) offset++;
      tmpData[i] = _ptr[i + offset];
    }
    delete[] _ptr;
    _ptr = tmpData;
    _len -= count;
  }
  return *this;
}

Tablica Tablica::operator+(const Tablica& tab) const {
  int sumLen = _len + tab._len;
  int* tmpData = new int[sumLen];
  for (int i = 0; i < _len; i++)
    tmpData[i] = _ptr[i];
  for (int i = 0; i < tab._len; i++)
    tmpData[i + _len] = tab._ptr[i];
  Tablica tmp(tmpData, sumLen);
  delete[] tmpData;
  return tmp;
}

int* Tablica::poczatek() const {
  return &(_ptr[0]);
}

int* Tablica::koniec() const {
  return &(_ptr[_len - 1]);  
}

Tablica Tablica::tylkoPierwszeWystapienia() {
  bool* repeated = new bool[_len];
  int count = 0;

  for (int i = 0; i < _len; i++) {
    repeated[i] = false;
  }
    
  for (int i = 0; i < _len; i++) {
    for (int j = i + 1; j < _len; j++) {
      if(_ptr[j] == _ptr[i]) {
        count++;
        repeated[j] = true;
      }
    }
  }
  
  int uniqueLen = _len - count;
  int* unique = new int[uniqueLen];

  int offset = 0;
  for (int i = 0; i < uniqueLen; i++) {
    while(repeated[i + offset] == true) offset++;
    unique[i] = _ptr[i + offset];
  }

  Tablica result(unique ,uniqueLen);
  delete[] unique;
  delete[] repeated;
  return result;
}

Tablica::~Tablica() {
  delete[] _ptr;
  _ptr = nullptr;
  _len = 0;
}

std::ostream& operator<<(std::ostream& stream, const Tablica& tab) {
  for (int i = 0; i < tab._len - 1; i++)
    stream << tab._ptr[i] << ", ";
  stream << tab._ptr[tab._len - 1];
  return stream;
}