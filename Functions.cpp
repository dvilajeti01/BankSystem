#include "Bank_Functions.h"



sql::mysql::MySQL_Driver *driver;
sql::Connection *con;
sql::Statement *stmt;
sql::ResultSet *res;
sql::PreparedStatement *prep_stmt;



void Main_Interface()
{
    
    cout << "     WELCOME MANHATTAN COLLEGE BANK" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Employee Login" << endl;
    cout << "2. Costumer Login" << endl;
    cout << "3. Create Account" << endl;
    cout << "4. Exit" << endl;
    
    
}

void Employee_Interface()
{
    
    cout << "1. Register New Customer" << endl;
    cout << "2. Approve Transactions" << endl;
    cout << "3. Customer Transaction History" << endl;
    cout << "4. Exit" << endl;
    
    
}

void Customer_Interface()
{
    
    cout << "1. Make a Transaction" << endl;
    cout << "2. View Transaction History" << endl;
    cout << "3. Delete Account" << endl;
    cout << "4. Exit" << endl;
    
    
}


int NewCustomer_Interface()
{
    string SSN;
    string FName;
    string LName;
    string Address;
    string Home_Phone;
    string Cell_Phone;
    string DOB;
    int AC_ID;
    
    //takes as input all the attributes in the customer table
    cout << "To create new account please fill in the required fields below: " << endl;
    cout <<"SSN: ";
    cin >> SSN;
    cout <<"First Name: ";
    cin >> FName;
    cout <<"Last Name: ";
    cin >> LName;
    cout <<"Address: ";
    cin.ignore();
    getline(cin,Address, '\n');
    cout <<"Home Phone number: ";
    cin >> Home_Phone;
    cout <<"Celphone Number: ";
    cin >> Cell_Phone;
    cout <<"Birthday: (mm_dd_yyyy) ";
    cin >> DOB;
    
    if (Create_Customer(SSN,FName, LName,Address,Home_Phone,Cell_Phone,DOB)) //calls function to create new customer instance using previously input attributes as parameters
    {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "root1234");
        con->setSchema("Bank");
        stmt = con->createStatement();
        res = stmt->executeQuery("select count(ID) from Account");
        
        
        //returns auto incremented ID to ensure uniqueness
        while(res->next())
        {
            AC_ID = res->getInt(1);
        }
        
        delete res;
        delete stmt;
        delete con;
        
        return AC_ID;
    }
    else
    {
        return -1;
    }
    
}


void Approve_Interface()
{
    
    
    cout << "Below are transactions pending approval." << endl << "Select the one you wish to approve by inputing Transaction ID" << endl;
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "root1234");
    stmt = con->createStatement();
    stmt->execute("Use Bank");
    res = stmt->executeQuery("select * from Transaction where Status = 'Pending'");
    
    
    while (res->next()) //displays all "pending" transaction the employee could approve
    {
        cout << res->getInt(1)<<" " << res->getString(2) <<" " << res->getString(3) <<" " << res->getString(4) <<" " <<res->getInt(5) <<" " <<res->getInt(6)  << endl;
    }
    delete stmt;
    delete res;
    delete con;
    
    
    
}

void Info_Interface(string person)
{
    cout << "Below is the transaction log: " << endl;
    
    fetch_transHist(person); //displays trascation history
    
}

void make_Transaction(int ID,string type, int sum)
{
    
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "root1234");
    con->setSchema("Bank");
    //creates a new transaction instance
    prep_stmt = con->prepareStatement("insert into Transaction (T_Type,Status,Date,Sum, Ac_ID) values (?,?,?,?,?)");
    prep_stmt->setString(1,type);
    prep_stmt->setString(2,"pending");
    prep_stmt->setString(3,curr_date);
    prep_stmt->setInt(4,sum);
    prep_stmt->setInt(5,ID);
    prep_stmt->executeQuery();
    
    delete prep_stmt;
    delete con;
    
    cout << "**TRANSACTION POSTED WAIT FOR APPROVAL**" << endl;
    
}

