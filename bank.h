#define MAX 3


typedef struct Customer
{
    char name[50];
    char type[10];
    double cash;
    int id;
    unsigned char CheckDelete;

}Customer;

/* prototypes */
void CreateNewCustomer_mainF (void);
void CreateNewCustomer(void);
void EditCustomer(void);
void PrintCustomerData(void);
void TransferMoney(void);
void DeleteCustomerData(void);
