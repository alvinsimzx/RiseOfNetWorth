// RiseOfNetWorth.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Location.h"
#include "Queue.h"
#include "Player.h"
#include "Stack.h"
#include "PlayerXP.h"
#include "LocationIterator.h"
#include "OppurtunityCard.h"
#include "DialogueTree.h"
#include "FinalDialogue.h"
#include "MainDialogueVisitor.h"
#include "GameEndVisitor.h"
#include "IPOCentre.h"
#include "SendInvitation.h"
#include <fstream>


using namespace std;
int main()
{
    ofstream WriteFile;
    ifstream ReadFile;
    while (true)
    {
        system("cls");
        cout << R"(

 ____  _  ____  _____   ____  _____   _      _____ _____    _      ____  ____  _____  _    
/  __\/ \/ ___\/  __/  /  _ \/    /  / \  /|/  __//__ __\  / \  /|/  _ \/  __\/__ __\/ \ /|
|  \/|| ||    \|  \    | / \||  __\  | |\ |||  \    / \    | |  ||| / \||  \/|  / \  | |_||
|    /| |\___ ||  /_   | \_/|| |     | | \|||  /_   | |    | |/\||| \_/||    /  | |  | | ||
\_/\_\\_/\____/\____\  \____/\_/     \_/  \|\____\  \_/    \_/  \|\____/\_/\_\  \_/  \_/ \|
                                                                                           

)" << '\n';
        int lUserChoice;
        cout << "Game Menu (Choose what to do from 1-4)" << endl;
        cout << "[1] Play Game\t[2] Check Game History\t[3] Invite your friends to play!\t[4] Exit game" << endl;
        cin >> lUserChoice;


        if (lUserChoice == 1)
        {
            //Player XP Stack Initialised
    //Answer is "jeff"
            Stack<PlayerXP*> lPlayerXPStack(3);
            lPlayerXPStack.push(new PlayerXP("He is an American"));
            lPlayerXPStack.push(new PlayerXP("His company's name is similar to a river's name"));
            lPlayerXPStack.push(new PlayerXP("He once said he couldn't spend the money he earns even if he tries"));

            //Oppurtunity Card Stack Initialised
            Stack<OppurtunityCard*> lOppurtunityCardStack(10);
            lOppurtunityCardStack.push(new OppurtunityCard("YOU BOUGHT SOME NEW BOATS FOR $500", 500, false));
            lOppurtunityCardStack.push(new OppurtunityCard("YOU BOUGHT SOME NEW SHOES FOR $100", 100, false));
            lOppurtunityCardStack.push(new OppurtunityCard("YOU HAD BEEN FINED $200 FOR ILLEGAL PARKING", 200, false));
            lOppurtunityCardStack.push(new OppurtunityCard("YOU WON THE LOTTERY! $1000 IS YOURS!", 1000, true));
            lOppurtunityCardStack.push(new OppurtunityCard("FREE STIMULAS $500 MONEY", 500, true));
            lOppurtunityCardStack.push(new OppurtunityCard("YOU HAD TO PAY $100 FOR A BIRTHDAY PARTY", 100, false));
            lOppurtunityCardStack.push(new OppurtunityCard("LUCKY DRAW WINNER OF $500!", 500, true));
            lOppurtunityCardStack.push(new OppurtunityCard("YOUR STOCK INVENSTMENTS RETURNED $500", 500, true));
            lOppurtunityCardStack.push(new OppurtunityCard("YOU JAYWALKED AND NEED TO PAY A $200 FINE", 200, false));
            lOppurtunityCardStack.push(new OppurtunityCard("RECEIVE $500 TO START YOUR JOURNEY", 500, true));

            //Court Trial Dialogue Tree Initialised
            DialogueTree CourtTree("You're called in because you are thought to be evading taxes and you may need to serve time in prison. Anything to say?", "You are making a grave mistake.", "I have my reasons");
            CourtTree.AttachANode("That's just a red flag. Off to prison you go!", "NOOOOOOOO", "I NEVER LIKED THIS SYSTEM!");
            CourtTree.AttachBNode("Well then, mind explaining what it is?", "It ain't wrong not to pay taxes once in a while.", "I have the right documents to prove my innocence.");
            CourtTree.GetBNode()->AttachANode("That's not cool. You should either retract your statement or you'll be going to jail sir.", "I stand by my word", "Fine. I retract my statement.");
            CourtTree.GetBNode()->GetANode()->AttachANode("Well Suit yourself. Have fun in prison!", "THIS IS NOT RIGHT!", "Just you wait.");
            CourtTree.GetBNode()->GetANode()->AttachBNode("Good. Now we'll just give you $1000 in fine so don't do it ever again!", "Yeah totally (sarcastic laugh)", "Yes, I won't at all!");
            CourtTree.GetBNode()->AttachBNode("They don't look right to me but you can just pay a $500 fine for now.", "THAT'S RUBBISH!", "Sure then.");


            CourtTree.GetANode()->SetReturnCode(1);
            CourtTree.GetBNode()->GetBNode()->SetReturnCode(3);
            CourtTree.GetBNode()->GetANode()->GetANode()->SetReturnCode(1);
            CourtTree.GetBNode()->GetANode()->GetBNode()->SetReturnCode(2);


            FinalDialogue IPOCentreTree("Jeff: Welcome to the IPO Centre, young lad.");
            IPOCentreTree.AttachANode("Jeff: We Hope to see you earn more as time passes!. Gotta make sure you stay humble!");


            MainDialogueVisitor CourtTreeVisitor = MainDialogueVisitor();
            GameEndVisitor IPOCentreTreeVisitor = GameEndVisitor();
            int lplayeroutcome = 0;


            string lPlaceNames[12] = { "Kota Bahru","Alor Setar","Kuala Terengganu","Kangsar","Kuantan","Ipoh","Kota Kinabalu","Kuching","Georgetown","Malacca","Seremban","Johor Bahru" };
            int listCounter = 0;

            Location* KualaLumpur = new Location("Kuala Lumpur", 0, false);

            Location* tempLocation = KualaLumpur;
            for (int i = 0; i < 16; i++)
            {
                if ((i == 4) || (i == 7) || (i == 9) || (i == 13))
                {
                    tempLocation->SetNextForward(new Location("Oppurtunity Slot", true));
                    tempLocation = tempLocation->GetNextLocation();
                }
                else
                {
                    if (listCounter == 2 || listCounter == 5 || listCounter == 11)
                    {
                        tempLocation->SetNextForward(new Location(lPlaceNames[listCounter], true, (listCounter) * 100, (listCounter + 1) * 100, (listCounter + 2) * 100));
                    }
                    else
                    {
                        tempLocation->SetNextForward(new Location(lPlaceNames[listCounter], (listCounter + 1) * 100, (listCounter + 2) * 100, (listCounter + 3) * 100));
                    }
                    tempLocation = tempLocation->GetNextLocation();
                    listCounter++;
                }

            }


            string lPlayerName;
            cout << "Please enter your first name: ";
            cin >> lPlayerName;
            Player* player1 = new Player(lPlayerName);
            system("cls");

            LocationIterator iter(KualaLumpur);
            IPOCentre* GameIPOCentre = new IPOCentre();

            //Node to represent the current gamemap the player is in
            Location* lCurrentNode = iter.current();
            Location* tempLocation2 = KualaLumpur;

            cout << "Storyline: \n" << endl;
            cout << "You are the owner of a new Real Estate Company and your main goal is to start an IPO with the company.\nBut to do so, you would have to purchase a set of properties to increase your own net worth, which shows your worthiness to start this IPO!" << endl;
            cout << "HOWEVER, it's not going to be a smooth ride. \nBe ready to pay TAXES for your properties and FINES if you break any rules.\nTherefore, MANAGE YOUR BUDGET PROPERLY!" << endl;
            cout << "\n\nWe'll see you on the other side. Hopefully not behind bars." << endl;
            system("pause");

            while (true)
            {
                if (player1->GetPlayerMoney() < 0)
                {
                    break;
                }

                player1->DetermineTaxes();

                if (player1->GetPlayerTaxes().size() > 2)
                {
                    system("cls");
                    cout << "YOU DID NOT PAY TAXES 3 TIMES IN A ROW AND NOW U ARE BRING PROSECUTED" << endl;
                    cout << "Choose your responses in this court trial to ensure your survival" << endl;
                    system("pause");
                    lplayeroutcome = CourtTree.accept(CourtTreeVisitor);
                    if (lplayeroutcome == 1)
                    {
                        cout << "Court Trial Result: You went to jail for not paying taxes" << endl;
                        system("pause");
                        break;
                    }
                    else if (lplayeroutcome == 2)
                    {
                        cout << "Court Trial Result: You need to pay a $1000 fine" << endl;
                        system("pause");
                        player1->SetPlayerMoney((player1->GetPlayerMoney() - 1000));
                    }
                    else if (lplayeroutcome == 3)
                    {
                        cout << "Court Trial Result: You need to pay a $500 fine" << endl;
                        system("pause");
                        player1->SetPlayerMoney((player1->GetPlayerMoney() - 500));
                    }
                    player1->RemoveAllTaxes();
                }
                player1->ShowPlayerInfo(iter);
                player1->GetPropertiesIncome();

                if (lCurrentNode->CheckHaveOppurtunities() and !lOppurtunityCardStack.isEmpty())
                {
                    cout << "\nOPPURTUNITY CARD MESSAGE: " << lOppurtunityCardStack.top()->GetCardMessage() << endl;
                    if (lOppurtunityCardStack.top()->GetCardBeneficial())
                    {
                        lOppurtunityCardStack.top()->AddPlayerMoney(player1);
                    }
                    else
                    {
                        lOppurtunityCardStack.top()->DeductPlayerMoney(player1);
                    }
                    lOppurtunityCardStack.pop();
                }
                else if (lCurrentNode->CheckHaveOppurtunities() and lOppurtunityCardStack.isEmpty())
                {
                    cout << "This is an oppurtunity slot, but you ran out of Oppurtunity Cards" << endl;
                }

                if (lCurrentNode->CheckHaveXPCard() && !lPlayerXPStack.isEmpty())
                {
                    cout << "You Received an XP Card: " << endl;
                    cout << lPlayerXPStack.top()->ShowMessage() << endl;
                    system("pause");

                    player1->ObtainXPCard(lPlayerXPStack.top()); //problem w last clue
                    lPlayerXPStack.pop();
                    lCurrentNode->SetHasXP(false);
                }


                player1->DeterminePlayerActions(iter, GameIPOCentre);
                if (GameIPOCentre->GetActivated())
                {
                    break;
                }
                player1->ShowPlayerInfo(iter);
                iter = player1->DeterminePlayerMovement(iter);
                lCurrentNode = iter.current();
            }

            if (GameIPOCentre->GetActivated())
            {
                system("cls");
                IPOCentreTree.accept(IPOCentreTreeVisitor);
                cout << "CONGRATULATIONS! YOU WON!" << endl;
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                cout << "GAME OVER! Please try again." << endl;
                system("pause");
                system("cls");
            }

            WriteFile.open("GameHistory.txt", ios_base::app);
            string lPlayerSuccess;
            if (GameIPOCentre->GetActivated())
            {
                lPlayerSuccess = "Success";
            }
            else
            {
                lPlayerSuccess = "Lost";
            }
            WriteFile << player1->GetPlayerName() << "\t" << player1->GetPlayerValuation() << "\t\t" << lPlayerSuccess << endl;
            WriteFile.close();
        }
        else if (lUserChoice == 2)
        {
            ReadFile.open("GameHistory.txt", ios::in);
            if (ReadFile.is_open())
            {   //checking whether the file is open
                string tp;
                cout << "\nGame History" << endl;
                cout << "Name\tValuation ($)\tWin?\n" << endl;
                while (getline(ReadFile, tp))
                { //read data from file object and put it into string.
                    cout << tp << "\n"; //print the data of the string
                }
                ReadFile.close(); //close the file object.
                system("pause");

            }
        }
        else if (lUserChoice == 3)
        {
            cout << "Enter your friend's email address: ";
            string lUserEmail;
            cin >> lUserEmail;
            cout << "Sending invitation, please wait for a moment..." << endl;
            SendInvitation lSendInvite(lUserEmail);

            }
            else if (lUserChoice == 4)
            {
                break;
            }
            else
            {
                cout << "That is an invalid choice. Please try again." << endl;
            }
        }
        return 0;
    }

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
