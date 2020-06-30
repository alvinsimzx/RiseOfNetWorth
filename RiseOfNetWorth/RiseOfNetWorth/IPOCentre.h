#pragma once
#include <iostream>
using namespace std;
class Player;
class IPOCentreState;

class IPOCentre
{
protected:
	IPOCentreState* fIPOCentreState;
	int fPlayerValuation;
	bool fActivated;
public:
	IPOCentre();
	~IPOCentre();
	//Setters
	void SetCurrentState(IPOCentreState* aIPOCentreState);
	void SetPlayerValuation(int aPlayerValuation);
	void SetActivated(bool aActivated);

	//Getters
	bool GetPlayerValuation();
	bool GetActivated();

	//Use Cases
	void AddPlayerValuation(Player* aPlayer);
	void StartIPO();
	void EnterGuess(string aUserGuess);
};

