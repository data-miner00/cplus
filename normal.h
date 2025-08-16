#pragma once
#include "person.h"

class Normal : public Person {
public:
    using Person::Person; // Inherit constructors from Person
    Normal(const std::string& name, int age, const std::string& address);
    Normal(const Normal& other); // copy constructor

    void greet() const override;

private:
    std::string address;
};
