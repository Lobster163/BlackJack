
#include "include/BlackJack.h"

int main()
{
    GenericPlayer* player1 = new GenericPlayer("user1", 18);

    player1->AddCard(new Card(Rank::_A, Suit::hearts));
    player1->AddCard(new Card(Rank::_10, Suit::diamonds));
    player1->AddCard(new Card(Rank::_K, Suit::diamonds));

    cout << "Cards in hand: " << endl;

    for (int i = 0; i < player1->GetCountCard(); ++i)
        cout << player1->GetNameCard(i) << " ";
    cout << endl;

    cout << "Count card = " << player1->GetCountCard() << endl;
    cout << "Sum card = " << player1->GetSumCard() << endl;

    cout << player1->GetNamePlayer() << endl;
    player1->Bust();

    delete player1;

    return 0;
}
