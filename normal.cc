#include "normal.h"

void Normal::greet() const {
    std::cout << "Hi, I am Normal Person " << this->getName() << ". I am " << this->getAge() << " years old and I live in " << address << std::endl;
}
