#include <iostream>
#include <vector>
#include "Bank.h"

using namespace std;

extern unsigned int Number_of_customers;
/*************************************************************************************/
/*
Name: PrintStart
Desc: prints options before each operation
*/
/*************************************************************************************/
void PrintStart(void){
    cout << "\nEnter your operation: " <<endl;
    cout << "1: Create a new Customer" <<endl;
    cout << "2: Print a customer     " <<endl;
    cout << "3: Delete a customer    " <<endl;
    cout << "4: Edit a customer      " <<endl;
    cout << "5: Transfer Money       " <<endl;
    cout << "6: Number of Accounts   " <<endl;
    cout << "Press -1 to Exit\n"       <<endl;
    cout << "Your Input: ";
}

/*************************************************************************************/
/*
Name: CheckExist
Desc: Checks is the input id exists in the database or not
*/
/*************************************************************************************/
int CheckExist(vector<Customer> l , string id){
    int i;
    for(i=0 ; i<l.size() ; i++){
        if(l[i].GetID() == id){
            return i;
        }
    }
    return -1;
}

/*************************************************************************************/
/*
Name: CreateCustomer
Desc: creates new customers by setting name, id, card type and cash
*/
/*************************************************************************************/
Customer CreateCustomer(vector<Customer> l){
    Customer newCustomer;
    double d;
    string s;
    cout << endl;
    cout << "Enter Customer's ID: ";
    cin >> s;
    newCustomer.SetID(s);
    fflush(stdin);

    // -1 if the id doesn't exist in database
    if(CheckExist(l,s) != -1){
        cout<<"The ID you Entered is already in the DataBase, please Enter another ID"<<endl;
        newCustomer.SetIsValid(false); // not valid ID
        return newCustomer;
    }
    //valid ID
    newCustomer.SetIsValid(true);

    cout << "Enter Customer's name: ";
    cin >> s;
    newCustomer.SetName(s);
    fflush(stdin);

    cout << "Enter Card Type \n<press 1 for Credit OR press 2 for Debit>: ";
    do{
        cin >> s;
        if(s!="1" && s!="2"){
            cout << "\nWrong Option\nEnter Card Type \n<press 1 for Credit OR press 2 for Debit>: ";
        }
    }while(s!="1" && s!="2");

    if(s == "1"){
        newCustomer.SetCardType("Credit");
    }else{
        newCustomer.SetCardType("Debit");
    }

    cout << "Enter Initial account's cash: ";
    cin >> s;
    char c = 0;
    do{
        while(s[c] != '\0'){
            if(!(s[c]>='0' && s[c] <= '9') && s[c] != '.'){
                cout << "Enter a valid cash number: " <<endl;
                cin >> s;
            }
            c++;
        }
    }while(s[c] != '\0');
    d = stod(s);
    newCustomer.SetCash(d);
    Number_of_customers++;
    return newCustomer;
}

/*************************************************************************************/
/*
Name: PrintCustomerInfo
Desc: prints a customer's information
*/
/*************************************************************************************/
void PrintCustomerInfo(Customer c){
    cout << endl;
    cout<<"Customer's Name: " << c.GetName()      <<endl;
    cout<<"Customer's ID  : " << c.GetID()        <<endl;
    cout<<"Customer's Card: " << c.GetCardType()  <<endl;
    cout<<"Customer's Cash: " << c.GetCash()<<" $"<<endl;
}

/*************************************************************************************/
/*
Name: DeleteCustomer
Desc: Deletes a customer's information from database
*/
/*************************************************************************************/
void DeleteCustomer(vector<Customer>& l, string id){
    int index = CheckExist(l,id);
    if(index == -1){
        cout << "\nThe ID you Entered doesn't exist in the database"<<endl;
    }
    else{
        l.erase(l.begin()+index);
        Number_of_customers--;
        cout << "Customer " << id << " 's information deleted successfully" << endl;
    }
}

/*************************************************************************************/
/*
Name: EditCustomer
Desc: Edit a customer's information
*/
/*************************************************************************************/
void EditCustomer(vector<Customer>& l, string id){
    int index = CheckExist(l,id);
    if(index == -1){
        cout << "\nThe ID you Entered doesn't exist in the database"<<endl;
    }
    else{
        string s;
        double d;

        cout << "Edit Name? <y/n>: ";
        cin >> s;
        if(s == "y" || s == "Y"){
            cout << "Enter New Name: ";
            cin >> s;
            l[index].SetName(s);
        }

        cout << "Edit Card Type? <y/n>: ";
        cin >> s;
        if(s == "y" || s == "Y"){
            cout << "Enter New Card Type \n<press 1 for Credit OR press 2 for Debit>: ";
            do{
                cin >> s;
                if(s!="1" && s!="2"){
                cout << "\nWrong Option\nEnter Card Type \n<press 1 for Credit OR press 2 for Debit>: ";
                }
            }while(s!="1" && s!="2");
            l[index].SetCardType(s);
        }

        cout << "Edit Cash? <y/n>: ";
        cin >> s;
        if(s == "y" || s == "Y"){
            cout << "Enter New Cash: ";
            cin >> d;
            l[index].SetCash(d);
        }
    }
}

/*************************************************************************************/
/*
Name: TransferMoney
Desc: transfers money from an account to another
*/
/*************************************************************************************/
void TransferMoney(vector<Customer>&l , int index1, int index2){
    double d;
    cout << "Enter amount of money to be transferred: ";
    cin >> d;
    if(d<0){ //entered negative number
        cout << "Invalid number"<<endl;
    }
    else if(l[index1].GetCash()<d){
        cout << "Cash in Sender's account is not enough"<<endl;
    }
    else {
        l[index1].SetCash(l[index1].GetCash() - d);
        l[index2].SetCash(l[index2].GetCash() + d);
        cout << "Money Transfered successfully" << endl;
    }
}

/*************************************************************************************/
