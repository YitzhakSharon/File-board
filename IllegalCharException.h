#pragma once
#include <string>
#include <iostream>
#include <exception>
using namespace std;

class IllegalCharException{
    public:
        char ch;
        IllegalCharException(const char& c): ch(c){};
        char theChar() const;
};
