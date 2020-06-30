#pragma once
#include <iostream>
#include "Player.h"
using namespace std;
class OppurtunityCard
{
private:
	string fMessage;
	int fValue;
	bool fBeneficial;
public:
	OppurtunityCard(string aMessage, int aValue, bool aBeneficial);
	~OppurtunityCard();

	void AddPlayerMoney(Player* aPlayer);
	void DeductPlayerMoney(Player* aPlayer);

	string GetCardMessage();
	int GetCardValue();
	bool GetCardBeneficial();

	
};

