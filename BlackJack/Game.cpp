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
    for (int i = 0; i < 2; ++i) //первая раздача - 2 карты всем
    {
        for (unique_ptr<Player>& player : m_Players)
            m_Deck->Deal(*player);
        m_Deck->Deal(*m_House);
    }
    m_House->FlipFirstCard(); //перевернуть первую карту рубашкой вверх

    bool play = true;
    int counter = 0;    //счетчик для кол-во активных игроков
    while (play)
    {
        cout << *this;  //вывод текущих карт
        counter = 0;
        
        for (unique_ptr<Player>& player : m_Players)
        {
            m_Deck->AdditionalCards(*player);   //запрос на доп карту
            if (!player->GetGameStatus())   //запрос текущего состояния 
                counter++;
        }
        if (counter == m_Players.capacity())
            play = false;
    }   

    //переворачиваем 1 карту дилера только при первом проходе, в остальных случаях запрашиваему ему карту
    if (!m_House->GetStatusFlipCard(0))
        m_House->FlipFirstCard();
    else
        m_Deck->AdditionalCards(*m_House);

    cout << *this;

    if (m_House->IsBusted())// все, кто остался в игре, побеждают
    {
        for (unique_ptr<Player>& player : m_Players)
            if (!player->IsBusted())
                player->Win();
    }
    else
    {
        // сравнивает суммы очков всех оставшихся игроков с суммой очков дилера
        for (unique_ptr<Player>& player : m_Players)
        {
            if (!player->IsBusted())
            {
                if (player->GetSumCard() > m_House->GetSumCard())
                    player->Win();
                else if (player->GetSumCard() < m_House->GetSumCard())
                    player->Lose();
                else
                    player->Push();
            }
        }
    }   
}

ostream& operator<<(ostream& out, const Game& game)
{
    system("cls");  //очистка экрана
    for (int i = 0; i < game.m_Players.capacity(); i++)
        out << *game.m_Players[i];
    out << *game.m_House;
    return out << endl;
}