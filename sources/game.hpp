
#include <list>
#include <utility>
#include <string>
#include "player.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;


namespace ariel{
    class Game;
}

class ariel::Game{
    public:
        int turn;
        std::list<std::pair<Card, Card>> turns;
        Player p1, p2;
        std::string winner;
        int num_of_draws;
        int carry_from_draw; // Each draw requires the players to place more cards upside down. This variable will count the number of upside down cards required.

        Game(Player other_p1, Player other_p2){
            p1 = other_p1;
            p2 = other_p2;
            turn = 0;
            num_of_draws = 0;
            winner = "No one";
            std::list<std::pair<Card, Card>> turns(0);
        }

        void playTurn(){
            turn ++;
            cout << p1.TopCard() << " , "; // Temporary
            cout << p2.TopCard() << endl; // Temporary
            turns.assign(1, std::pair<Card, Card>(Card(), Card()));
            // Compare p1.TopCard with p2.TopCard
        }
        void playAll(){
            // Calls playTurn in a while loop until one of the players reaches 0 cards
        }
        void printWiner(){ // Typo; Should be winner
            // printf("%s\n", winner);
        }
        void printLastTurn(){ 
            // Prints turn.top and the result of it.
        }
        void printLog(){
            // if(turns.size() < 1){
            //     throw errno;
            // }
            for(int i =0; i< turns.size(); i++){
                //print turns[i] and the result of it.
            }
        }
        void printStats(){
            // Go over turns to get the win rate, print num_of_draws
        }


};