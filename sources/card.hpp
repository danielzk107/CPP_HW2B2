namespace ariel{
    class Card;
}
#include <string>
using namespace std;
#ifndef card_hpp
#define card_hpp
class ariel::Card{
    public:
        int value;
        string type; // Hearts, Clubs, etc.
        
        Card();
        Card(int other_value, string other_type);
        int Winning(Card other); // Checking if this card beats another, 1 for victory, -1 for defeat, 0 for draw 
};
#endif