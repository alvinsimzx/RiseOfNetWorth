#include "Player.h"

Player::Player(string aPlayerName)
{
	fPlayerName = aPlayerName;
	fPlayerMoney = 2000;
	fPlayerMovesCounter = 0;
	fPlayerValuation = 2000;
	fPlayerXPReceived = new PlayerXP();
}

string Player::GetPlayerName()
{
	return fPlayerName;
}

int Player::GetPlayerMoney()
{
	return fPlayerMoney;
}

Properties* Player::GetPlayerProperties(int aIndex)
{
	return fPlayerProperties.at(aIndex);
}

Queue<int> Player::GetPlayerTaxes()
{
	return fPlayerTaxes;
}

int Player::GetPlayerValuation()
{
	return fPlayerValuation;
}

void Player::ShowPlayerInfo(LocationIterator aLocationIter)
{
	system("cls");
	cout << "Player Name: " + fPlayerName << endl; //Player's name information
	cout << "=====================================================================================================" << endl;
	cout << "Current Bank Balance: $" << fPlayerMoney << "|\t\tCurrent Net Worth: $" << fPlayerValuation << "|\t\tTaxes You Have: "<< fPlayerTaxes.size() <<endl; //Player's health information

	//Weapon information will change if or if not they have a weapon with them
	
	if (fPlayerProperties.empty())
	{
		cout << "Your current Properties: NONE|" << endl;
	}
	else
	{
		cout << "\nYour Current Properties:" << endl;
		for (int i = 0; i < fPlayerProperties.size(); i++)
		{
			cout << ">>"<<i+1 << ". " <<fPlayerProperties.at(i)->PropertyMessage()<<" \t\tPrice: $"<<fPlayerProperties.at(i)->GetSellPrice() << endl;
		}
	}

	
	cout << "\nXP Cards collected: " << endl;
	PlayerXPIterator lPlayerXPiter(fPlayerXPReceived);
	for (lPlayerXPiter; lPlayerXPiter != lPlayerXPiter.end(); lPlayerXPiter++)
	{
		cout << "- "<<*lPlayerXPiter << endl;
	}
	cout << "- " << *lPlayerXPiter << endl;
	cout << "" << endl;

	//Indicates the current situation of the cave they are in
	cout << "\nCurrent Location: " << *aLocationIter << endl;
	if (!aLocationIter.current()->CheckHaveOppurtunities())
	{
		aLocationIter.current()->ShowPropertyPrices();
	}
	
	cout << "=====================================================================================================" << endl;

}

void Player::InitiateIPO(LocationIterator& aLocationIterator, IPOCentre* aIPOCentre)
{
	if (aLocationIterator == aLocationIterator.begin())//checks if the player is at the start of the map
	{
		char UserResponse;
		cout << "What would you like to do at the IPO Centre?\n>> A. Submit IPO Request\n>> B. Guess Password\n>> C. Start IPO\n>> D. Nothing" << endl;
		cin >> UserResponse;
		if (tolower(UserResponse) == 'a')// Add Portal Ring
		{
			aIPOCentre->AddPlayerValuation(this);
		}
		else if (tolower(UserResponse) == 'b')// Guess the Password
		{
			string lPasswordGuess;
			cout << "What's your guess on the first name of the guy? " << endl;
			cin >> lPasswordGuess;
			aIPOCentre->EnterGuess(lPasswordGuess);

		}
		else if (tolower(UserResponse) == 'c')//Activate the portal
		{
			aIPOCentre->StartIPO();
		}
		else { //Do Nothing
			return;
		}
	}
	else// if the player is not at the start of the map
	{
		cout << "There is no IPO Centre here, you need to go back to Kuala Lumpur." << endl;
	}
	
}

