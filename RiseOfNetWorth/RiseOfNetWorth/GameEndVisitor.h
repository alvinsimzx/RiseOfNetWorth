#pragma once
#include "DialogueTreeVisitor.h"
class GameEndVisitor : public DialogueTreeVisitor
{
public:
	virtual void visit(FinalDialogue* aFinalDialogue);
};

