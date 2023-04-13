namespace ariel{
    class Card;
}
using namespace std;
#ifndef card_hpp
#define card_hpp
class ariel::Card{
    public:
        int value;
        string type; // Hearts, Clubs, etc.
        
        Card(){
            value = 12; // Queen
            type = "Hearts";
        }
        Card(int other_value, string other_type){
            value = other_value;
            type = other_type;
        }
};
#endif