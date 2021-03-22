#pragma once
#include "GenericPlayer.h"

/// <summary>
/// класс доски игры
/// </summary>
class Deck : virtual public Hand
{
    private:
        int m_countKolod;
    public:
        Deck(int countKolod = 1);
        virtual ~Deck() {};

        /// <summary>
        /// создает пачку карт
        /// </summary>
        void Populate();

        /// <summary>
        /// тусуем карты
        /// </summary>
        void Shuffle();

        /// <summary>
        /// раздать 1 карту на руку
        /// </summary>
        /// <param name="aHand">ссылка на руку</param>        
        void Deal(Hand& aHand);

        /// <summary>
        /// раздает игроку доп карту, покпа он хочет их получать
        /// </summary>
        void AdditionalCards(GenericPlayer& aGenericPlayer);
};

