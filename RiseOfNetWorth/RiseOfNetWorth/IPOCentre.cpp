#include "IPOCentre.h"
#include "IPOCentreState.h"
#include "InsufficientValuation.h"
#include "Player.h"

IPOCentre::IPOCentre()
{
	fPlayerValuation = 0;
	fActivated = false;
	fIPOCentreState = new InsufficientValuation();
}

IPOCentre::~IPOCentre() {}

void IPOCentre::SetCurrentState(IPOCentreState* aIPOCentreState) //Set the current state of the portal
{
	if (fIPOCentreState)
	{
		delete fIPOCentreState;
		fIPOCentreState = NULL;
	}
	fIPOCentreState = aIPOCentreState;
}

void IPOCentre::SetPlayerValuation(int aPlayerValuation) //add the Portal Ring
{
	fPlayerValuation = aPlayerValuation;

}

void IPOCentre::SetActivated(bool aActivated) //Activate the portal
{
	fActivated = aActivated;
}

bool IPOCentre::GetPlayerValuation() //checks if the portal ring is in the portal
{
	if (fPlayerValuation>=3500)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IPOCentre::GetActivated() //checks if the portal is activated
{
	return fActivated;
}

void IPOCentre::AddPlayerValuation(Player* aPlayer) //Adds a portal ring to the portal
{
	if (fIPOCentreState)
	{
		fIPOCentreState->AddPlayerValuation(this, aPlayer);
	}
}

void IPOCentre::StartIPO() //Activates the portal
{
	if (fIPOCentreState)
	{
		fIPOCentreState->StartIPO(this);
	}
};
void IPOCentre::EnterGuess(string aUserGuess) //Guess the portal's password
{
	if (fIPOCentreState)
	{
		fIPOCentreState->EnterGuess(this, aUserGuess);
	}
}