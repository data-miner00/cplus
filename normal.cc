#include "normal.h"

Normal::Normal(const std::string& name, int age, const std::string& address)
        : Person(name, age), address(address) {}

void Normal::greet() const {
    std::cout << "Hi, I am Normal Person " << this->getName() << ". I am " << this->getAge() << " years old and I live in " << address << std::boolalpha << ". I am rich " << this->isRich << std::noboolalpha << std::endl;
}
