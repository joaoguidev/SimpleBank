#include "Deposit.h"
#include "Account.h"
#include "Transaction.h"
using std::cout;
using std::endl;


//-----------Constructor----------
Deposit::Deposit() { };

void Deposit::ProcessAccountMovement(Account* ac, float amount) {
	ac->balance += amount;
	ac->transactions.push_back( new Transaction( amount, amount > 0 ? "Deposit":"Withdraw"));
}