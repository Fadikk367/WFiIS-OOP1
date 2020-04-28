#include "tablica.h"
#include <iostream>

int main ()
{
  using namespace std;

  int surowaTablica [] = {2, 4, 6};
  const Tablica* const pierwsza = new Tablica (surowaTablica, sizeof(surowaTablica)/sizeof(int));
  cout<<"Pierwsza: "<<*pierwsza<<"\n"; // Pierwsza: 2, 4, 6

  Tablica* druga = new Tablica;
  Tablica& trzecia = *druga;

  *druga = *pierwsza + 2 + 3 + 5;
  cout<<"Druga: "<<*druga<<"   Pierwsza: "<<*pierwsza<<"\n"; // Druga: 2, 4, 6, 2, 3, 5   Pierwsza: 2, 4, 6

  *druga + 4 + 6;
  cout<<"Druga II: "<<*druga<<"\n"; // Druga II: 2, 4, 6, 2, 3, 5

  trzecia = *druga;
  cout<<"Trzecia: "<<trzecia<<"\n"; // Trzecia: 2, 4, 6, 2, 3, 5

  trzecia(0) = trzecia(1);
  trzecia(1) = 2;
  cout<<"trzecia II: "<<trzecia<<"   Pierwsza: "<<(*pierwsza)(0)<<", "<<(*pierwsza)(1)<<"\n"; // trzecia II: 4, 2, 6, 2, 3, 5   Pierwsza: 2, 4

  cout<<"Bez szostki "<< *druga - 6 <<"\n"; // Bez szostki 4, 2, 2, 3, 5

  cout<<"Bez dwojek "<< (*druga -= 2) <<"\n"; // Bez dwojek 4, 6, 3, 5

  trzecia = *pierwsza + *druga;

  for (Tablica::IteratorStaly liczba = pierwsza->poczatek(); liczba != pierwsza->koniec(); ++liczba)
    cout <<*liczba<<", ";
  cout<<*pierwsza->koniec()<<"\n";

  Tablica niepowtarzalna = trzecia.tylkoPierwszeWystapienia();
  cout<<"Trzecia III: " << trzecia << endl; // Trzecia III: 2, 4, 6, 4, 6, 3, 5
  cout<<"Niepowtarzalna: " << niepowtarzalna<< endl; // Niepowtarzalna: 2, 4, 6, 3, 5

  for (Tablica::Iterator liczba = druga->poczatek(); liczba != druga->koniec(); ++liczba)
    *liczba = 0;
  *druga->koniec()=0;

  cout<<"Wyzerowana: "<<*druga<<endl; // Wyzerowana: 0, 0, 0, 0, 0, 0, 0
  
  delete pierwsza;
  delete druga;

  return 0;
}

/* oczekiwany wynik:
Pierwsza: 2, 4, 6
Druga: 2, 4, 6, 2, 3, 5   Pierwsza: 2, 4, 6
Druga II: 2, 4, 6, 2, 3, 5
Trzecia: 2, 4, 6, 2, 3, 5
trzecia II: 4, 2, 6, 2, 3, 5   Pierwsza: 2, 4
Bez szostki 4, 2, 2, 3, 5
Bez dwojek 4, 6, 3, 5
2, 4, 6
Trzecia III: 2, 4, 6, 4, 6, 3, 5
Niepowtarzalna: 2, 4, 6, 3, 5
Wyzerowana: 0, 0, 0, 0, 0, 0, 0
*/