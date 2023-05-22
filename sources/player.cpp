#include "player.hpp"
using namespace ariel;

Player::Player()
{
    name = "No Name";
    num_of_cards = 0;
    cardswon = 0;
}
Player::Player(std::string other_name)
{
    name = other_name;
    num_of_cards = 25; // Used more as a pointer than a representation of amount of cards
    for (size_t i = 0; i < 25; i++)
    {
        cards[i] = Card(i%13, "Default Value");
    }
    
    cardswon = 0;
}
int Player::stacksize()
{
    return num_of_cards + 1;
}
int Player::cardesTaken()
{
    return cardswon;
}
int Player::TopCard()
{ // This function returns the card at the top of the deck
    if (num_of_cards < 0)
    {
        return -1;
    }
    last_played = cards[num_of_cards];
    --num_of_cards;
    return last_played.value;
}
void Player::setCards(Card other[52])
{
    int new_num_of_cards = -1;
    for (int i = 0; i < 52; i++)
    {
        cards[i] = other[i];
        if (other[i].value > 0)
        {
            new_num_of_cards++;
        }
    }
    num_of_cards = new_num_of_cards;
}
