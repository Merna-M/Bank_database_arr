#include <stdio.h>
#include <string.h>
#include "bank.h"


Customer customer_arr[MAX];   //an array of struct customer
int customer_index = 0;       //index of current customer & number of customers

int DeleteCount = 0;          //number of deleted customers & index of deleted array
int Deleted_index[MAX];       //array to store index of deleted customers


/* a function to check if input ID was used before
it returns 1 if the ID exists and 0 if not*/
int CheckExistID (int id , int index)
{
    int i;
    for (i=0 ; i<customer_index ; i++)
    {
        //check if there are any other IDs with different index
        if (customer_arr[i].id == id && index != i)
        {
            return 1;
        }
    }
    return 0;
}


/*a function to create a new customer */
void CreateNewCustomer(void)
{
    int index;      //an int to be used as the index of customer_arr
    //check if the array is still has space
    if (customer_index < MAX)
    {
        index = customer_index;
        customer_index++;    //increment customer index
    }
    //if the array is full then there are some deleted customers
    else
    {
        DeleteCount--;      //decrement the deleted index
        index = Deleted_index[DeleteCount];
        customer_arr[index].CheckDelete=0;  //0 to indicate that it's used and not deleted
    }
    //ask of customer name
    printf("Please Enter the name of customer number %d : ",index+1);
    gets(customer_arr[index].name);
    //ask for customer cash
    printf("Please Enter the cash of customer number %d : ",index+1);
    scanf("%lf",&customer_arr[index].cash);
    fflush(stdin);
    //ask for the type
    printf("Please Enter the type of customer number %d <credit of debit> : ",index+1);
    gets(customer_arr[index].type);
    //if user entered a wrong word then ask him to re-enter it
    while (strcmp(customer_arr[index].type,"credit") && strcmp(customer_arr[index].type,"debit"))
    {
        printf("Please Enter the type correctly <credit or debit> : ");
        gets(customer_arr[index].type);
    }
    //ask for customer id
    printf("Please Enter the ID of customer number %d : ",index+1);
    scanf("%d",&customer_arr[index].id);
    fflush(stdin);
    //check if the entered ID has been used before
    while (CheckExistID(customer_arr[index].id , index) == 1)
    {
        printf("This ID already exists , Please Enter another ID : ");
        scanf("%d",&customer_arr[index].id);
        fflush(stdin);
    }
    printf("\n\n");
}

/*the main function to be used in the main function*/
void CreateNewCustomer_mainF (void)
{
    //check if the customer arr is full or not
    if (customer_index == MAX && DeleteCount==0)
    {
        printf("The maximum number of customers is %d so you can't add anymore\n",MAX);
    }
    else
    {
        // if not full then create a new customer
        CreateNewCustomer();
    }
}

/* a function to edit an existing customer*/
void EditCustomer(void)
{
    unsigned char id,i;
    // ask user to enter the ID
    printf("Please Enter the ID of the customer you need to change his data : ");
    scanf("%d",&id);
    fflush(stdin);
    // a loop with the size of customers in the array
    for (i=0 ; i<customer_index ; i++)
    {
        // if the ID is found
        if (customer_arr[i].id == id)
        {
            //check if the ID is deleted or not
            if (customer_arr[i].CheckDelete == 1)
            {
                printf("This customer's information has been deleted\n\n");
            }
            else
            {
                // if the ID is not deleted then ask user to re-enter information about customer
                printf("Please Enter the new name : ");
                gets(customer_arr[i].name);
                printf("Please Enter the new cash : ");
                scanf("%lf",&customer_arr[i].cash);
                fflush(stdin);
                printf("Please Enter the new type : ");
                gets(customer_arr[i].type);
                while (strcmp(customer_arr[i].type,"credit") && strcmp(customer_arr[i].type,"debit"))
                {
                    printf("Please Enter the type correctly <credit or debit> : ");
                    gets(customer_arr[i].type);
                }
                printf("Please Enter the new ID : ");
                scanf("%d",&customer_arr[i].id);
                fflush(stdin);
            }
            break;
        }
    }
    //i== customer_index only of the ID is not found in the array
    if (i == customer_index)
    {
        printf("The Entered ID is not stored in the database\n\n");
    }
}



