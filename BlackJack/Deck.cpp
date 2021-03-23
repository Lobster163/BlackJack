#include "include/Deck.h"


Deck::Deck(int countKolod)
{
    assert(countKolod);
    m_countKolod = countKolod;
    GetCards().reserve(countKolod * 52);
    Populate();
}

void Deck::Populate()
{
    ClearHand();    
    for (int k = 0; k < m_countKolod; ++k)
        for (int m = (int)Suit::spades; m <= (int)Suit::hearts; m++)
        {
            for (int r = (int)Rank::_A; r <= (int)Rank::_K; ++r)
            {
                AddCard( 
                    new Card(
                        (Rank)r, 
                        (Suit)m 
                    ));
            }
        }
}

void Deck::Shuffle() 
{
    random_shuffle(GetCards().begin(), GetCards().end());
}

void Deck::Deal(Hand& aHand)
{
    if (!GetCards().empty())
    {
        aHand.AddCard(GetCards().back());
        GetCards().pop_back();
    }
    else
        cout << "koloda is empty";
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
    //если нету перебора и игрок хочет карту
    if (!aGenericPlayer.IsBusted() && aGenericPlayer.GetGameStatus())
        if (aGenericPlayer.IsHitting())
        {
            Deal(aGenericPlayer);
        }
}