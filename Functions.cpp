#include "BankCalls.h"

void Bank::getName(string first, string last)
{

	first_name = first;

	last_name = last;


}



void Bank::getAccount_Num(long int AC)
{

	AC_Num = AC;
}



void Bank::withdraw(int ammount)
{

	balance = balance - ammount;

}

void Bank::deposit(int amount)
{

	balance = balance + amount;

}
