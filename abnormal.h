#pragma once
#include "person.h"

class Abnormal : protected Person { // public members in Person are now protected
public:
    using Person::Person; // Inherit constructors from Person
    Abnormal(const std::string& name, int age, const std::string& condition)
        : Person(name, age), condition(condition) {}

    using Person::greet; // Resurrect the greet method that is inherited protectedly
private:
    std::string condition;
};
