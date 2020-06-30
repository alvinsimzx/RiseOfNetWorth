#pragma once
#include <iostream>
using namespace std;

class DialogueTree;
class FinalDialogue;
class DialogueTreeVisitor
{
public:
	virtual ~DialogueTreeVisitor() {} //virtual default destructor 
	virtual int visit(DialogueTree* aDialogueTree) { return 0; };
	virtual void visit(FinalDialogue* aFinalDialogue) {};
};

