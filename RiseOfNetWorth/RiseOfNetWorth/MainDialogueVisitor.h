#pragma once
#include "DialogueTreeVisitor.h"

class MainDialogueVisitor : public DialogueTreeVisitor
{
public:
	virtual int visit(DialogueTree* aDialogueTree);
};

