#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
using namespace ariel;


TEST_CASE("Player tests"){
    Player p1("Daniel");
    Player p2("Noam");
    CHECK_EQ(p2.num_of_cards, 26);
    p2.TopCard();
    CHECK_EQ(p2.num_of_cards, 25);
    for(int i = 0; i < 25; i++){
        CHECK_FALSE(p2.TopCard() == -1);
    }
    CHECK_EQ(p2.TopCard(), -1);
    p2.setCards(p1.cards);
    CHECK_FALSE(p2.stacksize() == 0);
    CHECK_FALSE(p1.cards == p2.cards); // Cards are objects and setCards only transfers the values
    p2.TopCard();
    CHECK_FALSE(p2.stacksize() == p1.stacksize());
    // CHECK_EQ(p1.num_of_cards, p2.num_of_cards);
    CHECK_FALSE(p2.TopCard() == -1);
    CHECK_FALSE(p2.num_of_cards == p1.num_of_cards);
    p1.num_of_cards = 0;
    CHECK_EQ(p1.TopCard(), -1);
    CHECK_EQ(p1.stacksize(), p1.num_of_cards);
    CHECK_FALSE(p2.name == p1.name);
}

TEST_CASE("Game tests"){
    Player p1("Daniel");
    Player p2("Noam");
    Game game(p1, p2);
    // CHECK_THROWS(game.printLog());
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printStats());
    // CHECK_FALSE(game.winner != p1.name && game.winner != p2.name);
    CHECK_FALSE(game.turn < 1);
    CHECK_EQ(game.turn, game.turns.size());
}

TEST_CASE(""){
    
}