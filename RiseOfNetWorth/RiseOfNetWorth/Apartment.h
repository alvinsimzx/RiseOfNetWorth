#pragma once
#include "Properties.h"
class Apartment :public Properties
{
public:
	Apartment(int aPrice, string aPlaceName);
	~Apartment();

	string PropertyMessage();
};

