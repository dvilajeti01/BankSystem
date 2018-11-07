void main_Interface();
void Create_Account();
void Print_Info();
void withdraw();
void deposit();
void Print_Info();
int search_account(long int AC);



int choice = 0;
static int n = 0;
Bank Account[10];



int main()
{
    do
    {
        
        main_Interface();
        
        
        switch (choice)
        {
            case 1:
                Create_Account();
                break;
                
            case 2:
                deposit();
                break;
                
            case 3:
                withdraw();
                break;
                
            case 4:
                Print_Info();
                break;
                
            case 5:
                break;
                
                
        }
        
    } while (choice == 0);
    
    return 0;
}

void main_Interface()
{
    
    cout << "========================================" << endl;
    cout << "\t  WELCOME TO VILAJETI BANK \t" << endl;
    cout << "========================================" << endl << "\n\n";
    
    cout << "1. CREATE ACCOUNT \n";
    cout << "2. DEPOSIT MONEY \n";
    cout << "3. WITHDRAW MONEY \n";
    cout << "4. GET ACCOUNT INFO \n\n\n";
    cout << "5. EXIT\n";
    
    cin >> choice;
    
    
}

void Create_Account()
{
    string first;
    string last;
    
    
    
    long int AC = 10000000;
    
    
    cout << "HELLO NEW USER!\n\n";
    cin.ignore();
    cout << "Enter you first name: ";
    getline (cin,first);
    
    cout << "\nEnter you last name: ";
    getline (cin,last);
    
    Account[n].getName(first, last);
    n++;
    
    
    Account[n-1].getAccount_Num(AC+n);
    
    cout<< "\nYOUR ACCOUNT NUMBER IS: " << Account[n-1].showAccount_Num();
    
    cout << "\n\nTO EXIT PRESS '0' ";
    cin >> choice;
    
    
}

void withdraw()
{
    int ammount;
    long int account_num;
    int i;
    
    cout << "\nTO WITHDRAW MONEY PLEASE ENTER ACCOUNT NUMBER: ";
    cin >> account_num;
    
    i = search_account(account_num);
    
    if(i != -1)
    {
        
        cout << "\nEnter the amount you would like to withdraw: ";
        cin >> ammount;
        
        if(ammount > Account[i].showBalance())
        {
            cout<<"PLEASE ENTER A SMALLER AMMOUNT";
            cin >> ammount;
        }
        
        Account[i].withdraw(ammount);
    }
    else
        withdraw();
    
    cout << "\n\nTO EXIT PRESS '0' ";
    cin >> choice;
    
    
    
    
}
void deposit()
{
    int ammount;
    long int account_num;
    
    cout << "\nTO DEPOSIT MONEY PLEASE ENTER ACCOUNT NUMBER: ";
    cin >> account_num;
    
    if (search_account(account_num) != -1)
        
    {    cout << "\nEnter the amount you would like to deposit: ";
        cin >> ammount;
        
        Account[search_account(account_num)].deposit(ammount);
    }
    else
        deposit();
    
    cout << "\n\nTO EXIT PRESS '0' ";
    cin >> choice;
    
}
void Print_Info()
{
    long int account_num;
    int i;
    
    
    cout << "\nTO SEE ACCOUNT INFO PLEASE ENTER ACCOUNT NUMBER: ";
    cin >> account_num;
    i =search_account(account_num);
    if (i != -1)
    {
        
        cout << "\nFirst Name: " << Account[i].showF_Name();
        cout << "\nLast Name: " << Account[i].showL_Name();
        cout << "\nAccount Number: " << Account[i].showAccount_Num();
        cout << "\nBalance: " << Account[i].showBalance();
    }
    else
        Print_Info();
    
    cout << "\n\nTO EXIT PRESS '0' ";
    cin >> choice;
    
}

int search_account(long int AC)
{
    
    
    for (int i = 0; i < 10; i++)
    {
        if (Account[i].showAccount_Num() == AC)
        {
            return i;
        }
        
        
    }
    
    return -1;
    
}
