#include "game.hpp"
using namespace ariel;

Game::Game(Player &other_p1, Player &other_p2)
{
    p1 = &other_p1;
    p2 = &other_p2;
    turn = 0; // Used as index, and therefor will only get a legal value when turns is initialized.
    num_of_draws = 0;
    carry_from_draw = 0;
    winner = "The game is not over yet.";
    std::vector<std::pair<Card, Card>> turns{};
    std::vector<int> results; // Used to keep track of the result of every turn.
    ShuffleDeck(p1, p2);
}
void Game::playTurn()
{
    for (int i = 0; i < carry_from_draw / 2; i++) // Drawing cards upside down as the last turn was a draw.
    {
        if (p1->stacksize() > 1)
        {
            p1->TopCard();
            p2->TopCard();
            turns.push_back(std::pair<Card, Card>(p1->last_played, p2->last_played));
            turn++;
            results.push_back(-1);
        }
    }
    p1->TopCard();
    p2->TopCard();
    turns.push_back(std::pair<Card, Card>(p1->last_played, p2->last_played));
    turn++;
    if (p1->last_played.Winning(p2->last_played) == 1)
    {
        if (p2->last_played.value == 1)
        {
            if (p1->last_played.value == 2)
            { // P1 wins
                p1->cardswon_arr[p1->cardswon] = turns.at(turn - 1).first;
                p1->cardswon_arr[p1->cardswon + 1] = turns.at(turn - 1).second;
                p1->cardswon += 2 + carry_from_draw*2;
                results.push_back(1);
                carry_from_draw = 0; // Resetting the number of consecutive draws
            }
            else
            { // P2 wins
                p2->cardswon_arr[p2->cardswon] = turns.at(turn - 1).first;
                p2->cardswon_arr[p2->cardswon + 1] = turns.at(turn - 1).second;
                p2->cardswon += 2 + carry_from_draw*2;
                results.push_back(2);
                carry_from_draw = 0; // Resetting the number of consecutive draws
            }
        }
        else
        { // P1 wins
            p1->cardswon_arr[p1->cardswon] = turns.at(turn - 1).first;
            p1->cardswon_arr[p1->cardswon + 1] = turns.at(turn - 1).second;
            p1->cardswon += 2 + carry_from_draw*2;
            results.push_back(1);
            carry_from_draw = 0; // Resetting the number of consecutive draws
        }
    }
    else if (p1->last_played.Winning(p2->last_played) == 0)
    {
        if (turn == 25)
        {
            size_t index = turn -1;
            while (index >= 0 && (results[index] == 0 || results[index] == -1))
            {
                p1->cardswon_arr[p1->cardswon] = turns.at(index - 1).first;
                p2->cardswon_arr[p2->cardswon + 1] = turns.at(index - 1).second;
                p1->cardswon += 1 * (turn - index + 1);
                p2->cardswon += 1 * (turn - index + 1);
                index--;
            }
            p1->cardswon++;
            p2->cardswon++;
        }
        if(carry_from_draw == 0){
            carry_from_draw = 2;
        }
        else{
            carry_from_draw = carry_from_draw * 2;
        }
        num_of_draws++;
        results.push_back(0);
    }
    else
    { // P2 wins
        p2->cardswon_arr[p2->cardswon] = turns.at(turn - 1).first;
        p2->cardswon_arr[p2->cardswon + 1] = turns.at(turn - 1).second;
        p2->cardswon += 2 + carry_from_draw*2;
        results.push_back(2);
        carry_from_draw = 0; // Resetting the number of consecutive draws
    }
    int res = gameResult();
    if (res != -1)
    {
        if (res == 0)
        {
            winner = "The game has ended in a draw.";
        }
        else if (res == 1)
        {
            winner = "The winner is " + p1->name;
        }
        else
        {
            winner = "The winner is " + p2->name;
        }
    }
}
void Game::playAll()
{
    while (p1->stacksize() > 0 && p2->stacksize() > 0)
    {
        playTurn();
    }
}
void Game::printLog()
{
    if (turns.size() < 1)
    {
        printf("Game not played\n");
    }
    for (size_t i = 0; i < turns.size(); i++)
    {
        if (results.at(i) != -1) // If results[i] == -1 the cards were placed upside down, for a 'dead' turn to continue the draw from last turn.
        {
            cout << p1->name << " played " << turns.at(i).first.value << " of " << turns.at(i).first.type << ", " << p2->name << " played " << turns.at(i).second.value << " of " << turns.at(i).second.type << ". ";

            if (results.at(i) == 1)
            {
                cout << p1->name << " wins." << endl;
            }
            else if (results.at(i) == 2)
            {
                cout << p2->name << " wins." << endl;
            }
            else
            {
                cout << "Draw." << endl;
            }
        }
    }
}
void Game::printWiner()
{
    cout << winner << endl;
} // Typo; Should be winner
void Game::printLastTurn()
{
    if (turns.size() < 1)
    {
        printf("The game has not yet started.\n");
        return;
    }
    cout << p1->name << " played " << turns.at(turn - 1).first.value << " of " << turns.at(turn - 1).first.type << ", " << p2->name << " played " << turns.at(turn - 1).second.value << " of " << turns.at(turn - 1).second.type << "." << endl;
    if (results.at(turn - 1) == 1)
    {
        cout << p1->name << " wins." << endl;
    }
    else if (results.at(turn - 1) == 2)
    {
        cout << p2->name << " wins." << endl;
    }
    else
    {
        cout << "Draw." << endl;
    }
}
void Game::printStats()
{
    printWiner();
    cout << "This game had " << num_of_draws << " draws, meaning " << (num_of_draws) * (100 / (float)(turn + 1)) << "\% of turns were draws." << endl;
    cout << p1->name << " has won " << p1->cardesTaken() << " cards, while " << p2->name << " has won " << p2->cardesTaken() << "." << endl;
}
void Game::ShuffleDeck(Player *p1, Player *p2) // Shuffles a deck and splits it between the two players
{
    srand((unsigned int)time(NULL)); // Setting a random seed to get different results each time
    Card cards[52];
    int count = 0;
    string types[4] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    for (int i = 1; i < 14; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cards[count] = Card(i, types[j]);
            count++;
        }
    }
    for (int j = 0; j < 3; j++) // Shuffling three times
    {
        for (int i = 0; i < 52; i++)
        {
            int newPlace = rand() % 52;
            Card temp = cards[newPlace];
            cards[newPlace] = cards[i];
            cards[i] = temp;
        }
    }
    Card p1Cards[52];
    Card p2Cards[52];
    for (int i = 0; i < 52; i++)
    {
        if (i < 26)
        {
            p1Cards[i] = cards[i];
            p2Cards[1 + 26] = Card();
        }
        else
        {
            p2Cards[i % 26] = cards[i];
            p1Cards[i] = Card();
        }
    }
    p1->setCards(p1Cards);
    p2->setCards(p2Cards);
}
int Game::gameResult()
{
    if (p1->num_of_cards > 0)
    { // Both players have the same amount of cards in the main deck, so this could be p2 as well
        return -1;
    }
    if (p1->cardesTaken() > p2->cardesTaken())
    {
        return 1;
    }
    if (p1->cardesTaken() < p2->cardesTaken())
    {
        return 2;
    }
    return 0;
}
