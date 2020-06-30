#pragma once
#include "Properties.h"
#include "Location.h"
#include "LocationIterator.h"
#include "PlayerXPIterator.h"
#include "PlayerXP.h"
#include "Queue.h"
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Stack.h"
#include "IPOCentre.h"
using namespace std;
class Player
{
private:
	string fPlayerName;
	int fPlayerMoney;
	int fPlayerValuation;
	int fPlayerMovesCounter;

	Queue<int> fPlayerTaxes;
	PlayerXP* fPlayerXPReceived;
	vector<Properties*> fPlayerProperties;
public:
	Player(string aPlayerName);
	~Player();

	string GetPlayerName();
	int GetPlayerMoney();
	Queue<int> GetPlayerTaxes();
	Properties* GetPlayerProperties(int aIndex);
	int GetPlayerValuation();

	void BuyProperty(int aChoice, LocationIterator& aLocationIterator);
	void SellProperty();
	void PayTaxes();
	void GetPropertiesIncome();
	void InitiateIPO(LocationIterator& aLocationIterator,IPOCentre* aIPOCentre);
	void DetermineTaxes();
	void ShowPlayerInfo(LocationIterator aLocationIter);
	void SetPlayerMoney(int aValue);
	void ObtainXPCard(PlayerXP* aPlayerXP);
	void RemoveAllTaxes();
	
	//Map Movement Methods
	LocationIterator& DeterminePlayerMovement(LocationIterator& aLocationIterator);
	LocationIterator& MoveForward(LocationIterator& aLocationIterator);
	LocationIterator& MoveBackward(LocationIterator& aLocationIterator);

	void DeterminePlayerActions(LocationIterator& aLocationIterator, IPOCentre* aIPOCentre);
};

