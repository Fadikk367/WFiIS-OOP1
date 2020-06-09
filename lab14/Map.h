#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <exception>

/// Szablon klasy reprezentujacej tablice asocjacyjna
template <typename K, typename V>
class Map {

    public:

    Map() = default;
  
    /// szablon metody dodajacej do mapy nowy element (pare klucz - wartosc)
    void insert(const K key, const V value);
  
    /// szablon metody wypisujaca wszytskie elemnty mapy, poprzedzajac kazdy z nich podanym jako argument prefixem
    void print(std::string prefix) const;
    
    /// szablon metody sprawdzajacej czy w mapie znajduje sie element o podanym kluczu
    bool contains(const K key) const;
  
    /// szablon przeladowanego operatora "[]", daje dostep do elementow mapy w notacji tablicowej, pozwala na modyfikacje
    V& operator[](const K& key);
    
    /// szablon przeladowanego operatora "[]", daje dostep do elementow mapy w notacji tablicowej, NIE pozwala na modyfikacje
    const V& operator[](const K& key) const;
    
    ~Map() = default;
     
     
    protected:
    
    /// vektor sluzacy jako kontener dla naszej mapy
    std::vector<std::pair<K, V>> m_map;
    
};


template <typename K, typename V>
void Map<K, V>::insert(const K key, const V value) {
    //std::cout << std::hash<K>{}(key) << std::endl;
    m_map.emplace_back(std::pair<K, V>(key, value));
}

template <typename K, typename V>
void Map<K, V>::print(std::string prefix) const {
    for (const auto& node : m_map)
        std::cout << "--- "<< prefix << " --- klucz: " << node.first << " wartosc: " << node.second << std::endl;
}

template <typename K, typename V>
bool Map<K, V>::contains(const K key) const {
    auto iter = std::find_if(std::begin(m_map), std::end(m_map), [key](const std::pair<K, V>& node) -> bool {
        return (node.first == key ? true : false);
    });
    return iter < std::end(m_map);
}

template <typename K, typename V>
V& Map<K, V>::operator[](const K& key) {
    auto iter = std::find_if(std::begin(m_map), std::end(m_map), [key](const std::pair<K, V>& node) -> bool {
        return (node.first == key ? true : false);
    });
    if (iter >= std::end(m_map)) {
        this->insert(key, V());
        return (std::end(m_map) - 1)->second;
    }
    return iter->second;
}

template <typename K, typename V>
const V& Map<K, V>::operator[](const K& key) const {
    auto iter = std::find_if(std::begin(m_map), std::end(m_map), [key](const std::pair<K, V>& node) -> bool {
        return (node.first == key ? true : false);
    });
    if (iter == std::end(m_map)) {
        throw std::invalid_argument("Niewlasciwy klucz");
    }
    return iter->second;
}