void Player::BuyProperty(int aChoice, LocationIterator& aLocationIterator)
{
	if (aChoice == 1)
	{
		if (aLocationIterator.current()->GetApartment()->GetOwnershipStatus() == true)
		{
			cout << "You already owned this property" << endl;
		}
		else if (aLocationIterator.current()->GetApartment()->GetPrice() > fPlayerMoney)
		{
			cout << "You don't have enough funds at the moment" << endl;
		}
		else
		{
			fPlayerMoney -= aLocationIterator.current()->GetApartment()->GetPrice();
			fPlayerProperties.push_back(aLocationIterator.current()->GetApartment());
			fPlayerValuation += aLocationIterator.current()->GetApartment()->GetPrice();
			cout << "You have bought " << aLocationIterator.current()->GetApartment()->PropertyMessage() << endl;
			aLocationIterator.current()->GetApartment()->SetOwnershipStatus(true);
			
		}
	}
	else if (aChoice == 2)
	{
		if (aLocationIterator.current()->GetHouses()->GetOwnershipStatus() == true)
		{
			cout << "You already owned this property" << endl;
		}
		else if (aLocationIterator.current()->GetHouses()->GetPrice() > fPlayerMoney)
		{
			cout << "You don't have enough funds at the moment" << endl;
		}
		else
		{
			fPlayerMoney -= aLocationIterator.current()->GetHouses()->GetPrice();
			fPlayerProperties.push_back(aLocationIterator.current()->GetHouses());
			fPlayerValuation += aLocationIterator.current()->GetHouses()->GetPrice();
			cout << "You have bought " << aLocationIterator.current()->GetHouses()->PropertyMessage() << endl;
			aLocationIterator.current()->GetHouses()->SetOwnershipStatus(true);
			
		}
	}
	else if (aChoice == 3)
	{
		if (aLocationIterator.current()->GetHotel()->GetOwnershipStatus() == true)
		{
			cout << "You already owned this property" << endl;
		}
		else if (aLocationIterator.current()->GetHotel()->GetPrice() > fPlayerMoney)
		{
			cout << "You don't have enough funds at the moment" << endl;
		}
		else
		{
			fPlayerMoney -= aLocationIterator.current()->GetHotel()->GetPrice();
			fPlayerProperties.push_back(aLocationIterator.current()->GetHotel());
			fPlayerValuation += aLocationIterator.current()->GetHotel()->GetPrice();
			cout << "You have bought " << aLocationIterator.current()->GetHotel()->PropertyMessage() << endl;
			aLocationIterator.current()->GetHotel()->SetOwnershipStatus(true);
			
		}
	}
	else
	{
		cout << "That is an invalid number" << endl;
		return;
	}

}

void Player::SellProperty()
{
	if (!fPlayerProperties.empty())
	{
		cout << "Which property do you want to sell" << endl;
		for (int i = 0; i < fPlayerProperties.size(); i++)
		{
			cout << i + 1 << ". " << fPlayerProperties.at(i)->PropertyMessage() << endl;
		}
		int lResponse = NULL;
		cin >> lResponse;
		fPlayerMoney += fPlayerProperties.at(lResponse - 1)->GetSellPrice();
		fPlayerValuation -= fPlayerProperties.at(lResponse - 1)->GetPrice();
		fPlayerProperties.erase(fPlayerProperties.begin() + (lResponse - 1));
	}
	else
	{
		cout << "You don't have any properties at the moment" << endl;
	}
	
	
}

void Player::ObtainXPCard(PlayerXP* aPlayerXP)
{
	if (fPlayerXPReceived->ShowMessage() == "")
	{
		fPlayerXPReceived = aPlayerXP;
	}
	else
	{
		fPlayerXPReceived->SetTail(aPlayerXP);
	}
}

void Player::RemoveAllTaxes()
{

	while (!fPlayerTaxes.isEmpty())
	{
		fPlayerTaxes.dequeue();
	}
}

//method to determine player's taxes and add into queue
void Player::DetermineTaxes()
{
	if (fPlayerMovesCounter % 3 == 0 && !fPlayerProperties.empty())
	{
		int randNum = rand() % fPlayerProperties.size();
		fPlayerTaxes.enqueue(fPlayerProperties.at(randNum)->GetSellPrice());
	}
}

//Player Pays taxes and dequeus the top most item from the queue
void Player::PayTaxes()
{
	if (!fPlayerTaxes.isEmpty())
	{
		cout << "Tax you have to pay: $" << fPlayerTaxes.peek() << endl;
		cout << "Confirm payment? Y/N" << endl;
		char lResponse = NULL;
		cin >> lResponse;
		if (tolower(lResponse) == 'y')
		{
			cout << "You have paid $" << fPlayerTaxes.peek() << " of taxes" << endl;
			fPlayerMoney -= fPlayerTaxes.dequeue();
		}
		else if (tolower(lResponse) == 'n')
		{
			return;
		}
		else
		{
			cout << "Invalid input" << endl;
		}
	}
	else
	{
		cout << "You have no taxes to pay at the moment" << endl;
	}
}

