#pragma once
#include <string>

class Person {
public:
    Person();
    Person(const std::string& name, int age);
    ~Person();

    std::string getName() const;
    int getAge() const;

    void setName(const std::string& name);
    void setAge(int age);
private:
    std::string name;
    int age;
};
