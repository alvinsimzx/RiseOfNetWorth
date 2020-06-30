#include "PlayerXP.h"

PlayerXP::PlayerXP()
{
	fMessage = "";
}

PlayerXP::PlayerXP(string aMessage)
{
	fMessage = aMessage;
}

PlayerXP::~PlayerXP()
{
}

PlayerXP* PlayerXP::NextXP()
{
	return fNextPlayerXP;
}

PlayerXP* PlayerXP::LatestXP()
{
	PlayerXP* TempClue = this;
	while (TempClue->fNextPlayerXP != NULL)
	{
		TempClue = fNextPlayerXP;
	}
	return TempClue;
}

void PlayerXP::SetNextXP(PlayerXP* aNextXP)
{
	if (fNextPlayerXP != NULL)
	{
		aNextXP->fNextPlayerXP = fNextPlayerXP;
	}
	fNextPlayerXP = aNextXP;
}

void PlayerXP::SetTail(PlayerXP* aNextXP)
{
	LatestXP()->SetNextXP(aNextXP);
}

string PlayerXP::ShowMessage()
{
	return fMessage;
}