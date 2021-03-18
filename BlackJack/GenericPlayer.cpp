#include "include/GenericPlayer.h"

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

	for (iter=m_Cards.begin(); iter!= m_Cards.end(); ++iter)
		delete * iter;

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

vector<Card*> Hand::GetCards() const
{
	return m_Cards;
}


string GenericPlayer::GetNamePlayer() const  { return _name; }
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

ostream& operator<<(ostream& out, const GenericPlayer& genPlayer)
{
	out << genPlayer.GetNamePlayer() << ":\t";

	if (genPlayer.GetCountCard() > 0)
	{
		for (int i = 0; i < genPlayer.GetCountCard(); i++)
			out << *genPlayer.GetCards()[i] << "\t";
		
		
		if (genPlayer.GetSumCard() != 0)		
			cout << "Sum=" << genPlayer.GetSumCard() << "";
	}
	else
	{
		out << "No card in hand";
	}
	return out << endl;
}