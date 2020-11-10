//Friend Class Source: https://docs.microsoft.com/en-us/cpp/cpp/friend-cpp?view=msvc-160 and https://www.geeksforgeeks.org/friend-class-function-cpp/
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Transaction.h"

using std::string;
using std::ostream;
using std::vector;

class Account
{
	friend class Deposit;
private:
	float balance;
	vector<Transaction*> transactions;


public:
	Account();
	void MakeDeposit(float amount);
	void MakeWithdraw(float amount);
	float GetBalance();
	Account(const Account& copyFrom);
	Account& operator=(const Account& copyFrom);
	friend ostream& operator<<(ostream& os, const Account& ac);
	friend ostream& operator<<(ostream& os, const Account* ac);
	~Account();
};

ostream& operator<<(ostream& os, const Account& ac);
ostream& operator<<(ostream& os, const Account* ac);

