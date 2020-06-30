#include "Properties.h"

Properties::Properties(int aPrice, string aPlaceName)
{
	fPlaceName = aPlaceName;
	fPrice = aPrice;
	fMortgagePrice = aPrice / 2;
	fOwned = false;
}

Properties::~Properties()
{}
/*
string Properties::PropertyMessage()
{
	return "Housing Residnecy of " + fPlaceName;
}*/

int Properties::GetPrice()
{
	return fPrice;
}

int Properties::GetSellPrice()
{
	return fMortgagePrice;
}

void Properties::BuyProperty()
{
	fOwned = true;
}

bool Properties::GetOwnershipStatus()
{
	return fOwned;
}

string Properties::OwnershipStatusString()
{
	if (fOwned == false)
	{
		return "On Sale";
	}
	else
	{
		return "SOLD";
	}
}

void Properties::SetOwnershipStatus(bool aStatus)
{
	fOwned = aStatus;
}
