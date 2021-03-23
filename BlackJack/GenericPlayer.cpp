#include "include/GenericPlayer.h"

string GenericPlayer::GetNamePlayer() const  { return _name; }
uint8_t GenericPlayer::GetYear() { return _year;  }

bool GenericPlayer::IsBusted()
{
	if (this->GetSumCard() > 21)
		return true;
	else
		return false;
}

void GenericPlayer::Bust()
{
	if (IsBusted())
		cout << "Player " << _name << " Sum card > 21" << endl;
}

ostream& operator<<(ostream& out, const GenericPlayer& genPlayer)
{
	out << genPlayer.GetNamePlayer() << ":\t";

	if (genPlayer.GetCountCard() > 0)
	{
		for (Card* card : genPlayer.сGetCards())
			out << *card << "\t";
		
		
		if (genPlayer.GetSumCard() != 0)		
			out << "Sum=" << genPlayer.GetSumCard() << "\t";

		if (genPlayer.GetSumCard() >= 21)
		{
			genPlayer.SetGameStatus(false);
		}
	}
	else
	{
		out << "No card in hand";
	}
	return out << endl;
}