#include "IllegalCoordinateException.h"
#include <string>
using namespace std;

//  IllegalCoordinateException::IllegalCoordinateException(const Coordinate& c){
//    this->coor=new Coordinate(c);
//}

string IllegalCoordinateException::theCoordinate() const{
    return ""+to_string(this->coor.x) + "," + to_string(this->coor.y);
} 

//~IllegalCoordinateException::IllegalCoordinateException(){
//    delete(this);
//}