void DeleteAcc(int ID) //deletes account instance that matches ID
{
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "root1234");
    con->setSchema("Bank");
    prep_stmt = con->prepareStatement("delete from Account where ID = (?)");
    prep_stmt->setInt(1,ID);
    prep_stmt->executeQuery();
    
    delete prep_stmt;
    delete con;
    
    cout << "**ACCOUNT SUCCESFULLY DELETED**" <<endl;
    
}

bool check_employee(int ID) //checks to see if employee exists
{
    
    
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "root1234");
    con->setSchema("Bank");
    stmt = con->createStatement();
    // stmt->execute("Use Bank");
    prep_stmt = con->prepareStatement("select Emp_ID from Employee where Emp_ID = (?)");
    prep_stmt->setInt(1,ID);
    res = prep_stmt->executeQuery();
    
    if(res->next())
    {
        delete res;
        delete stmt;
        delete con;
        return true;
    }
    else
    {
        delete res;
        delete stmt;
        delete con;
        return false;
    }
    
    
}




bool Create_Customer(string SSN,string FName, string LName, string Address,string Home_Phone,string Cel_Phone,string DOB)
{
    string type;
    string branch;
    
    
    if(!check_customer(SSN)) //if customer SSN is unique append the new instance
    {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "root1234");
        con->setSchema("Bank");
        stmt = con->createStatement();
        //creates customer based on info from passed parameers
        prep_stmt = con->prepareStatement("insert into customer values (?,?,?,?,?,?,?) ");
        prep_stmt->setString(1,SSN);
        prep_stmt->setString(2,FName);
        prep_stmt->setString(3,LName);
        prep_stmt->setString(4,Address);
        prep_stmt->setString(5,Home_Phone);
        prep_stmt->setString(6,Cel_Phone);
        prep_stmt->setString(7,DOB);
        prep_stmt->executeQuery();
        
        delete prep_stmt;
        delete stmt;
        delete con;
        
        
        cout << "What type of Account would you like to open? (C/S)" << endl;
        cin >> type;
        
        cout << "Which branch are you currently at?" << endl;
        cin >> branch;
        
        //Opens account for new customer
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "root1234");
        con->setSchema("Bank");
        stmt = con->createStatement();
        prep_stmt = con->prepareStatement("insert into Account(SSN,Balance,Type,B_name) values (?,?,?,?) ");
        prep_stmt->setString(1,SSN);
        prep_stmt->setInt(2,0);
        prep_stmt->setString(3,type);
        prep_stmt->setString(4,branch);
        prep_stmt->executeQuery();
        
        delete res;
        delete stmt;
        delete prep_stmt;
        delete con;
    
        return true;
    }
    else
    {
        delete res;
        delete prep_stmt;
        delete stmt;
        delete con;
        
        return false;
    }
}

bool check_customer(string SSN) //checks to see if SS is unique
{
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "root1234");
    stmt = con->createStatement();
    stmt->execute("Use Bank");
    prep_stmt = con->prepareStatement("select SSN from Customer where SSN = (?)");
    prep_stmt->setString(1,SSN);
    res = prep_stmt->executeQuery();
    
    if(res->next())
    {
        delete res;
        delete prep_stmt;
        delete stmt;
        delete con;
        
        return true;
    }
    else
    {
        delete res;
        delete prep_stmt;
        delete stmt;
        delete con;
        
        return false;
    }
}

bool check_account(int AC_ID) //checks to see if account already exists
{
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "root1234");
    
    con->setSchema("Bank");
    stmt = con->createStatement();
    prep_stmt = con->prepareStatement("select ID from Account where ID = (?)");
    prep_stmt->setInt(1,AC_ID);
    res = prep_stmt->executeQuery();
    
    if(res->next())
    {
        delete res;
        delete stmt;
        delete prep_stmt;
        delete con;
        return true;
    }
    else
    {
        delete res;
        delete stmt;
        delete prep_stmt;
        delete con;
        return false;
    }
}



