#include "FinalDialogue.h"


FinalDialogue::FinalDialogue(string aQuestion)
{
	fQuestion = aQuestion;
	ANode = NULL;
	BNode = NULL;
}

FinalDialogue::~FinalDialogue() {}

bool FinalDialogue::isEmpty()
{
	return this == NULL;
}

string FinalDialogue::GetQuestion()
{
	if (isEmpty())
		throw std::domain_error("Empty Dialogue Tree");
	return fQuestion;
}


FinalDialogue* FinalDialogue::GetANode()
{
	return ANode;
}
FinalDialogue* FinalDialogue::GetBNode()
{
	return BNode;
}


void FinalDialogue::AttachANode(string aQuestion)
{
	if (isEmpty())
		throw std::domain_error("Empty Dialogue Tree");
	if (ANode != NULL)
		throw std::domain_error("Non-empty sub tree");
	ANode = new FinalDialogue(aQuestion);
}

void FinalDialogue::AttachBNode(string aQuestion)
{
	if (isEmpty())
		throw std::domain_error("Empty Dialogue Tree");
	if (BNode != NULL)
		throw std::domain_error("Non-empty sub tree");
	BNode = new FinalDialogue(aQuestion);
}

FinalDialogue* FinalDialogue::DetachANode()
{
	if (isEmpty())
		throw std::domain_error("Empty BTree");
	FinalDialogue& Result = *ANode; //changed to pointer variable 
	ANode = NULL;
	return &Result;
}

FinalDialogue* FinalDialogue::DetachBNode()
{
	if (isEmpty())
		throw std::domain_error("Empty BTree");
	FinalDialogue& Result = *BNode; //changed to pointer variable 
	BNode = NULL;
	return &Result;
}

void FinalDialogue::accept(DialogueTreeVisitor& aVisitor)
{
	aVisitor.visit(this); //print out the instructions
}