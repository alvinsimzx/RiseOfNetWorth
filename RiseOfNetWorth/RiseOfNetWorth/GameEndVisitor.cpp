#include "GameEndVisitor.h"
#include "FinalDialogue.h"

void GameEndVisitor::visit(FinalDialogue* aFinalDialogue)
{
	if (aFinalDialogue != NULL)
	{
		cout << "IPO Centre Meeting" << endl;
		cout << aFinalDialogue->GetQuestion() << endl;
		system("pause");
		system("cls");
		aFinalDialogue->GetANode()->accept(*this);
	}
	return;	
}