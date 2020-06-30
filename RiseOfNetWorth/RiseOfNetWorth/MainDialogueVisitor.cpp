#include "MainDialogueVisitor.h"
#include "DialogueTree.h"



int MainDialogueVisitor::visit(DialogueTree* aDialogueTree)
{
	system("cls");
	cout << "COURT TRIAL" << endl;
	cout << "\nProsecutor: " << aDialogueTree->GetQuestion() << endl;
	cout << "\nPick a response: " << endl;
	cout << ">>A." << aDialogueTree->GetChoiceA() << endl;
	cout << ">>B." << aDialogueTree->GetChoiceB() << endl;
	cout << endl;
	cout << "Your Response: ";

	int aPlayerOutcome=0;
	char lResponse = NULL;
	cin >> lResponse;
	if (tolower(lResponse) == 'a')
	{
		if (aDialogueTree->GetReturnCodeVal() > 0)
		{
			return aDialogueTree->GetReturnCodeVal();
		}
		aPlayerOutcome = aDialogueTree->GetANode()->accept(*this);
	}
	else if (tolower(lResponse) == 'b' )
	{
		if (aDialogueTree->GetReturnCodeVal() > 0)
		{
			return aDialogueTree->GetReturnCodeVal();
		}
		aPlayerOutcome = aDialogueTree->GetBNode()->accept(*this);
	}
	return aPlayerOutcome;
}
