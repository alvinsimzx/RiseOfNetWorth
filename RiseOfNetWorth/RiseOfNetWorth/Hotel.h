#pragma once
#include "Properties.h"
class Hotel : public Properties
{
public:
	Hotel(int aPrice, string aPlaceName);
	~Hotel();

	string PropertyMessage();
};

