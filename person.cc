#include "person.h"

Person::Person() = default;

Person::Person(const std::string& name, int age) : name(name), age(age) {}

Person::~Person() = default;

std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

void Person::setName(const std::string& name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::printAddress() {
    std::cout << "Address of this object: " << this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "Person(Name: " << person.getName() << ", Age: " << person.getAge() << ")";
    return os;
}

void Person::greet() const {
    std::cout << "Hello, my name is " << name << " and I am " << age << " years old." << std::endl;
}
