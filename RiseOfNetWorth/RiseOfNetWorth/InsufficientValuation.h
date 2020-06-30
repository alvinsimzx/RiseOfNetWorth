#pragma once
#include "IPOCentreState.h"

class IPOCentre;
class InsufficientValuation : public IPOCentreState
{
public:
	void AddPlayerValuation(IPOCentre* aIPOCentre, Player* aPlayer);
};

