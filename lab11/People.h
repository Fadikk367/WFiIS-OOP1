#pragma once

#include <iostream>
#include <string>

enum class Gender { MAN, WOMAN };

class Person {
    public:
    
    Person(std::string name, Gender, bool doNeedHaircut = true);
    void haircut();
    Gender getGender() const;
    std::string name() const;
    bool getDoNeedHaircut() const;
    virtual void print() const = 0;
    virtual ~Person() = default; 
    
    protected:

    std::string _name;
    Gender _gender;
    bool _doNeedHaircut;
};


class Man : public Person {
    public:

    Man(std::string name, bool doNeedHaircut = true, bool doNeedShave = true, Gender gender = Gender::MAN);
    void shave();
    bool getDoNeedShave() const;
    void print() const override;
    ~Man() override;
    
    protected:

    bool _doNeedShave;
};


class Woman : public Person {
    public:

    Woman(std::string name, bool doNeedHaircut = true, bool doNeedMakeup = true, Gender gender = Gender::WOMAN);
    void makeup();
    bool getDoNeedMakeup() const;
    void print() const override;
    ~Woman() override;
    
    protected:
    
    bool _doNeedMakeup;
};