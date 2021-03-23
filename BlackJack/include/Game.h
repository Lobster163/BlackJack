#pragma once
#include "Deck.h"
#include "House.h"
#include "Player.h"

class Game
{
	private:
		unique_ptr<Deck> m_Deck;
		unique_ptr<House> m_House;
		vector<unique_ptr<Player>> m_Players;

	public:
		Game(const vector<string>& names);
		~Game() {};

		/// <summary>
		/// начала игры
		/// </summary>
		void Play();

		friend ostream& operator<<(ostream& out, const Game& game);

};
