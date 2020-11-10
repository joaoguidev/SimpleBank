#pragma once
#include "Account.h"
#include <iostream>


class Deposit
{
	friend class Account;
private:
	//For security reasons I opted to make this methods private. It is a bank afterall
	void ProcessAccountMovement(Account* ac, float amount);

public:
	Deposit();
};



