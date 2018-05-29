#include "IllegalCharException.h"
using namespace std;

char IllegalCharException::theChar() const{
    return this->ch;
}