/* a function to print information of a customer*/
void PrintCustomerData(void)
{
    unsigned char id,i;
    //ask user to enter ID of the customer
    printf("Please Enter the ID of the customer you need to print his data : ");
    scanf("%d",&id);
    fflush(stdin);
    // a loop with the size of customers in the array
    for (i=0 ; i<customer_index ; i++)
    {
        if (customer_arr[i].id == id)
        {
            if (customer_arr[i].CheckDelete == 1)
            {
                printf("This customer's information has been deleted\n\n");
            }
            else
            {
                //if the ID is not deleted then print customer's information
                printf("The name of Customer Number %d : %s\n",i+1,customer_arr[i].name);
                printf("The cash of Customer Number %d : %.4f\n",i+1,customer_arr[i].cash);
                printf("The type of Customer Number %d : %s\n",i+1,customer_arr[i].type);
                printf("The id of Customer Number %d   : %d\n",i+1,customer_arr[i].id);
            }
            break;
        }

    }
    //i== customer_index only if the ID is not found
    if (i == customer_index)
    {
        printf("The Entered ID is not stored in the database\n\n");
    }
}


/* a function to transfer data from a customer to another*/
void TransferMoney(void)
{
    int id_send,id_receive;     //id of sender and receiver customers
    double cash;                //cash to be transfered
    int i;
    int Sender_index=-1 , Receiver_index=-1 ;   //index of sender and receiver in customer_arr

    //ask for sender ID
    printf("Please Enter the ID of customer who the money will be transfered from : ");
    scanf("%d",&id_send);
    fflush(stdin);
    //ask for receiver ID
    printf("Please Enter the ID of customer who the money will be transfered to : ");
    scanf("%d",&id_receive);
    fflush(stdin);
    //ask for cash to be transferred
    printf("Please Enter the amount of money to be transfered : ");
    scanf("%lf",&cash);
    fflush(stdin);

    for (i=0 ; i<customer_index ; i++)
    {
        //if sender ID found then get index of customer_arr
        if (customer_arr[i].id == id_send && customer_arr[i].CheckDelete != 1)
        {
            Sender_index = i;
        }
        //if receiver ID found then get index of customer_arr
        else if (customer_arr[i].id == id_receive && customer_arr[i].CheckDelete != 1)
        {
            Receiver_index = i;
        }
        //both sender and receiver customers index are found
        if (Sender_index != -1 && Receiver_index != -1)
        {
            //check if the sender account has the amount of cash that is required to be transfered
            if (customer_arr[Sender_index].cash >= cash)
            {
                // if cash are available then transfer
                customer_arr[Sender_index].cash -= cash;
                customer_arr[Receiver_index].cash += cash;
                printf("Successfully Transfered\n\n");
            }
            //if that amount of cash isn't available at the sender's account
            else
            {
                printf("Not Enough cash in the sender's account\n\n");
            }
            break;
        }
    }
    /* i == customer_index if the entered ID of either sender or receiver or both is not right
    or if sender has the same ID as receiver*/
    if (i == customer_index)
    {
        printf("Something Went wrong, Please check the IDs Entered\n\n");
    }

}




/* a function to delete customer's information */
void DeleteCustomerData(void)
{
    int id , i;
    //as user to enter ID of the customer
    printf("Please Enter the id of the customer to delete his data : ");
    scanf("%d",&id);
    fflush(stdin);

    for (i=0 ; i<customer_index ; i++)
    {
        if (customer_arr[i].id == id)
        {
            customer_arr[i].CheckDelete=1;//deleted
            Deleted_index[DeleteCount]=i;//add the index of deleted ID in the array
            DeleteCount++;  //increment the number of deleted customers
            printf("The customer with ID %d is deleted\n\n",id);
            break;
        }
    }
    //i== customer_index only if the ID is not found
    if (i == customer_index)
    {
        printf("The Entered ID is not stored in the database\n\n");
    }
}
