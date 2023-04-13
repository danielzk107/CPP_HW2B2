#include <string>
#include "card.hpp"
#include <iostream>
using namespace std;
namespace ariel{
    class Player;
}
#ifndef player_hpp
#define player_hpp
class ariel::Player{
    public:
        std::string name;
        int num_of_cards;
        int cardswon;
        Card last_played;
        Card cards[52];
        Card cardswon_arr[52];

        Player();

        Player(std::string other_name);
        int stacksize();
        int cardesTaken();
        int TopCard();
        void setCards(Card other[52]);
};
#endif