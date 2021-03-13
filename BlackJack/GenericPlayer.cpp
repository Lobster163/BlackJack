#include "include/GenericPlayer.h"

void Hand::AddCard(Card* pCard)
{
	m_Cards.push_back(pCard);
}
Hand::~Hand()
{
	cout << "Hand destructor" << endl;
	ClearHand();
}

void Hand::ClearHand()
{
	vector<Card*>::iterator iter = m_Cards.begin();	

	for (iter=m_Cards.begin(); iter!= m_Cards.end(); ++iter)
		delete * iter;

	m_Cards.erase(m_Cards.begin(), m_Cards.end());
}

int Hand::GetCountCard() { return m_Cards.size(); }

int Hand::GetSumCard()
{
	int sum = 0;
	for (int i = 0; i < GetCountCard(); ++i)
	{
		int val = m_Cards[i]->GetValue();
		if (val == 1)
		{
			if (sum < 21)
				sum = sum + 11;
			else
				sum = sum + 1;
		}
		else
		{
			if (val < 20)
				sum = sum + val;
			else
				sum = sum + 10;
		}
	}
	return sum;
}

string Hand::GetNameCard(int numberCard){ return m_Cards[numberCard]->GetName(); }
string GenericPlayer::GetNamePlayer() { return _name; }
uint8_t GenericPlayer::GetYear() { return _year;  }

bool GenericPlayer::IsBoosted()
{
	if (this->GetSumCard() > 21)
		return true;
	else
		return false;
}

void GenericPlayer::Bust()
{
	if (IsBoosted())
		cout << "Player " << _name << " Sum card > 21" << endl;
}