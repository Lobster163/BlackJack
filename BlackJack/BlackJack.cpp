
#include "include/BlackJack.h"

int main()
{
    srand((unsigned int)(time(0)));
    
    cout << "\t\tWelcome to Blackjack!\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }

    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    // игровой цикл
    unique_ptr<Game> aGame;
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame = make_unique<Game>(names);
        aGame->Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
        aGame.reset();
    }

    return 0;
}
