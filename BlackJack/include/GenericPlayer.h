#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Koloda.h"

class Hand
{
private:
	std::vector<Card*> m_Cards;
public:
	Hand() {};
	~Hand();
	void AddCard(Card* pCard);
	void ClearHand();
	int GetCountCard();
	int GetSumCard();
	string GetNameCard(int numberCard);
};

class GenericPlayer : public Hand
{
	private:
		string _name;
		uint8_t _year;
	public:
		GenericPlayer(const string& name, uint8_t year) :_name(name), _year(year), Hand() {};
		virtual void IsHitting() {};
		string GetNamePlayer();
		uint8_t GetYear();
		bool IsBoosted();
		void Bust();
};