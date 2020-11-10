#include "Transaction.h"
#include <ctime>// Reference for the time: https://en.cppreference.com/w/cpp/chrono/c/time
#include <string>
#include <iostream>
using std::time_t;
using std::endl;
using std::cout;
using std::string;


//--------Friends-------
//Friend function to get the current time and date as a string
string GetTimeCurrentTimeAsString()
{
	time_t t = time(NULL);
	const int TCHARSIZE = 30;
	char tChar[TCHARSIZE];
	//I tried to use ctime instead of ctime_s but it was deprecated
	ctime_s(tChar, sizeof tChar, &t); //Reference for ctime_s https://en.cppreference.com/w/c/chrono/ctime
	string nowTime = tChar;
	//The last character is a \n therefore substr was used to take it out.
	return nowTime.substr(0, nowTime.size() - 1);
};

//--------Constructors-------
Transaction::Transaction( float transactionAmount, string transactionType) : transactionAmount(transactionAmount), transactionType(transactionType) 
{
	timeStamp = GetTimeCurrentTimeAsString();
};
//Overloaded constructor that have a timeStamp as parameter
Transaction::Transaction(string timeStamp, float transactionAmount, string transactionType) : timeStamp(timeStamp), transactionAmount(transactionAmount), transactionType(transactionType) {};

//--------Getters-------
string Transaction::GetTransactionTimeStamp() {
	return timeStamp;
};
float Transaction::GetTransactionAmount() {
	return transactionAmount;
};
string Transaction::GetTransactionType() {
	return transactionType;
};


//---------- Operator Overload---------------

//Output overloading
//Overload to cout with ponter(*)
ostream& operator<<(ostream& os, const Transaction& tr)
{

	//This if keeps the information aligned with the correct amount of spaces
	if (tr.transactionType.compare("Deposit") == 0) {
		os << tr.timeStamp << " | " << tr.transactionType << "  | " << tr.transactionAmount;
	}
	else {
		os << tr.timeStamp << " | " << tr.transactionType << " | " << tr.transactionAmount;
	}
	return os;
}
//Overload to cout without ponter(*)
ostream& operator<<(ostream& os, const Transaction* tr)
{
	//This if keeps the information aligned with the correct amount of spaces
	if (tr->transactionType.compare("Deposit") == 0) {
		os << tr->timeStamp << " | " << tr->transactionType << "  | " << tr->transactionAmount;
	}
	else {
		os << tr->timeStamp << " | " << tr->transactionType << " | " << tr->transactionAmount;
	}
		
	return os;
}




