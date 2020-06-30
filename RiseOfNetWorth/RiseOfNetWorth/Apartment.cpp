#include "Apartment.h"

Apartment::Apartment(int aPrice, string aPlaceName) : Properties(aPrice, aPlaceName)
{

}
Apartment::~Apartment() {}

string Apartment::PropertyMessage()
{
	return "Apartment of " + fPlaceName;
}