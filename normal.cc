#include "normal.h"

Normal::Normal(const std::string& name, int age, const std::string& address)
        : Person(name, age), address(address) {}

// Copy constructor directly use the base class copy constructor
Normal::Normal(const Normal& other) : Person(other), address(other.address) {
    std::cout << "Copy constructor called for Normal Person " << this->getName() << std::endl;
}

void Normal::greet() const {
    std::cout << "Hi, I am Normal Person " << this->getName() << ". I am " << this->getAge() << " years old and I live in " << address << std::boolalpha << ". I am rich " << this->isRich << std::noboolalpha << std::endl;
}
