#pragma once
#include <iostream>

/// Klasa reprezentujaca tablice dynamiczna
class Tablica {
public:
  Tablica();
  Tablica(int*, int);
  Tablica(const Tablica&);

  Tablica& operator=(const Tablica&);
  /// Dodawanie elementow na koneic tablicy
  Tablica operator+(int) const;
  /// Dostep do elementu, odpowiednik []
  int& operator()(int) const;
  /// Usuwanie z tablicy pierwszego wytapienia podanej jako argument liczby
  Tablica operator-(int) const;
  /// Usuwanie z tablicy wszytskich wystapien podanej liczby => UWAGA! modyfikuje tablice
  Tablica operator-=(int);
  /// Laczenie dwoch tablic w jedna
  Tablica operator+(const Tablica&) const;

  ~Tablica();

  friend std::ostream& operator<<(std::ostream&, const Tablica&);

  int* poczatek() const;
  int* koniec() const;

  /// Tworzy nowa tablice unikalnych elementow => odpowiednik tworzenia zbioru
  Tablica tylkoPierwszeWystapienia();

  typedef  const int* IteratorStaly;
  typedef int* Iterator;

private:
  int* _ptr;
  int _len;
};
