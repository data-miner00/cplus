#include <iostream>
#include <cstdlib>
#include <string>
#include "bubble_sort.h"

typedef std::string text_t;
using number_t = int;

template <typename T>
T getSelf(T value) {
    return value;
}


int main(int argc, char** argv) {
    text_t hello = "hello, world";
    std::cout << hello << std::endl;

    // Sorting array
    int array[] = { 83, 123, 4, 45, 8, 2, 95, 18, 54 };
    bubble_sort(array, sizeof(array)/sizeof(int));

    for (auto element : array) {
         std::cout << element << ' ';
    }

    std::cout << '\n';

    // Pointers
    text_t* addr = &hello;
    text_t* invalid = nullptr;

    // Heap alloc
    int* persist = new int;
    *persist = 33;
    delete persist;

    // template usage
    std::cout << getSelf(53) << '\n';

    int int_default {};
    std::cout << int_default << '\n';

    int brance_init(500);
    std::cout << brance_init << '\n';

    return 0;
}
