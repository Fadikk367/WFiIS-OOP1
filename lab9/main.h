/// hierarchia klas:
/// Interfejsy Drawable oraz Transformalbe umozliwiaja rysowanie oraz manipulacje obiektow geometrycznych
/// klasa bazowa Shape reprezentuje abstrakcyjny obiekt geometryczny, implementuje interfejsy Drawable oraz Trafnsofmable
/// klasa ClosedShape reprezentujaca figury zamkniete poszerza funkcjonalnosc klasy Shape o obliczanie pola
/// klasy Point oraz Section dziedzicza po klasie Shape
/// klasy Cricle, Deltoid naturalnie dziedzicza po klasie ClosedShape
///
/// P.S Zdecydowalem sie klase Point dziedziczaca po Shape w celu umozliwienia operacji podobnych jak dla reszty figur
/// tym samym Point moze byc jest zarowno skladowa pozostalych obiektow jak i pelnoprawnym obiektem, ktory mozna wyrysowac czy przesunac
#include "Shapes.h"

void draw(Drawable* obj) {
    obj->draw();
}