#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/// <summary>
/// ������������ ������ ����
/// </summary>
enum class Suit
{
	spades = 0,
	clubs,
	diamonds,
	hearts
};

/// <summary>
/// ������������ �������� ����
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
/// ����� ������������� ������ �����
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
		/// �������������� �����
		/// </summary>
		/// <returns>True - ����� � �����. False - ����� � ����</returns>
		bool Flip();

		/// <summary>
		/// ���������� �������� �����
		/// </summary>
		/// <returns>�������� �����</returns>
		int GetValue() const;

		/// <summary>
		/// ���������� �������� �����
		/// </summary>
		/// <returns>��� �����</returns>
		string GetName() const;

		/// <summary>
		/// ���������� ����� �����
		/// </summary>
		/// <returns>����� �����</returns>
		string GetSuit() const;

		/// <summary>
		/// ���������� ��������� �����
		/// </summary>
		/// <returns>True - ����� � �����. False - ����� � ����</returns>
		bool GetFlipStatus() const;


		/// <summary>
		/// ���������� ������ ��� ������
		/// </summary>
		/// <param name="out">�������� �����</param>
		/// <param name="card">������ �� �����</param>
		/// <returns></returns>
		friend ostream& operator<<(ostream& out, const Card& card);
};