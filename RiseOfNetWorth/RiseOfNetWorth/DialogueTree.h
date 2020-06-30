#pragma once
#include <iostream>
#include "DialogueTreeVisitor.h"

using namespace std;
class DialogueTree
{
private:
	//Values
	string fQuestion;
	string fChoiceA;
	string fChoiceB;
	int fReturnCode;

	//Pointers to left and right node
	DialogueTree* ANode;
	DialogueTree* BNode;
public:
	DialogueTree(string aQuestion, string aChoiceA, string aChoiceB);
	~DialogueTree();
	bool isEmpty();

	//Tree Getters
	string GetQuestion();
	string GetChoiceA();
	string GetChoiceB();
	int GetReturnCodeVal();
	DialogueTree* GetANode();
	DialogueTree* GetBNode();
	
	//Setter for return code and attaching each tree node
	void SetReturnCode(int aReturnCode);
	void AttachANode(string aQuestion, string aChoiceA, string aChoiceB);
	void AttachBNode(string aQuestion, string aChoiceA, string aChoiceB);
	
	//Traversing through the tree
	int accept(DialogueTreeVisitor& aVisitor);

	DialogueTree* DetachANode();
	DialogueTree* DetachBNode();
};

