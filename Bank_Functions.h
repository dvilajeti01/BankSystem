#include <iostream>
#include <cstdlib>
#include <string.h>


#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;


//GLOBAL VARIABLES
static string curr_date;


void Main_Interface(); //Main Menu
void Employee_Interface(); //Menu when loged in as Employee
void Approve_Interface(); //Displays all "pending" transaction
void Customer_Interface(); //Menu when logedin as existing customer
int NewCustomer_Interface(); //Menu for new customers
void Info_Interface(string person); // takes input on what type of info is to be displayed
void DeleteAcc(int ID); //deletes a row from table account if it matches parameter
bool check_employee(int ID); //checks if employee exists
bool check_customer(string SSN); //checks if customer SSN exists
bool Create_Customer(string SSN,string FName, string LName, string Address,string Home_Phone,string Cel_Phone,string DOB); //creates a new instance in the customer table
bool Approve_Transaction(int Trans_ID,int Emp_ID); //returns true if tables succefully updated
bool fetch_transHist(string Person); //outpts transaction history for eother all customers or specific customer
void make_Transaction(int ID,string type, int sum); //adds new transaction instance to transaction table
bool check_account(int AC_ID); //checks if an account exists
