#include "PlayerXPIterator.h"

PlayerXPIterator::PlayerXPIterator()
{
	fPlayerXP = NULL;
}
PlayerXPIterator::~PlayerXPIterator() {}

PlayerXPIterator::PlayerXPIterator(PlayerXP* aPlayerXP)
{
	fPlayerXP = aPlayerXP;
};

string PlayerXPIterator::operator*() const
{
	return fPlayerXP->ShowMessage();
}

PlayerXPIterator& PlayerXPIterator::operator++()
{
	if (fPlayerXP->NextXP() != NULL)//will only return clues that have a value
	{
		fPlayerXP = fPlayerXP->NextXP();
	}
	return *this;
};

PlayerXPIterator& PlayerXPIterator::operator++(int)//postfix
{
	PlayerXPIterator ltemp = *this;
	++(*this);
	return ltemp;
};

bool PlayerXPIterator::operator==(const Iterator& aOther) const
{
	return(fPlayerXP == aOther.fPlayerXP);
}
bool PlayerXPIterator::operator!=(const Iterator& aOther) const
{
	return !(fPlayerXP == aOther.fPlayerXP);
}

PlayerXPIterator PlayerXPIterator::end()
{
	PlayerXPIterator ltemp = *this;
	while (ltemp.fPlayerXP->NextXP() != NULL)
	{
		ltemp++;
	}
	return ltemp;
};