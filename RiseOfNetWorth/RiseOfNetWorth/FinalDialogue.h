#pragma once
#include <iostream>
#include "DialogueTreeVisitor.h"
using namespace std;
class FinalDialogue
{
private:
	//Values
	string fQuestion;

	//Pointers to left node
	FinalDialogue* ANode;
	FinalDialogue* BNode;
public:
	FinalDialogue(string aQuestion);
	~FinalDialogue();
	bool isEmpty();

	//Tree Getters
	string GetQuestion();
	FinalDialogue* GetANode();
	FinalDialogue* GetBNode();

	//Setter for return code and attaching each tree node
	void AttachANode(string aQuestion);
	void AttachBNode(string aQuestion);

	//Traversing through the tree
	void accept(DialogueTreeVisitor& aVisitor);

	FinalDialogue* DetachANode();
	FinalDialogue* DetachBNode();
};

