#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <vector>
#include <map>

#include "People.h"


class QKolejka {
    public:

    QKolejka() = default;
    
    void add(std::unique_ptr<Person> person);
    void print(std::string header) const;
    void haircut();
    void haircut(std::string name);
    void shave(std::string name);
    void countNames() const;
    std::vector<Woman*> getWoman() const;
    
    ~QKolejka() = default;
  
  protected:
    std::vector<std::unique_ptr<Person>> _queue;
    int _pivot{-1}; // index showing where is last women in the queue, if no women in queue pivot == -1

    bool _isReadyToLeaveTheQueue(int index) const;
};