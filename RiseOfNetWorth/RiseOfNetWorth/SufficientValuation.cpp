#include "SufficientValuation.h"
#include "IPOCentre.h"
#include "CorrectGuess.h"
#include "Player.h"

void SufficientValuation::AddPlayerValuation(IPOCentre* aIPOCentre, Player* aPlayer)
{
	cout << "\nIPO Centre Message: You have already surpassed the required valuation.\n" << endl;
}

void SufficientValuation::EnterGuess(IPOCentre* aIPOCentre, string aUserGuess)
{
	if (aUserGuess == "jeff" && (aIPOCentre->GetPlayerValuation())) //if the player gueses the password correctly and the Portal Ring has been inserted
	{
		cout << "\nIPO Centre Message: Congratulations! You have successfully completed the requirements. You may start an IPO now.\n" << endl;
		aIPOCentre->SetCurrentState(new CorrectGuess());
	}
	else//wrong password but the portal ring has been inserted
	{
		cout << "\nIPO Centre Message: Sorry that was not the right guess.\n" << endl;
	}
}

void SufficientValuation::StartIPO(IPOCentre* aIPOCentre)
{
	cout << "\nIPO Centre Message: You have not guessed the correct leader yet.\n" << endl;
}