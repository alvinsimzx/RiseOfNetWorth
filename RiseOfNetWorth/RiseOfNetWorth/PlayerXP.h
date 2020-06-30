#pragma once
#include <iostream>
using namespace std;

class PlayerXP
{
private:
	string fMessage; //values
	PlayerXP* fNextPlayerXP; //Next pointer
public:
	PlayerXP();
	PlayerXP(string aMessage);
	~PlayerXP();

	PlayerXP* NextXP();
	PlayerXP* LatestXP();// Tail of Linked List

	//Setter
	void SetNextXP(PlayerXP* aNextXP);// Set the next XP from the current
	void SetTail(PlayerXP* aNextXP);// Set the tail of the linked list

	//Return the XP's content
	string ShowMessage();
};

