//Student : Joao Dantas
//SID: 2032559
//This program creates a simple banking system with accounts with capabilities of moving money on it

#include "Account.h"
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

//Turns any A-Z character into its respective lowercase
char ToLowerCaseLetter(char letter) {
	if (letter >= 65 && letter <= 90) {
		return letter + 32;
	}
	else {
		return letter;
	}
}


void DisplayMenu() {

	cout << "         Welcome to Simple Bank Corp. " << endl;
	cout << "********************************************" << endl;
	cout << "*        Please select a transaction       *" << endl;
	cout << "*        [1] -> Deposit                    *" << endl;
	cout << "*        [2] -> Withdrawal                 *" << endl;
	cout << "*        [3] -> Balance Inquiry            *" << endl;
	cout << "*        [4] -> Close Account              *" << endl;
	cout << "*        [0] -> Exit                       *" << endl;
	cout << "*                                          *" << endl;
	cout << "********************************************" << endl;
}

//Get what transaction the user want to do.
int GetUserTransaction(int totalNumberOfOptions) 
{
	int uIn = -1;
	while (uIn < 0 || uIn > totalNumberOfOptions -1) 
	{
		system("cls");
		DisplayMenu();
		if (uIn != -1) {
			cout << "Please Select a transaction Between 0 and 4 only: ";
		}
		else {
			cout << "         Select: ";
		}
		cin >> uIn;
	}
	return uIn;
}

//Define if the user whant to do another operation or not.
bool ContinueOrNot() {
	char uIn = 'z';
	while (ToLowerCaseLetter(uIn) != 'y' && ToLowerCaseLetter(uIn) != 'n') {
		cout << "\n"<< "Would you like to perform another operation? [Y,N] ";
		cin >> uIn;
	}

	if (ToLowerCaseLetter(uIn) == 'y') {
		return true;
	}
	else {
		return false;
	}
}


//************************* Main *************************
int main()
{

	Account* ac = new Account();
	bool bPlayAgain = true;
	float userInput;

	while (bPlayAgain) {

		switch (GetUserTransaction(5)) {
		case 1://Deposit
			system("cls");
			userInput = -1;
			cout << "What amount would you like to deposit: ";
			cin >> userInput;
			//0.009 because no franction of cent is allowed
			while (userInput < 0.009) {
				system("cls");
				cout << "Please type a positive amount to deposit: ";
				cin >> userInput;
			}
			ac->MakeDeposit(userInput);
			break;
		case 2://Withdrawal
			system("cls");
			if (ac->GetBalance() == 0) {
				cout << "You are unable to withdraw. Your corrent balance is $0.00 "<< endl;
			}
			else {
				userInput = -1;
				cout << "What amount would you like to Withdraw: ";
				cin >> userInput;
				//0.009 because no franction of cent is allowed
				while (userInput < 0.009) {
					system("cls");
					cout << "Please type a positive amount to Withdraw: ";
					cin >> userInput;
				}
				ac->MakeWithdraw(userInput);
			}
			break;
		case 3://Balance Inquiry 
			system("cls");
			cout << ac; //output operator overloaded
			break;
		case 4://Close Account 
			system("cls");
			delete ac;
			cout << "Account deleted. We hope to see you back soon." << endl;
			cin.get();
			bPlayAgain = false;
			break;
		default://Exit
			delete ac;//For this exercise the account does not have to persist. Cleaning memory.
			bPlayAgain = false;
			break;
		}

		//If in some case of the switch it was defined not to continue the user will not be asked again.
		if (bPlayAgain) {
			bPlayAgain = ContinueOrNot();
		}
	}
}