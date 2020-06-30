#include "OppurtunityCard.h"

OppurtunityCard::OppurtunityCard(string aMessage, int aValue, bool aBeneficial)
{
	fMessage = aMessage;
	fValue = aValue;
	fBeneficial = aBeneficial;
}

OppurtunityCard::~OppurtunityCard()
{}

void OppurtunityCard::AddPlayerMoney(Player* aPlayer)
{ 
	int temp = aPlayer->GetPlayerMoney() + fValue;
	aPlayer->SetPlayerMoney(temp);
}

void OppurtunityCard::DeductPlayerMoney(Player* aPlayer)
{
	int temp = aPlayer->GetPlayerMoney() - fValue;

	aPlayer->SetPlayerMoney(temp);
}

bool OppurtunityCard::GetCardBeneficial()
{
	return fBeneficial;
}

string OppurtunityCard::GetCardMessage()
{
	return fMessage;

}

int OppurtunityCard::GetCardValue()
{
	return fValue;
}
