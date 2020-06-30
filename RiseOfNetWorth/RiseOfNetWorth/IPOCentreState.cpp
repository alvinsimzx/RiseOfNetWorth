#include "IPOCentreState.h"

void IPOCentreState::AddPlayerValuation(IPOCentre* aIPOCentre, Player* aPlayer)
{
	cout << "\nIPO CENTRE Message: Your net worth isn't high enough yet, come back when you have a valuation of more thatn $3500.\n" << endl;
}
void IPOCentreState::StartIPO(IPOCentre* aIPOCentre)
{
	cout << "\nIPO CENTRE Message: Your net worth isn't high enough yet and you have not gussed the correct person. Therfore, you cannot start an IPO.\n" << endl;
}
void IPOCentreState::EnterGuess(IPOCentre* aIPOCentre, string aUserGuess)
{
	cout << "\nIPO CENTRE Message: You have not reached the required valuation.\n" << endl;
}