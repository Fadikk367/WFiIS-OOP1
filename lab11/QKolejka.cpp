#include "QKolejka.h"

void QKolejka::add(std::unique_ptr<Person> person) {
    if (person->getGender() == Gender::WOMAN) {
        _pivot++;
        _queue.insert(std::begin(_queue) + _pivot, std::move(person));
        return;
    }
    _queue.emplace_back(std::move(person));
}

bool QKolejka::_isReadyToLeaveTheQueue(int index) const {
    if (_queue[index]->getGender() == Gender::MAN) {
        Man* male = dynamic_cast<Man*> (_queue[index].get());
        if (male != nullptr) {
            if (!male->getDoNeedHaircut() && !male->getDoNeedShave()) return true;
        }
        return false;
    } else {
        Woman* female = dynamic_cast<Woman*> (_queue[index].get());
        if (female != nullptr) {
            if (!female->getDoNeedHaircut() && !female->getDoNeedMakeup()) return true;
        }
        return false;
    }
}

void QKolejka::print(std::string header) const {
    std::cout << "*** " << header << " ***" << std::endl;
    for (const auto& p : _queue)
        p->print();
}

void QKolejka::haircut() {
    _queue[0]->haircut();

    if (_isReadyToLeaveTheQueue(0)) 
        _queue.erase(std::begin(_queue));
    // if person who leaved was women we have to move pivot so that it will still show position of last women in our queue
    if (_pivot == 0) _pivot--;
}

void QKolejka::haircut(std::string name) {
    auto iter = std::find_if(std::begin(_queue), std::end(_queue), [name](std::unique_ptr<Person>& a) -> bool {
        return a.get()->name() == name ? true : false;
    });
    
    int index = std::distance(std::begin(_queue), iter);
    _queue[index]->haircut();

    if (_isReadyToLeaveTheQueue(index)) 
        _queue.erase(std::begin(_queue) + index);
    // if person who leaved was women we have to move pivot so that it will still show position of last women in our queue
    if (index <= _pivot) _pivot--;
}

void QKolejka::shave(std::string name) {
    auto iter = std::find_if(std::begin(_queue), std::end(_queue), [name](std::unique_ptr<Person>& a) -> bool {
        return a.get()->name() == name ? true : false;
    });
    
    int index = std::distance(std::begin(_queue), iter);
    (dynamic_cast<Man*> (_queue[index].get()))->shave();

    if (_isReadyToLeaveTheQueue(index)) 
        _queue.erase(std::begin(_queue) + index);
}

void QKolejka::countNames() const {
    std::map<std::string, int> countedNames;

    for (const auto& person : _queue)
        ++countedNames[person.get()->name()];

    for (const auto& pair : countedNames)
        std::cout << pair.first << ": " << pair.second << std::endl;
}

std::vector<Woman*> QKolejka::getWoman() const {
    std::vector<Woman*> result;
    for (const auto& person : _queue)
        if (person->getGender() == Gender::WOMAN) 
            result.emplace_back(dynamic_cast<Woman*> (person.get()));

    return result;
}