#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/// <summary>
/// перечесление мастей карт
/// </summary>
enum class Suit
{
	spades = 0,
	clubs,
	diamonds,
	hearts
};

/// <summary>
/// перечесление значение карт
/// </summary>
enum class Rank
{
	_A = 1,
	_2,
	_3,
	_4,
	_5,
	_6,
	_7,
	_8,
	_9,
	_10,
	_V = 11,
	_Q = 12,
	_K = 13,
	
};

/// <summary>
///  ласс представле€ет обьект карту
/// </summary>
class Card
{
	private:
		Suit m_Suit;
		Rank m_Rank;
		bool m_IsFaceUp;
	public:
		Card() : m_Suit(Suit::clubs), m_Rank(Rank::_2), m_IsFaceUp(false) {};
		Card(Rank valueCard, Suit suit) : m_Rank(valueCard), m_Suit(suit), m_IsFaceUp(false) {};
		~Card(); 

		/// <summary>
		/// ѕереворачивает карту
		/// </summary>
		/// <returns>True - лицом к верху. False - лицом к низу</returns>
		bool Flip();

		/// <summary>
		/// ¬озврашает значение карты
		/// </summary>
		/// <returns>значение карты</returns>
		int GetValue() const;

		/// <summary>
		/// ¬озвращает название карты
		/// </summary>
		/// <returns>им€ карты</returns>
		string GetName() const;

		/// <summary>
		/// ¬озвращает масть карты
		/// </summary>
		/// <returns>масть карты</returns>
		string GetSuit() const;

		/// <summary>
		/// ¬озвращает состо€ние карты
		/// </summary>
		/// <returns>True - лицом к верху. False - лицом к низу</returns>
		bool GetFlipStatus() const;


		/// <summary>
		/// перегрузка вывода дл€ класса
		/// </summary>
		/// <param name="out">выводной поток</param>
		/// <param name="card">ссылка на класс</param>
		/// <returns></returns>
		friend ostream& operator<<(ostream& out, const Card& card);
};