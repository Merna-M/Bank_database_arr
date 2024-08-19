#ifndef _BANK_H
#define _BANK_H

using namespace std;
#define NULL ((void*)0)

class Customer{
    private:
        string name;
        string id;
        string card_type;
        double cash;
        bool is_valid;
    public:
        //constructors
        Customer(){}
        //Setters
        void SetName(string name){
            this->name = name;
        }
        void SetID(string id){
            this->id = id;
        }
        void SetCardType(string card_type){
            this->card_type = card_type;
        }
        void SetCash(double cash){
            this->cash = cash;
        }
        void SetIsValid(bool isvalid){
            this->is_valid = isvalid;
        }
        //getters
        string GetName(void){
            return this->name;
        }
        string GetID(void){
            return this->id;
        }
        string GetCardType(void){
            return this->card_type;
        }
        double GetCash(void){
            return this->cash;
        }
        bool GetIsValid(void){
        return this->is_valid;
        }
};

void PrintStart(void);
int CheckExist(vector<Customer> l , string id);
Customer CreateCustomer(vector<Customer> l);
void PrintCustomerInfo(Customer c);
void DeleteCustomer(vector<Customer>& l, string id);
void EditCustomer(vector<Customer>& l, string id);
void TransferMoney(vector<Customer>&l , int index1, int index2);

#endif // _BANK_H
