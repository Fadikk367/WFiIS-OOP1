#include "People.h"

Person::Person(std::string name, Gender gender, bool doNeedHaircut) 
    : 
    _name(name), 
    _gender(gender),
    _doNeedHaircut(doNeedHaircut)
    {}

void Person::haircut() {
    if (!_doNeedHaircut) {
        std::cout << "!!! Juz obciet(y/a) !!!" << std::endl;
        return;
    }
    _doNeedHaircut = false;
}

Gender Person::getGender() const {
    return _gender;
}

std::string Person::name() const {
    return _name;
}

bool Person::getDoNeedHaircut() const {
    return _doNeedHaircut;
}
    


Man::Man(std::string name, bool doNeedHaircut, bool doNeedShave, Gender gender) 
    : 
    Person(name, gender, doNeedHaircut),
    _doNeedShave(doNeedShave) 
    {}

void Man::shave() {
    if (!_doNeedShave) {
        std::cout << "\n!!! Juz ogolony !!!";
        return;
    }
    _doNeedShave = false;
}

bool Man::getDoNeedShave() const {
    return _doNeedShave;
}

void Man::print() const {
    std::cout << _name << (_doNeedHaircut ? " nieobciety" : " obciety") << " i " << (_doNeedShave ? " nieogolony" : " ogolony") << std::endl;
}

Man::~Man() {
    std::cout << "\n" << _name << (_doNeedHaircut ? " nieobciety" : " obciety") << " i " << (_doNeedShave ? " nieogolony" : " ogolony") << " idzie na piwko";
}
    


Woman::Woman(std::string name, bool doNeedHaircut, bool doNeedMakeup,  Gender gender) 
    : Person(name, gender, doNeedHaircut), 
    _doNeedMakeup(doNeedMakeup) 
    {}

void Woman::makeup() {
    if (!_doNeedMakeup) {
        std::cout << "!!! Juz pomalowana !!!" << std::endl;
        return;
    }
    _doNeedMakeup = false;    
}

bool Woman::getDoNeedMakeup() const {
    return _doNeedMakeup;
}

void Woman::print() const {
    std::cout << _name << (_doNeedHaircut ? " nieobcieta" : " obcieta") << " i " << (_doNeedMakeup ? " niepomalowana" : " pomalowana") << std::endl;
}

Woman::~Woman() {
    std::cout << "\n" << _name << (_doNeedHaircut ? " nieobcieta" : " obcieta") << " i " << (_doNeedMakeup ? " niepomalowana" : " pomalowana") << " idzie na zakupy";
}
    
