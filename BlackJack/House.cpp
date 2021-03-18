#include "include/House.h"

bool House::IsHitting() const
{
	return (this->GetSumCard() <= 16);
}

void House::FlipFirstCard()
{
	if (GetCountCard() > 0)
	{
		FlipCard(0);
	}		
}