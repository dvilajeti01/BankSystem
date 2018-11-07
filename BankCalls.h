#pragma once

#include <iostream>
#include <string>
using namespace std;


class Bank
{
private:

	string first_name;
	string last_name;
	long int AC_Num;
	int balance;

public:


	string showF_Name()
	{
		return first_name;
	}

	string showL_Name()
	{
		return last_name;
	}

	long int showAccount_Num()
	{
		return AC_Num;
	}

	int showBalance()
	{
		return balance;
	}
	void getName(string, string);
	void getAccount_Num(long int);
	void withdraw(int);
	void deposit(int);

};
