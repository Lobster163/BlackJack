#pragma once
#include "GenericPlayer.h"

/// <summary>
/// ����� ����� ����
/// </summary>
class Deck : virtual public Hand
{
    private:
        int m_countKolod;
    public:
        Deck(int countKolod = 1);
        virtual ~Deck() {};

        /// <summary>
        /// ������� ����� ����
        /// </summary>
        void Populate();

        /// <summary>
        /// ������ �����
        /// </summary>
        void Shuffle();

        /// <summary>
        /// ������� 1 ����� �� ����
        /// </summary>
        /// <param name="aHand">������ �� ����</param>        
        void Deal(Hand& aHand);

        /// <summary>
        /// ������� ������ ��� �����, ����� �� ����� �� ��������
        /// </summary>
        void AdditionalCards(GenericPlayer& aGenericPlayer);
};

