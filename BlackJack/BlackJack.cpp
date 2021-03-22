
#include "include/BlackJack.h"
#include "include/Deck.h"

int main()
{
    srand(time(0));
    int countKolod = 2;
    unique_ptr<Deck> deck = make_unique<Deck>(countKolod);
    for (int i = 0; i < countKolod * 52; i++)
        cout << *deck->GetCards()[i] << endl;

    cout << endl;
    deck->Shuffle();
    for (int i = 0; i < countKolod * 52; i++)
        cout << *deck->GetCards()[i] << endl;

    //deck->Populate();

    //vector<Player>Players;

    //for(int i=0; i<12;i++)
    //    Players.push_back(Player("Alex_"+to_string(i)));

    //for (int pl = 0; pl < Players.size(); pl++)
    //    for (int i = 1; i < 3; i++)
    //    {
    //        int randCard = rand() % 12 + 1;
    //        int randMast = rand() % 3 + 1;
    //        Players[pl].AddCard(new Card((Rank)randCard, (Suit)randMast));
    //        Players[pl].FlipCard(i - 1);
    //        
    //    }
    //
    //for (int i=0; i<Players.size();i++)
    //    cout << "Count card on " << Players[i].GetNamePlayer() << " = " << Players[i].GetCountCard() << endl;

    //cout << endl;

    //if (Players[0].IsHitting())
    //{
    //    //если надо еще карту - добавляем
    //    Players[0].AddCard(new Card(Rank(rand() % 12 + 1), Suit(rand() % 3 + 1)));
    //    Players[0].FlipCard(Players[0].GetCountCard()-1);
    //}

    //cout << endl;

    //for (int pl = 0; pl < Players.size(); pl++)
    //    cout << Players[pl];

    return 0;
}
