#include <ios>
#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cctype>
#include "bubble_sort.h"

typedef std::string text_t;
using number_t = int;

template <typename T>
T getSelf(T value) {
    return value;
}

constexpr int get_value() {
    return 42;
}

void play_with_limits() {
    std::cout << "int min: " << std::numeric_limits<int>::min() << '\n';
    std::cout << "int max: " << std::numeric_limits<int>::max() << '\n';
    std::cout << "double min: " << std::numeric_limits<double>::min() << '\n';
    std::cout << "double max: " << std::numeric_limits<double>::max() << '\n';
}

void get_array_size() {
    int array[] = { 1, 2, 3, 4, 5 };
    std::cout << "Size of array: " << sizeof(array) / sizeof(array[0]) << '\n';
    std::cout << "Size of array: " << std::size(array) << '\n';
}

void print_cstring() {
    char message[5] { 'H', 'i', '!', '\0' }; // because have 5 space, non-initialized character will automatically be '\0'
    std::cout << message << '\n';
}

void playing_with_pointers() {
    int value = 42;
    int* ptr = &value;

    std::cout << "Value: " << value << '\n';
    std::cout << "Pointer: " << ptr << '\n';
    std::cout << "Dereferenced pointer: " << *ptr << '\n';

    // Pointer arithmetic
    int arr[] = { 1, 2, 3, 4, 5 };
    int* arr_ptr = arr;

    for (int i = 0; i < 5; ++i) {
        std::cout << *(arr_ptr + i) << ' ';
    }
    std::cout << '\n';

    int int_var {43};
    int *p_int_var { &int_var };

    std::cout << "The value for p_int_var is: " << *p_int_var << '\n';

    // If we use {} to initialize a pointer, it will be initialized to nullptr
    int* p_nullptr {};

    // Explicitly initializing a pointer to nullptr
    int* p_explicit_nullptr { nullptr };
}

void allocate_value_on_heap() {
    // Allocating an integer on the heap
    int* heap_value = new int(42);
    std::cout << "Value allocated on heap: " << *heap_value << '\n';

    // Don't forget to free the memory
    // Do not call delete multiple times!
    delete heap_value;
    heap_value = nullptr;
}

void dynamic_arrays() {
    size_t size = 5;

    int* dynamic_array = new int[size];
    for (size_t i = 0; i < size; ++i) {
        dynamic_array[i] = static_cast<int>(i * 10);
    }

    int* safe_dynamic_array { new(std::nothrow) int[size]{} }; // All initialized to 0
    int* safe_initialized_dynamic_array { new(std::nothrow) int[size]{1, 2, 3, 4, 5} };

    if (safe_initialized_dynamic_array) {
        for (size_t i {}; i < size; ++i) {
            // Print using array bracket operator or pointer arithmetic
            std::cout << "Value: " << safe_initialized_dynamic_array[i] << '-' << *(safe_initialized_dynamic_array + i) << '\n';
        }
    }

    delete[] dynamic_array;
    dynamic_array = nullptr;

    delete[] safe_dynamic_array;
    safe_dynamic_array = nullptr;

    delete[] safe_initialized_dynamic_array;
    safe_initialized_dynamic_array = nullptr;
}

void references() {
    int value = 42;
    int& ref = value; // Reference to value
    int* const ref2 = &value; // Pointer to value, same as using a reference

    std::cout << "Value: " << value << '\n';
    std::cout << "Reference: " << ref << '\n';
    std::cout << "Const Ptr: " << *ref2 << '\n';

    ref = 100; // Changing the reference also changes the original value
    std::cout << "New Value: " << value << '\n';

    *ref2 = 200;
    std::cout << "New Value after pointer change: " << value << '\n';

    // Immutable references, cannot be updated or reassigned
    const int& const_ref = value;
    const int* const const_ptr = &value;
}

void string_functions() {
    std::string str = "Hello, World!";
    std::cout << std::boolalpha;
    std::cout << "String length: " << str.length() << '\n';
    std::cout << "First character: " << str[0] << '\n';
    std::cout << "Substring (0, 5): " << str.substr(0, 5) << '\n';
    std::cout << "Find 'World': " << str.find("World") << '\n';
    std::cout << "Replace 'World' with 'C++': " << str.replace(str.find("World"), 5, "C++") << '\n';
    std::cout << "Is 'C' alphanumeric? " << std::isalnum('C') << '\n';
    std::cout << "Is ' ' blank? " << std::isblank(' ') << '\n';
    std::cout << "Is '1' a digit? " << std::isdigit('1') << '\n';
    std::cout << "Is 'A' cntrl? " << std::iscntrl('A') << '\n';
    std::cout << std::noboolalpha;
}

void cstrings() {
    const char cstr[] = "Hello, C-style string!";

    // CString decayed into pointer
    const char* decayed_cstr = "Hello, decayed C-style string!";
    std::cout << "C-style string: " << cstr << '\n';

    // Using strlen to get the length of a C-style string
    size_t length = std::strlen(cstr);
    std::cout << "Length of C-style string: " << length << '\n';

    // Using strcpy to copy a C-style string
    char buffer[50];
    strcpy_s(buffer, cstr);
    std::cout << "Copied C-style string: " << buffer << '\n';

    // Using strcat to concatenate C-style strings
    strcat_s(buffer, " How are you?");
    std::cout << "Concatenated C-style string: " << buffer << '\n';

    // Count occurrence of character
    char target = 'A';
    const char* result = decayed_cstr;
    int iterations{};

    while ((result = std::strchr(result, target)) != nullptr) {
        std::cout << "Found '" << target << "' at position: " << (result - decayed_cstr) << '\n';
        result++; // Move to the next character
        iterations++;
    }

    // Find last occurrence
    const char* output = std::strrchr(decayed_cstr, target);
    if (output) {
        std::cout << "Last occurrence of '" << target << "' at position: " << (output - decayed_cstr) << '\n';
    } else {
        std::cout << "Character '" << target << "' not found in the string.\n";
    }

    // Concat string
    char dest[50] = "Hello, ";
    char src[50] = "World!";

    std::cout << strcat_s(dest, src) << '\n';
    std::cout << "Length of concatenated string: " << std::strlen(dest) << '\n';
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
    number_t* persist = new int;
    *persist = 33;
    delete persist;

    // template usage
    std::cout << getSelf(53) << '\n';

    int int_default {};
    std::cout << int_default << '\n';

    int brance_init(500);
    std::cout << brance_init << '\n';

    constexpr int value = get_value();
    std::cout << value << '\n';

    play_with_limits();

    for (unsigned int i{}; i < 3; ++i) {
        std::cout << "Printing " << i << '\n';
    }

    get_array_size();
    print_cstring();
    playing_with_pointers();
    allocate_value_on_heap();
    dynamic_arrays();
    references();
    string_functions();
    cstrings();

    return 0;
}
