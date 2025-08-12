#pragma once
#include <string>
#include <iostream>

class Person {
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
public:
    Person();
    Person(const std::string& name, int age);
    ~Person();

    std::string getName() const;
    int getAge() const;

    void setName(const std::string& name);
    void setAge(int age);

    void printAddress();
private:
    std::string name;
    int age;
};
