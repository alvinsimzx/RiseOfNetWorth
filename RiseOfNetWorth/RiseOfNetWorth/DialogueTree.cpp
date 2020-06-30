#include "DialogueTree.h"

DialogueTree::DialogueTree(string aQuestion, string aChoiceA, string aChoiceB)
{
	fQuestion = aQuestion;
	fChoiceA = aChoiceA;
	fChoiceB = aChoiceB;
	fReturnCode = 0;
	ANode = NULL;
	BNode = NULL;
}

DialogueTree::~DialogueTree() {}

bool DialogueTree::isEmpty()
{
	return this == NULL;
}

string DialogueTree::GetQuestion()
{
	if (isEmpty())
		throw std::domain_error("Empty Dialogue Tree");
	return fQuestion;
}

string DialogueTree::GetChoiceA()
{
	if (isEmpty())
		throw std::domain_error("Empty Dialogue Tree");
	return fChoiceA;
}

string DialogueTree::GetChoiceB()
{
	if (isEmpty())
		throw std::domain_error("Empty Dialogue Tree");

	return fChoiceB;
}

int DialogueTree::GetReturnCodeVal()
{
	return fReturnCode;
}

DialogueTree* DialogueTree::GetANode()
{
	return ANode;
}
DialogueTree* DialogueTree::GetBNode()
{
	return BNode;
}


void DialogueTree::SetReturnCode(int aReturnCode)
{
	fReturnCode = aReturnCode;
}

void DialogueTree::AttachANode(string aQuestion, string aChoiceA,string aChoiceB)
{
	if (isEmpty())
		throw std::domain_error("Empty Dialogue Tree");
	if (ANode!=NULL)
		throw std::domain_error("Non-empty sub tree");
	ANode = new DialogueTree(aQuestion,aChoiceA,aChoiceB);
}

void DialogueTree::AttachBNode(string aQuestion, string aChoiceA, string aChoiceB)
{
	if (isEmpty())
		throw std::domain_error("Empty Dialogue Tree");
	if (BNode != NULL)
		throw std::domain_error("Non-empty sub tree");
	BNode = new DialogueTree(aQuestion, aChoiceA, aChoiceB);
}

DialogueTree* DialogueTree::DetachANode()
{
	if (isEmpty())
		throw std::domain_error("Empty BTree");
	DialogueTree& Result = *ANode; //changed to pointer variable 
	ANode = NULL;
	return &Result;
}

DialogueTree* DialogueTree::DetachBNode()
{
	if (isEmpty())
		throw std::domain_error("Empty BTree");
	DialogueTree& Result = *BNode; //changed to pointer variable 
	BNode = NULL;
	return &Result;
}

int DialogueTree::accept(DialogueTreeVisitor& aVisitor)
{
	if (!isEmpty())
	{
		return aVisitor.visit(this); //print out the instructions
	}
	return 0;
}

