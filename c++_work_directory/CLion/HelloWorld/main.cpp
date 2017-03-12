#include <iostream>
#include <algorithm> // std::swap
#include <cstddef>   // size_t
#include <cstring>   // strlen, strcpy
#include <stdio.h>
#include <string.h>

struct String {
    String(const char *str = "");
    String(size_t n, char c);
    String(const String &other);
    ~String();

    /* Реализуйте оператор присваивания */
    String &operator=(const String &other) {
        if(this != &other) {
            delete [] str;
            str = new char[other.size+1];
            strcpy(str, other.str);
            size = other.size;
        }
        return *this;
    }

    void append(const String &other);

    size_t size;
    char *str;
};

int main() {

    String ;
    return 0;
};