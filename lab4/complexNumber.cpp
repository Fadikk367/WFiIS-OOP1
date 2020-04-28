#include "complexNumber.h"


/// GarbageCollector
void GarbageCollector::add(ComplexNumber* ptr) {
  allocated.emplace_back(ptr);
}
void GarbageCollector::remove(ComplexNumber* ptr) {
  int idx = 0;
  for (auto* el: allocated) {
    if (el == ptr) break;
    idx++;
  }
  allocated.erase(allocated.begin() + idx);
}

GarbageCollector::~GarbageCollector() {
  for (auto* ptr: allocated)
    delete ptr;
}


/// ComplexNumber
GarbageCollector ComplexNumber::collector = GarbageCollector();

ComplexNumber::ComplexNumber(int r, int i): _r(r), _i(i) {
  std::cout << "Constructing " << *this << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const ComplexNumber& num) {
  return stream << num._r << "+" << num._i << "i";
}

ComplexNumber::~ComplexNumber() {
  std::cout << "Deleting: " << *this << std::endl;
}

void* ComplexNumber::operator new(std::size_t size) {
  auto ptr =  std::malloc(size);
  collector.add(static_cast<ComplexNumber*> (ptr));
  return ptr;
}

void ComplexNumber::operator delete(void* ptr) {
  collector.remove(static_cast<ComplexNumber*> (ptr));
	free(ptr);
}
