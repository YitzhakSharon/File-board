#pragma once
#include <iostream>
#include "Character.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

using namespace std;

class Board{
    public:
        uint num;
        Character** board;
    public:
        Board(int num1):num(num1){
            Character** b = new Character*[this->num];
            for (int i = 0; i < this->num; i++)
                b[i] = new Character[num];

            for(int i=0; i<this->num; i++){
                for(int j=0; j<this->num; j++){
                    b[i][j]='.';
                }
            }
            this->board = b;
        };

        Board():num(0){
            Character** b = new Character*[this->num];
            for (int i = 0; i < this->num; i++)
                b[i] = new Character[num];

            for(int i=0; i<this->num; i++){
                for(int j=0; j<this->num; j++){
                    b[i][j]='.';
                }
            }
            this->board = b;
        };
        const int size() const;
        Board( const Board& b);
        Character& operator [] (Coordinate) const;
        void operator =(char) const;
        Board& operator = (const Board& b);
        ~Board();
        friend ostream& operator << (ostream& os,const Board& c);
        friend istream& operator >> (istream& is  ,Board& c);

};
