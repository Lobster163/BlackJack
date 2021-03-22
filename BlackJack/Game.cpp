#include "include/Game.h"

Game::Game(const vector<string>& names)
{

    for (string name : names)
        m_Players.push_back(make_unique<Player>(name));
    
    int countKolod = 2;
    m_Deck = make_unique<Deck>(countKolod);
    m_Deck->Populate();
    m_Deck->Shuffle();
    m_House = make_unique<House>();
}

void Game::Play()
{    
    for (int i = 0; i < 2; ++i)
    {
        for (unique_ptr<Player>& player : m_Players)
            m_Deck->Deal(*player);
        m_Deck->Deal(*m_House);
    }
    m_House->FlipFirstCard();
    
    bool play = true;
    while (play)
    {
        //вывод текущих карт
        for (unique_ptr<Player>& player : m_Players)
            cout << *player;
        cout << *m_House;

        //запрос на доп карту
        for (unique_ptr<Player>& player : m_Players)
            m_Deck->AdditionalCards(*player);

        if (!m_House->GetStatusFlipCard(0))
            m_House->FlipFirstCard();
        else
            m_Deck->AdditionalCards(*m_House);


    }
}