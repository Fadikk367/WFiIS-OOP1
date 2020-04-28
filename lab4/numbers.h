#pragma once

typedef float english;

class polish {
  public:
  
  /// Konstruktor konwertujacy
  polish(int val) : _val(val) {};

  /// Przeciazony operator "," majacy na celu zwrocenie liczny zmiennoprzecinkowej z zapisu: (polish) num1,num2 => num1.num2
  float operator,(int d) const;

  private:

  int _val{0};
};

