#include "Map.h"
#include <string>

std::string print(bool exists) {
    return exists ? std::string("Znaleziono") : std::string("Nie znaleziono");
}


/// przeladowany operator do mnozenia stringow <str * int>(kopiuje dany string n razy)
const std::string operator*(const std::string str, int n) {
    std::string result = "";
    for (int i = 0; i < n; ++i)
        result += str;
        
    return result;
}

/// przeladowany operator do mnozenia stringow <int * str>(kopiuje dany string n razy)
const std::string operator*(int n, const std::string str) {
    return str*n;    
}