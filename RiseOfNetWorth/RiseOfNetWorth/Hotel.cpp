#include "Hotel.h"

Hotel::Hotel(int aPrice, string aPlaceName): Properties(aPrice, aPlaceName)
{}

Hotel::~Hotel() {}

string Hotel::PropertyMessage()
{
 return "Hotel of " + fPlaceName;
}

