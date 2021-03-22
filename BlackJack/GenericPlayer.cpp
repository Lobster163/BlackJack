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
		for (int i = 0; i < genPlayer.GetCountCard(); i++)
			out << genPlayer.ñGetCards()[i] << "\t";
		
		
		if (genPlayer.GetSumCard() != 0)		
			cout << "Sum=" << genPlayer.GetSumCard() << "";
	}
	else
	{
		out << "No card in hand";
	}
	return out << endl;
}