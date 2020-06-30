#include "InsufficientValuation.h"
#include "IPOCentre.h"
#include "SufficientValuation.h"
#include "Player.h"

void InsufficientValuation::AddPlayerValuation(IPOCentre* aIPOCentre, Player* aPlayer)
{
		if (aPlayer->GetPlayerValuation()>=3500)
		{
			aIPOCentre->SetPlayerValuation(aPlayer->GetPlayerValuation());
			aIPOCentre->SetCurrentState(new SufficientValuation());
			cout << "\nIPO Centre Message: CONGRATULATION, you Have reached the required player valuation\n" << endl;
			return;
		}
		else
		{
			cout << "\nIPO Centre Message: You have nota achieved the required player valuation yet\n" << endl;
		}
	
}