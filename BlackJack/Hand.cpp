#include "include/Hand.h"

void Hand::AddCard(Card* pCard)
{
	m_Cards.push_back(pCard);
}

Hand::~Hand()
{
	//cout << "Hand destructor" << endl;
	ClearHand();
}

void Hand::ClearHand()
{
	vector<Card*>::iterator iter = m_Cards.begin();

	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
		delete* iter;

	m_Cards.erase(m_Cards.begin(), m_Cards.end());
}

int Hand::GetCountCard() const { return m_Cards.size(); }

int Hand::GetSumCard() const
{
	int sum = 0;
	for (int i = 0; i < GetCountCard(); ++i)
	{
		if (m_Cards[i]->GetFlipStatus())
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
	}
	return sum;
}

string Hand::GetNameCard(int numberCard) const { return m_Cards[numberCard]->GetName(); }

void Hand::FlipCard(int numberCard) const
{
	m_Cards[numberCard]->Flip();
}

vector<Card*> Hand::ñGetCards() const
{
	return m_Cards;
}

vector<Card*>& Hand::GetCards()
{
	return m_Cards;
}