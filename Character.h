#include "IllegalCharException.h"
class Character{
private:
    char c;
public:
    Character(){
        this->c='.';
    };
    Character(char t){
        if(t=='.' || t=='X' || t=='O')
            this->c=t;
        else{
            this->c='.';
            throw IllegalCharException(t);
        }
    };
    operator char() const{
        return this->c;
    };
    
        


};