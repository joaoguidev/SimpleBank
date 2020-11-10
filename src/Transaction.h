#pragma once
#include <string>
#include <iostream>
#include <ctime>// Reference for the time: https://en.cppreference.com/w/cpp/chrono/c/time
using std::string;
using std::ostream;

class Transaction
{
private:
	string timeStamp;
	float transactionAmount;
	string transactionType;
public:
	//--------Constructor-------
	Transaction( float transactionAmount, string transactionType);
	Transaction( string timeStamp, float transactionAmount, string transactionType);
	//--------Getters-------
	string GetTransactionTimeStamp();
	float GetTransactionAmount();
	string GetTransactionType();
	//--------Setters-------
	// No setters for security reasons.

	friend ostream& operator<<(ostream& os, const Transaction& tr);
	friend ostream& operator<<(ostream& os, const Transaction* tr);
	friend string GetTimeCurrentTimeAsString();
};

ostream& operator<<(ostream& os, const Transaction& tr);
ostream& operator<<(ostream& os, const Transaction* tr);
