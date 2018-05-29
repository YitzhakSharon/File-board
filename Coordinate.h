#pragma once
#include <iostream>
using namespace std;

class Coordinate{
   friend class Board;
    public:
        uint x;
        uint y;
    public:
        Coordinate(): x(0),y(0){};
        Coordinate(int x1 , int y1): x(uint(x1)), y(uint(y1)){};
        Coordinate(uint x1 , uint y1): x(x1), y(y1){};
        Coordinate(const Coordinate& other) {
            this->x=other.x;
            this->y=other.y;
        };

};
