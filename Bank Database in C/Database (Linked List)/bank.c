#include <stdio.h>
#include <string.h>
#include "Linked_List.h"
#include "bank.h"
/**********************************************************************************************************/
void DeleteDeletedCustomer(deleted_node* del_head, deleted_node** del_head_ptr,int ID)
{
    deleted_node* temp;
    if(del_head->ID==ID)      //first element
    {
        temp = *del_head_ptr;
        *del_head_ptr = (*del_head_ptr)->next;
        free(temp);
    }
    else
    {
        while(del_head != NULL)
        {
            if(del_head->next->ID == ID)
            {
                temp = del_head->next;
                if(del_head->next->next == NULL)
                {
                    del_head->next = NULL;
                }
                else
                {
                    del_head->next = del_head->next->next;
                }
                free(temp);
                break;
            }
            else
            {
                del_head = del_head->next;
            }
        }
    }
}
/**********************************************************************************************************/
void CreateNewCustomer(node* head, node** head_ptr,deleted_node *del_head,deleted_node** del_head_ptr)
{
    //node* new_node;
    char name[50],type[10],check_char;
    double cash;
    int ID,check;

    printf("Please Enter the name of customer: ");
    gets(name);
    printf("Please Enter the Cash of customer: ");
    scanf("%lf",&cash);
    fflush(stdin);
    printf("Please Enter the type of customer <credit or debit>: ");
    gets(type);
    while(strcmp(type,"credit" )&& strcmp(type,"debit"))
    {
        printf("Please Enter the type correctly <credit or debit> : ");
        gets(type);
    }
    printf("Please Enter the ID of the Customer: ");
    scanf("%d",&ID);
    fflush(stdin);
    check = Check_deleted(del_head_ptr,del_head,ID);
    if(check != -1)
    {
        do{
            printf("This ID has been Deleted, Would you like to use it <y/n>: ");
            scanf("%c",&check_char);
            fflush(stdin);
            if(check_char == 'y'||check_char=='Y')
            {
                DeleteDeletedCustomer(del_head,del_head_ptr,ID);
                break;
            }
            else if(check_char == 'n'||check_char=='N')
            {
                printf("Please Enter the ID of the Customer: ");
                scanf("%d",&ID);
                fflush(stdin);
                check = Check_deleted(del_head_ptr,del_head,ID);
            }
            else
            {
                printf("You need to Enter Y/y to use the same ID, or N/n to use different ID!\n");
            }
        }while(check != -1);
    }
    while(head != NULL)
    {
        if(head->ID == ID)
        {
            printf("This ID already exists, Please Enter another ID: ");
            scanf("%d",&ID);
            fflush(stdin);
            head = *head_ptr;
        }
        else
        {
            head = head->next;
        }
    }
    LinkedList_PushBegin(head_ptr,name,type,cash,ID);
    printf("Customer %d's Information has been stored successfully\n",ID);
}
/**********************************************************************************************************/
int Check_deleted(deleted_node** del_head_ptr,deleted_node* del_head,int ID)
{
    int index=0;
    while(del_head != NULL)
    {
        if(del_head->ID == ID)
        {
            break;
        }
        index++;
        del_head=del_head->next;
    }
    if(del_head == NULL)
    {
        index = -1;
    }
    return index;
}
/**********************************************************************************************************/
void Edit_Customer(node* head,deleted_node* del_head, deleted_node** del_head_ptr)
{
    int ID,check;
    printf("Enter the ID of the customer you need to change his data: ");
    scanf("%d",&ID);
    fflush(stdin);
    check = Check_deleted(del_head_ptr,del_head,ID);
    if(check == -1) // not deleted
    {
        while(head != NULL)
        {
            if(head->ID == ID)
            {
                printf("Please Enter the New Name: ");
                gets(head->name);
                printf("Please Enter the New Cash: ");
                scanf("%lf",&head->cash);
                fflush(stdin);
                printf("Please Enter the New Type: ");
                gets(head->type);
                printf("\nNew data has been stored Successfully\n");
                break;
            }
            head = head->next;
        }
        if(head == NULL)
        {
            printf("This ID doesn't exist in the Database!\n\n");
        }
    }
    else //deleted
    {
        printf("This ID has been Deleted!\n\n");
    }
}
/**********************************************************************************************************/

void Delete_Customer(node* head,node** head_ptr,deleted_node** del_head_ptr,deleted_node* del_head)
{
    int ID,check;
    printf("Enter the ID of the customer you want to delete: ");
    scanf("%d",&ID);
    fflush(stdin);
    //check if deleted before
    check = Check_deleted(del_head_ptr,del_head,ID); ///////////////////////////////
    if(check != -1)
    {
        printf("This ID has already been deleted !\n\n");
    }
    else
    {
        deleted_node* new_node = (deleted_node*)malloc(sizeof(deleted_node));
        new_node->ID = ID;
        new_node->next = *del_head_ptr;
        *del_head_ptr = new_node;
        LinkedList_RemoveByID(head,head_ptr,ID);
    }
}
/**********************************************************************************************************/
void Print_Customer(node* head,deleted_node* del_head,deleted_node** del_head_ptr)
{
    int ID,check;
    printf("Enter the ID of the customer you want to Print his data: ");
    scanf("%d",&ID);
    fflush(stdin);
    //check if deleted before
    check = Check_deleted(del_head_ptr,del_head,ID);
    if(check != -1)
    {
        printf("This ID has already been deleted !\n\n");
    }
    else
    {
        printf("Required Customer with ID %d's Data:\n",ID);
        LinkedList_Print(head,ID);
    }
}
/**********************************************************************************************************/
void Cash_Transfer(node* head, node** head_ptr)
{
    int ID1,ID2;
    double cash1,cash2,amount;
    node* sender=*head_ptr;
    node* receiver = *head_ptr;

    printf("Enter ID of Customer to transfer cash FROM: ");
    do{
        sender = *head_ptr;
        scanf("%d",&ID1);
        fflush(stdin);
        while(sender != NULL)
        {
            if(sender->ID == ID1)
            {
                cash1 = sender->cash;
                break;
            }
            sender = sender->next;
        }
        if(sender == NULL)
        {
            printf("ID not Found!\nPlease re-Enter the right ID: ");
        }
    }while(sender == NULL);

    printf("Enter ID of Customer to transfer cash TO: ");
    do{
        receiver = *head_ptr;
        scanf("%d",&ID2);
        fflush(stdin);
        while(receiver != NULL)
        {
            if(receiver->ID == ID2)
            {
                cash2 = receiver->cash;
                break;
            }
            receiver = receiver->next;
        }
        if(receiver == NULL)
        {
            printf("ID not Found!\nPlease re-Enter the right ID: ");
        }
    }while(receiver == NULL);
    printf("Enter the amount of money to be transfered: ");
    scanf("%lf",&amount);
    fflush(stdin);
    if(cash1<amount)
    {
        printf("Not Enough Money in the sender's Cash\n");
    }
    else
    {
        cash1 = cash1 - amount;
        cash2 = cash2 + amount;
        sender->cash = cash1;
        receiver->cash = cash2;
        printf("%.3f$ has been transfered successfully from Customer %d to Customer %d\n",amount,ID1,ID2);
    }
}
/**********************************************************************************************************/
