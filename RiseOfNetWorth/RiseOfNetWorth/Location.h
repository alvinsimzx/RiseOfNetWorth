#pragma once
#include <iostream>
#include "Apartment.h"
#include "Hotel.h"
#include "HousingEstate.h"
using namespace std;
class Location
{
private:
	//values stored
	string fLocationName;
	bool fHasOppurtunities;
	bool fHasXPCard;
	bool fHaveProperties;
	//Instances of differnt properties
	Apartment* fApartment;
	HousingEstate* fHouses;
	Hotel* fHotel;

	//Mext and previous pointers
	Location* fNextLocation;
	Location* fPreviousLocation;
public:
	Location(string aLocationName,int aPriceApartment,int aPriceHouse,int aPriceHotel);
	Location(string aLocationName, int aPricePlaceholder,bool aHasProperties);
	Location(string aLocationName, bool aHasXPCard, int aPriceApartment, int aPriceHouse, int aPriceHotel);
	Location(string aLocationName, bool aHasOpportunities);
	~Location();

	string GetLocationName();
	void ShowPropertyPrices();
	void SetHasXP(bool aHasXP);
	string GetPropertyStatus(bool aPropertyStatus);
	bool CheckHaveProperties();
	bool CheckHaveOppurtunities();
	bool CheckHaveXPCard();
	
	Apartment* GetApartment();
	HousingEstate* GetHouses();
	Hotel* GetHotel();

	void SetNextForward(Location* aNextLocation); // append
	void SetPreviousBack(Location* aPreviousLocation);// prepend
	Location* GetNextLocation();
	Location* GetPreviousLocation();
};

