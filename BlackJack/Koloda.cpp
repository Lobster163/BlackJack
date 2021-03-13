#include "include/Koloda.h"

bool Card::Flip()
{
	m_IsFaceUp = !m_IsFaceUp;
	return m_IsFaceUp;
}

Card::~Card()
{
	cout << "card destructor" << endl;
}

int Card::GetValue() { return (int)m_Rank; }

string Card::GetName()
{
	switch (m_Rank)
	{
	case Rank::_2:
	case Rank::_3:
	case Rank::_4:
	case Rank::_5:
	case Rank::_6:
	case Rank::_7:
	case Rank::_8:
	case Rank::_9:
	case Rank::_10:
		return std::to_string((int)m_Rank);
	case Rank::_V:
		return "V";
	case Rank::_Q:
		return "Q";
	case Rank::_K:
		return "K";
	case Rank::_A:
		return "T";
	}
}