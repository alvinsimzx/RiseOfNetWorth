#pragma once
#include "IPOCentreState.h"
class CorrectGuess : public IPOCentreState
{
public:
	void AddPlayerValuation(IPOCentre* aIPOCentre, Player* aPlayer);
	void StartIPO(IPOCentre* aIPOCentre);
	void EnterGuess(IPOCentre* aIPOCentre, string aUserGuess);
};

