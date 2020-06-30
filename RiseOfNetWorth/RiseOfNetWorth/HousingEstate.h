#pragma once
#include "Properties.h"
class HousingEstate : public Properties
{
public:
	HousingEstate(int aPrice, string aPlaceName);
	~HousingEstate();

	string PropertyMessage();
};