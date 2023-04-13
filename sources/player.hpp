#include <string>
#include "card.hpp"
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

        Player(){
            name = "No Name";
            num_of_cards = 0;
            cardswon = 0;
        }

        Player(std::string other_name){
            name = other_name;
            num_of_cards = 26;
            cardswon = 0;
        }
        int stacksize(){
            return num_of_cards;
        }
        int cardesTaken(){
            return cardswon;
        }
        int TopCard(){ // This function returns the card at the top of the deck
            if(num_of_cards <= 0){
                return -1;
            }
            --num_of_cards;
            // return cards[num_of_cards+1].value;
            return 7;
        }
        void setCards(Card other[52]){
            int new_num_of_cards = 0;
            for(int i=0; i< 52; i++){
                cards[i] = other[i];
                if(other[i].value > 0){
                    new_num_of_cards++;
                }
            }
            num_of_cards = new_num_of_cards;
        }


};
#endif