#include "numbers.h"

 float polish::operator,(int d) const {
    float tmp = static_cast<float> (d);
    while(tmp > 1)
      tmp /= 10;
    return this->_val + tmp;
  }
