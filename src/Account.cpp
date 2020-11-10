//Reference for assignment overload: https://docs.microsoft.com/en-us/cpp/cpp/assignment?view=msvc-160 and https://en.wikipedia.org/wiki/Assignment_operator_(C%2B%2B) and https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)#:~:text=The%20rule%20of%20three%20(also,copy%20assignment%20operator
#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <iomanip> 
#include "Account.h"
#include "Deposit.h"
using std::cout;
using std::cin;
using std::string;
using std::fixed;
using std::setprecision;
using std::ostream;
using std::endl;
using std::vector;

//   !!! Rule of three implemented in this class !!!

//-----------Constructor----------
Account::Account() : balance(0.f) {};



//-----------Methods----------
void Account::MakeDeposit(float amount)
{
	//Create a deposit obj
	Deposit* movement = new Deposit();
	//acess the method for the processing of this movement
	movement->ProcessAccountMovement(this, amount);
	delete(movement);
}

void Account::MakeWithdraw(float amount)
{
	//Check if balance is enough for the withdraw and if the argument is positive. The argument must always be positive.
	if (amount > balance || amount < 0) {
		cout << "Unable to withdraw more than your current balance of $" << balance <<endl;// Good place to generate an error to be cought by try catch execution of this method.  
	}
	else {
		//Create a deposit obj
		Deposit* movement = new Deposit();
		//Acess the method for the processing of this movement. 
		//The minus on the amount parameter will define if this movement is a withdraw Transaction type
		movement->ProcessAccountMovement(this, -amount);
		delete(movement);
	}
}

float Account::GetBalance()
{
	return balance;
}


//-----------Copy Constructor----------
Account::Account(const Account& copyFrom)
{
	//Copy value of balance from copyFrom to this
	balance = copyFrom.balance;
	//Add new transactions to this with the same values of copyFrom
	for (int i = 0; i < copyFrom.transactions.size(); i++)
	{
		transactions.push_back(new Transaction(copyFrom.transactions[i]->GetTransactionTimeStamp(), copyFrom.transactions[i]->GetTransactionAmount(), copyFrom.transactions[i]->GetTransactionType()));
	}
}

//-----------Assignment Overlead----------
Account& Account::operator=(const Account& copyFrom)
{
	//If trying to copy self just return self
	if (this == &copyFrom) {
		return *this;
	}

	//Copy value of balance from copyFrom to this
	balance = copyFrom.balance;

	//Clean transactions vector from this in order to be able to add new transactions with the same values of copyFrom
	for (int i = 0; i < transactions.size(); i++)
	{
		delete transactions[i];
	}

	//Add new transactions to this with the same values of copyFrom
	for (int j = 0; j < copyFrom.transactions.size(); j++)
	{
		transactions.push_back(new Transaction(copyFrom.transactions[j]->GetTransactionTimeStamp(), copyFrom.transactions[j]->GetTransactionAmount(), copyFrom.transactions[j]->GetTransactionType()));
	}
	return *this;
}

//----------Output Operator Overload---------------

//Overload to cout with ponter(*)
ostream& operator<<(ostream& os, const Account& ac)
{

	string blankSpace;
	int digitIterator;
	int digitCounter;
	const int MAXDIGITSONSTATEMENT = 15; //max number of digits on the statement cells
	float currentBalance = 0;
	os << "\n" << "***************************** Account Statement *****************************" << "\n\n" << endl;
	os << "           DATE          |" << "   TYPE   |" << "      MOVEMENT     |" << "      BALANCE      |" << endl;
	os << "-------------------------|" << "----------|" << "-------------------|" << "--------------------" << endl;
	for (int i = 0; i < ac.transactions.size(); i++)
	{
		//Accumulate the number of spaces necessary to alighn depending on the digit count of the balance value displayed
		blankSpace = "";
		//Number of whole digits of the balance
		digitCounter = 0;
		//Take in consideration the - sign on withdrawls
		ac.transactions[i]->GetTransactionType().compare("Deposit") == 0 ? digitCounter = 0 : digitCounter = 1;
		//For digit counting pourposes use absolute value
		digitIterator = abs(ac.transactions[i]->GetTransactionAmount());
		if (digitIterator == 0) {
			digitCounter += 1;
		}
		else {
			//Divide the number by 10 iterativelly in order to count the number of digits
			while (digitIterator > 0)
			{
				digitIterator = digitIterator / 10;
				digitCounter++;
			}
		}

		//Accumulate on blankSpace the number of spaces necessary to make the statement aligned
		for (int k = 0; k < MAXDIGITSONSTATEMENT - digitCounter; k++)
		{
			blankSpace += " ";
		}
		currentBalance += ac.transactions[i]->GetTransactionAmount();

		os << fixed << setprecision(2) << ac.transactions[i] << blankSpace << "| " << currentBalance << endl;
	}
	os << "--------------------------" << "-----------" << "--------------------" << "--------------------" << endl;
	os << "                          " << "***TOTAL:  " << "                     " << ac.balance << endl;
	return os;
}
//Overload to cout without ponter(*)
ostream& operator<<(ostream& os, const Account* ac)
{
	string blankSpace;
	int digitIterator;
	int digitCounter;
	const int MAXDIGITSONSTATEMENT = 15; //max number of digits on the statement cells
	float currentBalance = 0;
	os << "\n" << "***************************** Account Statement *****************************" << "\n\n"<< endl;
	os << "           DATE          |" << "   TYPE   |" << "      MOVEMENT     |" << "      BALANCE      |" << endl;
	os << "-------------------------|" << "----------|" << "-------------------|" << "--------------------" << endl;
	for (int i = 0; i < ac->transactions.size(); i++)
	{
		//Accumulate the number of spaces necessary to alighn depending on the digit count of the balance value displayed
		blankSpace = "";
		//Number of whole digits of the balance
		digitCounter = 0;
		//Take in consideration the - sign on withdrawls
		ac->transactions[i]->GetTransactionType().compare("Deposit") == 0 ? digitCounter = 0 : digitCounter = 1;
		//For digit counting pourposes use absolute value
		digitIterator = abs(ac->transactions[i]->GetTransactionAmount());
		if (digitIterator == 0) {
			digitCounter += 1;
		}
		else {
			//Divide the number by 10 iterativelly in order to count the number of digits
			while (digitIterator > 0)
			{
				digitIterator = digitIterator / 10;
				digitCounter++;
			}
		}

		//Accumulate on blankSpace the number of spaces necessary to make the statement aligned
		for (int k = 0; k < MAXDIGITSONSTATEMENT - digitCounter; k++)
		{
			blankSpace += " ";
		}
		currentBalance += ac->transactions[i]->GetTransactionAmount();

		os << fixed << setprecision(2) << ac->transactions[i] << blankSpace <<"| " << currentBalance << endl;
	}
	os << "--------------------------" << "-----------" << "--------------------" << "--------------------" << endl;
	os << "                          " << "***TOTAL:  " << "                     " << ac->balance << endl;
	return os;
}
	

//-----------Destructor----------
Account::~Account()
{
	for (int i = 0; i < transactions.size(); i++)
	{
		//cout << " transacion deleted " << transactions[i]->GetTransactionAmount() << endl;
		delete transactions[i];
		//delete &transactions;
	}
}