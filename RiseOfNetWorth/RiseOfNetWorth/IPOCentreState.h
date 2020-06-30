#pragma once
#include <iostream>
using namespace std;

class Player;
class IPOCentre;

class IPOCentreState
{
public:
	//Use cases that can be override by each state
	virtual void AddPlayerValuation(IPOCentre* aIPOCentre, Player* aPlayer);
	virtual void StartIPO(IPOCentre* aIPOCentre);
	virtual void EnterGuess(IPOCentre* aIPOCentre, string aUserGuess);
};

