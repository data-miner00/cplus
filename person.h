#pragma once
#include <string>
#include <iostream>

class Person {
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
public:
    Person();
    Person(const std::string& name, int age);
    ~Person();
    Person(const Person& other); // copy constructor

    std::string getName() const;
    int getAge() const;

    void setName(const std::string& name);
    void setAge(int age);

    virtual void greet() const;
    void printAddress();
protected:
    bool isRich;
private:
    std::string name;
    int age;
};
