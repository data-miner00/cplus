#pragma once
#include "person.h"

class Abnormal : protected Person { // public members in Person are now protected
public:
    Abnormal(const std::string& name, int age, const std::string& condition)
        : Person(name, age), condition(condition) {}

    using Person::greet; // Resurrect the greet method that is inherited protectedly
private:
    std::string condition;
};
