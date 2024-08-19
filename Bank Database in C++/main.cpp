#include <iostream>
#include <vector>
#include "Bank.h"

using namespace std;
unsigned int Number_of_customers;

int main()
{
    vector <Customer> cList;
    int operation = 0;
    cout << "*************************************************************************" <<endl;
    cout << "*************************** Bank DataBase *******************************" <<endl;
    cout << "*************************************************************************" <<endl;

    while(1){
        PrintStart();
        fflush(stdin); // clear input buffer
        cin >> operation;
        cout << endl;
        if(operation == -1){
            break;
        }
        else if(operation == 1){
            Customer c = CreateCustomer(cList);
            if(c.GetIsValid() == true){
                cList.push_back(c);
            }
        }
        else if(operation == 2){
            cout<<"\nEnter customer's ID: ";
            string id;
            fflush(stdin);
            cin >> id;
            int i = CheckExist(cList,id);
            if(i != -1){
                PrintCustomerInfo(cList[i]);
            }
            else{
                cout << "\nThe ID you Entered doesn't exist in the database"<<endl;
            }
        }
        else if(operation == 3){
            cout<<"\nEnter customer's ID: ";
            string id;
            fflush(stdin);
            cin >> id;
            DeleteCustomer(cList,id);
        }
        else if(operation == 4){
            cout<<"\nEnter customer's ID: ";
            string id;
            fflush(stdin);
            cin >> id;
            EditCustomer(cList,id);
        }
        else if(operation == 5){
            string id1,id2;
            int index1 , index2;
            cout<<"Enter ID of the first  Customer (Sender)  : ";
            cin >> id1;
            index1 = CheckExist(cList,id1);
            if(index1 == -1){
                cout << "\nThe ID you Entered doesn't exist in the database" <<endl;
                continue;
            }
            cout<<"Enter ID of the second Customer (Receiver): ";
            cin >> id2;
            index2 = CheckExist(cList,id2);
            if(index2 == -1){
                cout << "\nThe ID you Entered doesn't exist in the database" <<endl;
                continue;
            }
            TransferMoney(cList,index1,index2);
        }
        else if(operation == 6){
            cout << "Number of Accounts: " << Number_of_customers << endl;
        }
        else {
            cout << "\nSelect number from 1->6 , or -1 to exit" <<endl;
        }
    }

    return 0;
}
