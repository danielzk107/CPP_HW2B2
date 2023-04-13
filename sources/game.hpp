
#include <list>
#include <utility>
#include <string>
#include "player.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;


namespace ariel{
    class Game;
}

class ariel::Game{
    public:
        size_t turn;
        Player *p1, *p2;
        std::string winner;
        std::vector<std::pair<Card, Card>> turns;
        std::vector<int> results; // Used to keep track of the result of every turn.
        int num_of_draws;
        int carry_from_draw; // Each draw requires the players to place more cards upside down. This variable will count the number of upside down cards required.

        Game(Player &other_p1, Player &other_p2);

        void playTurn();
        void playAll();// Calls playTurn in a while loop until one of the players reaches 0 cards
        void printWiner(); // Typo; Should be winner
        void printLastTurn(); // Prints turn.top and the result of it.
        void printLog();
        void printStats();
        void ShuffleDeck(Player *p1, Player *p2);
        int gameResult(); // Checks if the game has ended and returns the winner (-1 if game hasnt ended and 0 if game ended in a draw)


};