bool Approve_Transaction(int Trans_ID, int Emp_ID) //updates tables for approved tranactions
{
    int sum;
    int AC_ID;
    
    
    
    delete prep_stmt;
    
    
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "root1234");
    
    con->setSchema("Bank");
    stmt = con->createStatement();
    prep_stmt = con->prepareStatement("select AC_ID, Sum from Transaction where Trans_ID = (?)");
    prep_stmt->setInt(1,Trans_ID);
    res = prep_stmt->executeQuery();
    
    res->next();
    AC_ID  = res->getInt(1);
    sum = res->getInt(2);
    
    
    delete prep_stmt;
    delete res;
    
    //updates respective account balance based on the sum of approved transaction
    prep_stmt = con->prepareStatement("update Account set Balance = Balance + (?) where ID = (?)");
    prep_stmt->setInt(1,sum);
    prep_stmt->setInt(2,AC_ID);
    prep_stmt->executeQuery();
    
    delete prep_stmt;
    
    //marks transaction instance as "approved"
    prep_stmt = con->prepareStatement("update Transaction set Status = 'Aproved' where Trans_ID = (?)");
    prep_stmt->setInt(1,Trans_ID);
    prep_stmt->executeQuery();
    
    delete prep_stmt;
    
    //records who approved transaction, which transaction and when it was approved into aproves table
    prep_stmt = con->prepareStatement("insert into Approves values (?,?,?)");
    prep_stmt->setInt(1,Trans_ID);
    prep_stmt->setInt(2,Emp_ID);
    prep_stmt->setString(3,curr_date);
    prep_stmt->executeQuery();
    
    delete prep_stmt;
    delete stmt;
    delete con;
    
    return true;
    
    
}


bool fetch_transHist(string Person)
{
    int ID;
    
    if (Person == "Employee") //displays all transaction info
    {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "root1234");
        stmt = con->createStatement();
        stmt->execute("Use Bank");
        res = stmt->executeQuery("select * from Transaction natural join Account where Account.ID  = AC_ID ");
        
        while(res->next())
        {
            cout<< res->getInt(1);
            cout << " ";
            cout<< res->getString(2);
            cout << " ";
            cout<< res->getString(3);
            cout << " ";
            cout<<res->getString(4);
            cout << " ";
            cout<<res->getInt(5);
            cout << " ";
            cout<<res->getInt(6);
            cout << " ";
            cout<<res->getInt(7);
            cout << " ";
            cout<<res->getString(8);
            cout << " ";
            cout<<res->getInt(9);
            cout << " ";
            cout<<res->getString(10);
            cout << " ";
            cout<<res->getString(11);
            cout << endl;
        }
        delete res;
        delete stmt;
        delete con;
    }
    else //displays transaction info only for specific customer
    {
        cout << "Enter account ID: ";
        cin >> ID;
        cout << endl;
        
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "root1234");
        stmt = con->createStatement();
        stmt->execute("Use Bank");
        prep_stmt = con->prepareStatement("select * from Transaction natural join Account where Account.ID  = AC_ID and AC_ID = (?)");
        prep_stmt->setInt(1,ID);
        res = prep_stmt->executeQuery();
        
        while(res->next())
        {
            cout<< res->getInt(1);
            cout << " ";
            cout<< res->getString(2);
            cout << " ";
            cout<< res->getString(3);
            cout << " ";
            cout<<res->getString(4);
            cout << " ";
            cout<<res->getInt(5);
            cout << " ";
            cout<<res->getInt(6);
            cout << " ";
            cout<<res->getInt(7);
            cout << " ";
            cout<<res->getString(8);
            cout << " ";
            cout<<res->getInt(9);
            cout << " ";
            cout<<res->getString(10);
            cout << " ";
            cout<<res->getString(11);
            cout << endl;
        }
        delete res;
        delete stmt;
        delete prep_stmt;
        delete con;
        
    }
    
    return true;
    
}









    

