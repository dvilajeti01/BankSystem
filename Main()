#include "Bank_Functions.h"


int main()
{
    int choice_main = 0;
    int choice_emp = 0;
    int choice_cust = 0;
    char decision;
    int ID;
    int emp_ID;
    int person;
    string type;
    int sum;
    
    cout<< "Enter Today's Date: ";
    cin >> curr_date;
    cout << endl;
    
    
    do
    {
        Main_Interface();
        cin >> choice_main;
        
        switch(choice_main)
        {
            case 1:
                
                decision = 'Y';
                
                while(decision == 'Y' || decision == 'y')
                {
                    cout<<"Enter your employee ID: ";
                    cin >> emp_ID;
                    cout << endl << "\n";
                    
                    if (check_employee(emp_ID)) //if it exists proceed to employee interface
                    {
                        do
                        {
                            
                            Employee_Interface();
                            cin >> choice_emp;
                            
                            switch(choice_emp) //switch case to deviate between the three main perspectives
                            {
                                case 1: //Employee Perspective
                                    
                                    
                                    
                                    decision = 'Y';
                                    
                                    while(decision == 'Y' || decision == 'y')
                                    {
                                        ID = NewCustomer_Interface();
                                        if (ID != -1)
                                        {
                                            cout << "**ACCOUNT SUCCESFULLY CREATED**" << endl << "\n Your Account ID is " << ID << endl;
                                            
                                            cout << "\nWould you like to create another account? (Y/N)" <<endl;
                                            cin >> decision;
                                        }
                                        
                                        else
                                        {
                                            //Error Message lets you reenter info
                                            cout << "**SSN ALREADY EXIST**" << endl;
                                            cout << "\nWould you like to try again? (Y/N)" <<endl;
                                            cin >> decision;
                                            
                                        }
                                    }
                                    
                                    cout << "TO EXIT PRESS 0: ";
                                    cin >> choice_emp;
                                    cout << endl;
                                    
                                    break;
                                    
                                case 2:
                                    decision = 'Y';
                                    
                                    while (decision == 'Y' || decision == 'y')
                                    {
                                        Approve_Interface();
                                        
                                        cout << "Would you like to approve any of the above transaction? (Y/N)";
                                        cin >> decision;
                                        
                                        if (decision == 'Y' || decision == 'y') //allows you to aprove as many transaction as you would like
                                        {
                                            
                                            cout << "Enter Transaction ID: ";
                                            cin >> ID;
                                            
                                            if (Approve_Transaction(ID, emp_ID))
                                            {
                                                cout << "**TRANSACTION APPROVED**" << endl;
                                                
                                                cout << "Would you like to approve any other transaction? (Y/N)";
                                                cin >> decision;
                                                cout << endl;
                                            }
                                            else
                                            {
                                                cout << "**TRANSACTION ID INVALID**" << endl;
                                                cout << "Would you like to try again? (Y/N)" <<endl;
                                                cin >> decision;
                                            }
                                            
                                            
                                        }
                                        else
                                            break;
                                    }
                                    
                                    cout << "TO EXIT PRESS 0: ";
                                    cin >> choice_emp;
                                    cout << endl;
                                    
                                    break;
                                case 3:
                                    decision = 'Y';
                                    
                                    while (decision == 'Y' || decision == 'y')
                                    {
                                        cout << "Which would you like to view: " << "\n1. Specific Customer Transaction" <<endl <<"\n2. Entire Tracsction Log" <<endl;
                                        cin >> person;
                                        
                                        if (person == 1)
                                        {
                                            Info_Interface("Customer");
                                            
                                            cout << "Would you like to go back to the options screen? (Y/N)";
                                            cin >> decision;
                                            cout << endl;
                                        }
                                        else
                                        {
                                            Info_Interface("Employee");
                                            
                                            cout << "Would you like to go back to the options screen? (Y/N)";
                                            cin >> decision;
                                            cout << endl;
                                        }
                                    }
                                    
                                    cout << "TO EXIT PRESS 0: ";
                                    cin >> choice_emp;
                                    cout << endl;
                                    
                                    break;
                                case 4:
                                    choice_main = 0;
                                    break;
                                    
                            }
                            
                        } while (choice_emp == 0);
                    }
                    else //if invalid you can re-enter or exit entirely
                    {
                        cout << "**INVALID ID**" << endl;
                        cout << "Would you like to re-enter the ID? (Y/N): ";
                        cin >> decision;
                        
                    }
                }
                
                cout << "TO EXIT PRESS 0: ";
                cin >> choice_main;
                cout << endl;
                
                break;
            case 2:
                
                    do
                    {
                        cout << "Enter Account ID: ";
                        cin >> ID;
                        
                        if (check_account(ID))
                        {
                        Customer_Interface();
                        cin >> choice_cust;
                        
                        switch(choice_cust)
                        {
                            case 1:
                                
                                decision = 'Y';
                                
                                while(decision == 'Y' || decision == 'y')
                                {
                                
                                    cout << "What type of transaction would you like to make? (D/W)" <<endl;
                                    cin >> type;
                                    
                                    
                                    if(type == "D")
                                    {
                                        cout << "Enter the ammount you would like to deposit: ";
                                        cin >> sum;
                                        cout << endl;
                                    }
                                    else
                                    {
                                        cout << "Enter the ammount you would like to withdraw: ";
                                        cin >> sum;
                                        cout << endl;
                                    }
                                
                                    make_Transaction(ID,type,sum);
                                    
                                    cout << "Would you like to make another transaction?" <<endl;
                                    cin >> decision;
                                }
                                
                                cout << "TO EXIT PRESS 0: ";
                                cin >> choice_cust;
                                cout << endl;
                                
                                break;
                            case 2:
                    
                                Info_Interface("Customer");
                                
                                cout << "TO EXIT PRESS 0: ";
                                cin >> choice_cust;
                                cout << endl;
                                
                                break;
                            case 3:
                                
                                cout << "Are you sure you want to delete your account? (Y/N) *This decision is permanent*" << endl;
                                cin >> decision;
                                
                                if (decision == 'Y' || decision == 'y')
                                {
                                    DeleteAcc(ID);
                                }
                                
                                cout << "TO EXIT PRESS 0: ";
                                cin >> choice_cust;
                                cout << endl;
                                
                                
                                break;
                            case 4:
                                choice_main = 0;
                                break;
                        }
                        }
                        else
                        {
                            cout << "**INVALID ID**" << endl;
                            cout << "Would you like to re-enter ID? (Y/N)" << endl;
                            cin >> decision;
                            
                            if (decision == 'Y' || decision == 'y')
                            {
                                choice_cust = 0;
                            }
                            else
                            {
                                choice_cust = 5;
                            }
                        }
                        
                    } while(choice_cust == 0);
                    
                cout << "TO EXIT PRESS 0: ";
                cin >> choice_main;
                cout << endl;
                
                break;
            case 3:
                
                decision = 'Y';
                
                while (decision == 'Y' || decision == 'y')
                {
                ID = NewCustomer_Interface();
                if (ID != -1 )
                {
                    cout << "**ACCOUNT SUCCEFULLY CREATED**" << endl;
                    cout << "\nYour account ID is: " << ID << endl;
                    cout << "\nWould you like to create another account? (Y/N)" << endl;
                    cin >> decision;
                    
                }
                else
                {
                    cout << "**The info you entered already exists in our database**" << endl;
                    cout << "\nWould you like to re-try? (Y/N)" << endl;
                    cin >> decision;
                }
                    
                }
                
                cout << "TO EXIT PRESS 0: ";
                cin >> choice_main;
                cout << endl;
                break;
            
            case 4:
                cout <<"**THANK YOU FOR BANKING WITH US**" <<endl;
                break;
        }
        
    } while(choice_main == 0);
    
    
    
 
    
    
    
    return 0;
}

