#pragma once
#include <iostream>
#include <vector>

class ComplexNumber;

/// Klasa reprezentujaca GarbageCollector
/// dzialanie: 
/// Magazynuje dynamicznie zaalokowane obszary pamieci (wskazniki do nich - add / remove), pod koniec dzialania programu kiedy niszczona 
/// bedzie statyczna instancja tej klasy, zwalnia pamiec wskazywana przez przechowywane wskazniki
class GarbageCollector {
  public:

  GarbageCollector() = default;
  void add(ComplexNumber*);
  void remove(ComplexNumber*);
  std::vector<ComplexNumber*> allocated;

  ~GarbageCollector();
};


/// Klasa reprezentujaca liczbe zespolona
class ComplexNumber {
  public:

  ComplexNumber(int r = 0, int i = 0);
  /// przeladowane operatory new / delete pozwalaja na uzycie wczesniej przedstawionej klasy GarbageCollector - dodaja / usuwaja wskazniki
  /// na dynamicznie zaalokowana pamiec
  void* operator new(std::size_t);
  void operator delete(void*);
  ~ComplexNumber();

  friend std::ostream& operator<<(std::ostream&, const ComplexNumber&);

  private:

  /// obiekt ten bedzie niszczony na koncu dzialania programu - jego destruktor wyczysci niezwolnione "smieci"
  static GarbageCollector collector;
  int _r;
  int _i;
};


