#pragma once
#include "person.h"

class Normal : public Person {
public:
    Normal(const std::string& name, int age, const std::string& address);

    void greet() const override;

private:
    std::string address;
};
