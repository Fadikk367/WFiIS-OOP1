/* Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał
   a wynik jego działania był taki sam, jak podany na końcu tego pliku.

   Należy zdefiniować klasę umożliwiającą możliwość używania w kodzie 
   angielskiego i polskiego zapisu liczb dziesietnych, 
   tzn. przy użyciu kropki lub przecinka jako separatora miejsc dziesiętnych. 
   Można założyć, że cyfra na miejscu dziesietnym jest różna od zera.

   Proszę zdefiniować również klasę ComplexNumber reprezentującą liczbę zespoloną,
   wraz z wykorzystywanymi w tym programie operatorami.

 * Proszę zadbać o dobre zarządzanie pamiecią.
   Czas na rozwiązanie zadania do 13:00, bo możemy sobie na to pozwolić + 45 min dla spóźnialskich.
   W tym czasie można zadawać ew. pytania za pomocą chatroomu na górze w seksji wspólnej.

 * Proszę pamiętać o dokumentacji kodu.
 * Napisz Makefile albo skonfiguruj plik konfiguracyjny cmake tak, aby:
   - plikiem wynikowym był main
   - program kompilował się z flagami -Wall -pedantic.
   - były zdefiniowane cele użytkownika run, clean, check oraz all (main+run)

 * Kody źródłowe powinny znajdować się w katalogu nazwisko_lab4 
 * do którego nikt oprócz właściciela nie ma praw dostępu.
 * UWAGA! Wysyłamy spakowany katalog, nie oddzielne pliki!!!!!!
 * Wcześniej KASUJEMY niepotrzebne pliki.
 */


#include "numbers.h"
#include "complexNumber.h"
#include <iostream>

int main ()
{
  using namespace std;

  const float numEnglish_1 = ((english)1.2);
  const float numPolish_1 = ((polish)2,3);
  const float numEnglish_2 = (english)1.342;
  const float numPolish_2 = ((polish)2,789);
  cout<<numEnglish_1<<" "<<numPolish_1<<" "<<numEnglish_2<<" "<<numPolish_2<<"\n";

  ComplexNumber staticFirst (1, 2);
  cout<<staticFirst<<"\n";

  {
    ComplexNumber staticTmp (2, 3);
    ComplexNumber* dynamicTmp1 = new ComplexNumber (10, 11);

    cout<<staticTmp<<" "<<*dynamicTmp1<<"\n";
  } 

  ComplexNumber staticSecond (4, 5);
  ComplexNumber* dynamicSecond = new ComplexNumber (12, 13);
  ComplexNumber* dynamidThird = new ComplexNumber (14, 15);

  cout<<staticSecond<<" "<<*dynamicSecond<<"\n";

  delete dynamicSecond;

  cout<<staticFirst<<" "<<staticSecond<<"\n";

  return 0;
}
/* oczekiwany wynik 
1.2 2.3 1.342 2.789
Constructing 1+2i
1+2i
Constructing 2+3i
Constructing 10+11i
2+3i 10+11i
Deleting: 2+3i
Constructing 4+5i
Constructing 12+13i
Constructing 14+15i
4+5i 12+13i
Deleting: 12+13i
1+2i 4+5i
Deleting: 4+5i
Deleting: 1+2i
Deleting: 10+11i
Deleting: 14+15i
*/