void Player::GetPropertiesIncome()
{
	if (fPlayerMovesCounter % 5 == 0 && !fPlayerProperties.empty())
	{
		int randNum = rand() % fPlayerProperties.size();
		int ReceivedMoney = ceil(fPlayerProperties.at(randNum)->GetSellPrice() / 2);
		fPlayerMoney += ReceivedMoney;
		cout << "PROPERTY EARNING: You received $" << ReceivedMoney << " from your acquisition of " << fPlayerProperties.at(randNum)->PropertyMessage() << endl;
		system("pause");
	}
}



LocationIterator& Player::MoveForward(LocationIterator& aLocationIterator)
{
	fPlayerMovesCounter++;
	aLocationIterator++;
	return aLocationIterator;
}

LocationIterator& Player::MoveBackward(LocationIterator& aLocationIterator)
{
	fPlayerMovesCounter++;
	aLocationIterator--;
	return aLocationIterator;
}

LocationIterator& Player::DeterminePlayerMovement(LocationIterator& aLocationIterator)
{
	char lplayermove = NULL;
	if (aLocationIterator == aLocationIterator.end()) //The player can only move back if they reached the end of the game map
	{
		cout << "Where would you like to move?\n>> A. Move to the previous location" << endl;
		cout << "Please enter a move" << endl;
		while (lplayermove != 'a')
		{
			cout << "Please enter a move: ";
			cin >> lplayermove;
			lplayermove = tolower(lplayermove);
		}

		return MoveBackward(aLocationIterator);
	}
	else if (aLocationIterator == aLocationIterator.begin()) //The player can only move forward if they are at the start of the game map
	{
		cout << "Where would you like to move?\n>> A. Move to the next location" << endl;
		while (lplayermove != 'a')
		{
			cout << "Please enter a move: ";
			cin >> lplayermove;
			lplayermove = tolower(lplayermove);
		}
		return MoveForward(aLocationIterator);
	}
	else //When the player are anywhere between the start and the end
	{
		cout << "Where would you like to move?\n>> A.Move to the next location\n>> B.Move to the previous location" << endl;
		cin >> lplayermove;
		lplayermove = tolower(lplayermove);
		while (true)
		{
			if (lplayermove == 'a')
			{
				return MoveForward(aLocationIterator);
			}
			else if (lplayermove == 'b')
			{
				return MoveBackward(aLocationIterator);
			}
			else
			{
				cout << "Please Try again" << endl;
				cin >> lplayermove;
				lplayermove = tolower(lplayermove);
			}
		}
	}
}

void Player::DeterminePlayerActions(LocationIterator& aLocationIterator, IPOCentre* aIPOCentre)
{
	int luserChoice = 0;
	while (luserChoice != 5)
	{
		cout << "What would you like to do at this location?" << endl;
		cout << ">> 1. Start IPO\n>> 2. Buy Property\n>> 3. Sell your property\n>> 4. Pay Your Taxes\n>> 5. Make a move" << endl;
		cin >> luserChoice;

		if (luserChoice == 1) // Chooses to use the portal (only available at the first cave)
		{
			InitiateIPO(aLocationIterator,aIPOCentre);
			if (aIPOCentre->GetActivated())
			{
				break;
			}
		}
		else if (luserChoice == 2) //Chooses to Buy Property
		{
			if (aLocationIterator.current()->CheckHaveProperties() && !aLocationIterator.current()->CheckHaveOppurtunities())
			{
				int lPropertyToBuy;
				aLocationIterator.current()->ShowPropertyPrices();
				cout << "Select the property you want to buy: ";
				cin >> lPropertyToBuy;
				BuyProperty(lPropertyToBuy, aLocationIterator);
			}
			else
			{
				cout << "There are no properties here" << endl;
			}
			

		}
		else if (luserChoice == 3)
		{
			SellProperty();
		}
		else if (luserChoice == 4)
		{
			PayTaxes();
		}
		
		else if (luserChoice == 5) //Wants to move to another cave
		{
			return;
		}
		else // Invalid choice
		{
			cout << "That is not a valid choice, please try again" << endl;
		}
		cin.clear();
		cin.ignore();
	}
}

void Player::SetPlayerMoney(int aValue)
{
	fPlayerMoney = aValue;
}