#include "LocationIterator.h"

LocationIterator::LocationIterator(Location* aLocation)
{
	fLocation = aLocation;
}

LocationIterator::~LocationIterator() {}

string LocationIterator::operator*() const
{
	return fLocation->GetLocationName();
}

LocationIterator& LocationIterator::operator++()
{
	if (fLocation->GetNextLocation() != NULL)
	{
		fLocation = fLocation->GetNextLocation();
	}
	return *this;
}

LocationIterator& LocationIterator::operator++(int)
{
	LocationIterator temp = *this;
	++(*this);
	return temp;
}

LocationIterator& LocationIterator::operator--()
{
	if (fLocation->GetPreviousLocation() != NULL)
	{
		fLocation = fLocation->GetPreviousLocation();
	}
	return *this;
}

LocationIterator& LocationIterator::operator--(int)
{
	LocationIterator temp = *this;
	--(*this);

	return temp;
}


bool LocationIterator::operator==(const Iterator& aOther) const
{
	return(fLocation == aOther.fLocation);
}
bool LocationIterator::operator!=(const Iterator& aOther) const
{
	return !(fLocation == aOther.fLocation);
}

LocationIterator LocationIterator::begin()
{
	LocationIterator ltemp = *this;
	while (ltemp.fLocation->GetPreviousLocation() != NULL)
	{
		ltemp--;
	}
	return ltemp;

}

Location* LocationIterator::current() const //returns the current GameMap node being pointed at
{
	return fLocation;
}

LocationIterator LocationIterator::end()
{
	LocationIterator temp = *this;
	while (temp.fLocation->GetNextLocation() != NULL)
	{
		temp++;
	}
	return temp;
}