#include "CorrectGuess.h"
#include "IPOCentre.h"

void CorrectGuess::AddPlayerValuation(IPOCentre* aIPOCentre, Player* aPlayer)
{
	cout << "\nIPO CENTRE Message: You have already reached the required net worth.\n" << endl;
}
void CorrectGuess::EnterGuess(IPOCentre* aIPOCentre, string aUserGuess)
{
	cout << "\nIPO CENTRE Message: You have already guessed the correct person.\n" << endl;
}

void CorrectGuess::StartIPO(IPOCentre* aIPOCentre)
{
	aIPOCentre->SetActivated(true);
}