#include "card.hpp"
#include <string>
using namespace ariel;

Card::Card(){
    value = 0;
    type = "None";
}
Card::Card(int other_value, string other_type){
    value = other_value;
    type = other_type;
}
int Card::Winning(Card other){
    if(value == 1){ // Ace case
        if(other.value ==2){
            return -1;
        }
        if(other.value == 1){
            return 0;
        }
        return 1;
    }
    if(value > other.value){
        return 1;
    }
    if(value < other.value){
        return -1;
    }
    return 0;
}
