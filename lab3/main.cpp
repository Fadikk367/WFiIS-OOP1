/* Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał
   a wynik jego działania był taki sam, jak podany na końcu tego pliku.
   Celem zadania jest napisanie klasy tablicy dwuwymiarowej Arr2D.
   Obiekty tej klasy moga wystepować w dwóch wariantach:
   - nie alokują pamieci (współdzieląc ją), gdy sa stworzone za pomocą funkcji adopt
   - alokują pamięć, gdy sa skonstruowane w zwyczajny sposób.
 * UWAGA: przy przypisaniu, i w konstruktorze kopiującym wytwarzamy obiekty, ktore alokują pamięć,
          destruktor nia zwalnia pamięci, gdy tablica jest tworzona za pomocą adopt.
   Klasa ma przeciążone operatory:
      [] odpowiada za dostep do elementow 
         (co  powinien operator[] zwrocic zeby mogl na nim zadzialac kolejny operator[]?)
      - odwracający tablicę [m][n] na [n][m]
      = operator przypisania i porówniania
      <<= oraz << służące do wypisywania. 

 * Proszę pamiętać o dokumentacji kodu.
 * Napisz Makefile albo skonfiguruj plik konfiguracyjny cmake tak, aby:
   - plikiem wynikowym był main
   - program kompilował się z flagami -Wall -pedantic.
   - były zdefiniowane cele użytkownika run, clean, check oraz all (main+run)

 * Kody źródłowe powinny znajdować    //Arr2D() : _alloc(false), _n(0), _m(0), _tab(nullptr) {};się w katalogu nazwisko_lab3 
 * do którego nikt oprócz właściciela nie ma praw dostępu.
 * UWAGA! Wysyłamy spakowany katalog, nie oddzielne pliki!!!!!!
 * Wcześniej KASUJEMY niepotrzebne pliki.
 */

#include <iostream>
#include "Arr2D.h"

int main() {

  int dataT[] = {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7};
  Arr2D T1 = Arr2D::adopt(dataT,4,4);
  Arr2D T1A = Arr2D::adopt(dataT,5,3);
  std::cout << "T1 = "<< T1 << std::endl;
  std::cout << "T1A = "<< T1A << std::endl;
  Arr2D T1B = -T1A;
  
  int x = T1[0][2];
  "--- T1A ---" <<= T1A;
  T1[1][2] = 0;
  T1[2][1] = 0;
  T1[3][0] = 0;
  dataT[3] = 0;
   "--- T1 ---" <<= T1;
   "~~~ T1A ~~~" <<= T1A;
   "... T1B ..." <<= T1B;  //powinna sie roznic od T1A, bo skopiowana przed podstawieniami
  std::cout << "Czy " << x << " rowne " << T1[0][2] << ((x == T1[0][2])? "? TAK":"? NIE") << std::endl;
  std::cout << "Czy " << T1[0][2] << " rowne 0? " << ((T1[0][2] == 0)? "TAK":"NIE") << std::endl;
  
  Arr2D T2 (3,3); // tablica, ktora sama alokuje pamięć
  //SPRAWDZ TO! Po odkomentowaniu poniższej linii powinien wyskoczyć błąd
  //Arr2D T2A (3,3.5);
  T2[0][0] = 5;
  T2[1][1] = 5; 
  T2[2][0] = 5; 
  "*** T2 ***" <<= T2;

  const Arr2D T3 = T2;  
  T2 = T1;
    
  "---------" <<= T2;
  "~~~~~~~~~" <<= -T3;
}
/* Oczekiwany wynik ./main

T1 = [ [1, 2, 3, 4] [5, 6, 7, 8] [9, 1, 2, 3] [4, 5, 6, 7] ]
T1A = [ [1, 2, 3, 4, 5] [6, 7, 8, 9, 1] [2, 3, 4, 5, 6] ]
--- T1A ---
1 2 3 4 5
6 7 8 9 1
2 3 4 5 6
--- T1A ---
--- T1 ---
1 2 3 0
5 6 0 8
9 0 2 3
0 5 6 7
--- T1 ---
~~~ T1A ~~~
1 2 3 0 5
6 0 8 9 0
2 3 0 5 6
~~~ T1A ~~~
... T1B ...
1 6 2
2 7 3
3 8 4
4 9 5
5 1 6
... T1B ...
Czy 3 rowne 3? TAK
Czy 3 rowne 0? NIE
*** T2 ***
5 0 0
0 5 0
5 0 0
*** T2 ***
---------
1 2 3 0
5 6 0 8
9 0 2 3
0 5 6 7
---------
~~~~~~~~~
5 0 5
0 5 0
0 0 0
~~~~~~~~~
 */
