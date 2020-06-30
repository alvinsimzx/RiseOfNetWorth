#include "Location.h"

Location::Location(string aLocationName, int aPriceApartment, int aPriceHouse, int aPriceHotel)
{
	fLocationName = aLocationName;
	fHasOppurtunities = false;
	fHaveProperties = true;
	fHasXPCard = false;
	fApartment = new Apartment(aPriceApartment,aLocationName);
	fHouses = new HousingEstate(aPriceHouse, aLocationName);
	fHotel = new Hotel(aPriceHotel, aLocationName);
}

Location::Location(string aLocationName,bool aHasXPCard, int aPriceApartment, int aPriceHouse, int aPriceHotel)
{
	fLocationName = aLocationName;
	fHasOppurtunities = false;
	fHaveProperties = true;
	fHasXPCard = aHasXPCard;
	fApartment = new Apartment(aPriceApartment, aLocationName);
	fHouses = new HousingEstate(aPriceHouse, aLocationName);
	fHotel = new Hotel(aPriceHotel, aLocationName);
}


Location::Location(string aLocationName, bool aHasOpportunities)
{
	fLocationName = aLocationName;
	fHasOppurtunities = aHasOpportunities;
	fHasXPCard = false;
	fHaveProperties = true;
	fApartment = new Apartment(0,"");
	fHouses = new HousingEstate(0,"");
	fHotel = new Hotel(0,"");
}

Location::Location(string aLocationName, int aPricePlaceholder, bool aHasOpportunities)
{
	fLocationName = aLocationName;
	fHasOppurtunities = aHasOpportunities;
	fHasXPCard = false;
	fHaveProperties = false;
	fApartment = new Apartment(0, "");
	fHouses = new HousingEstate(0, "");
	fHotel = new Hotel(0, "");
}

void Location::ShowPropertyPrices()
{
	if (fHaveProperties)
	{
		cout << ">>1.Apartment: $" << fApartment->GetPrice()<<" \t\t"<<fApartment->OwnershipStatusString() << endl;
		cout << ">>2.Housing Estate: $" << fHouses->GetPrice() << " \t" << fHouses->OwnershipStatusString()<< endl;
		cout << ">>3.Hotel: $" << fHotel->GetPrice() << " \t\t\t" << fHotel->OwnershipStatusString() << endl;
		cout << endl;
	}
	else
	{
		cout << "This is the centre of the IPO." << endl;
	}

}

bool Location::CheckHaveProperties()
{
	return fHaveProperties;
}

bool  Location::CheckHaveOppurtunities()
{
	return fHasOppurtunities;
}

bool Location::CheckHaveXPCard()
{
	return fHasXPCard;
}

string Location::GetPropertyStatus(bool aPropertyStatus)
{
	if (aPropertyStatus == true)
	{
		return "Sold";
	}
	else
	{
		return "On Sale";
	}
}

string Location::GetLocationName()
{
	return fLocationName;
}

void Location::SetHasXP(bool aHasXP)
{
	fHasXPCard = aHasXP;
}

Apartment* Location::GetApartment()
{
	return fApartment;
}

HousingEstate* Location::GetHouses()
{
	return fHouses;
}
Hotel* Location::GetHotel()
{
	return fHotel;
}

void Location::SetNextForward(Location* aNextLocation)
{

	aNextLocation->fPreviousLocation = this;
	if (fNextLocation != NULL)
	{
		aNextLocation->fNextLocation = fNextLocation;
		fNextLocation->fPreviousLocation = aNextLocation;
	}
	fNextLocation = aNextLocation;
}

void Location::SetPreviousBack(Location* aPreviousLocation)
{
	aPreviousLocation->fNextLocation = this;
	if (fPreviousLocation != NULL)
	{
		aPreviousLocation->fPreviousLocation = fPreviousLocation;
		fPreviousLocation->fNextLocation = fPreviousLocation;
	}
	fPreviousLocation = aPreviousLocation;
}

Location* Location::GetNextLocation()
{
	return fNextLocation;
}

Location* Location::GetPreviousLocation()
{
	return fPreviousLocation;
}