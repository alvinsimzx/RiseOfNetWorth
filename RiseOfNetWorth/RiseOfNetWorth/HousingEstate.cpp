#include "HousingEstate.h"

HousingEstate::HousingEstate(int aPrice, string aPlaceName) : Properties(aPrice, aPlaceName)
{}

HousingEstate::~HousingEstate()
{

}

string HousingEstate::PropertyMessage()
{
	return "Housing Residnecy of " + fPlaceName;
}
