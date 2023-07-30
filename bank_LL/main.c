#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"
#include "bank.h"

int main()
{
    node* head=NULL;
    deleted_node* del_head=NULL;
    int option; //a variable to take option from user
    printf("######## Welcome To Bank Database ######## \n\n\n");
    //LinkedList_PushBegin(&head,"merna","credit",100,100);
    while(option != 6)
    {
        printf("\n\nPlease select one of the following options :\n");
        printf("Create a new customer:                  <press 1 to select this option>\n");
        printf("Edit customer:                          <press 2 to select this option>\n");
        printf("Delete customer:                        <press 3 to select this option>\n");
        printf("Print customer data:                    <press 4 to select this option>\n");
        printf("Cash transfer from customer to another: <press 5 to select this option>\n");
        printf("Exit:                                   <press 6 to select this option>\n");
        printf("\nYour Option: ");
        scanf("%d",&option);
        fflush(stdin);
        printf("\n");
        switch(option)
        {
        case 1: // the user asks to create a new customer
            CreateNewCustomer(head,&head,del_head,&del_head);
            break;
        case 2: // the user asks to edit an existing customer
            Edit_Customer(head,del_head,&del_head);
            break;
        case 3: // the user asks to delete an existing customer
            Delete_Customer(head,&head,&del_head,del_head);
            break;
        case 4: // the user asks to print the data of an existing customer
            Print_Customer(head,del_head,&del_head);
            break;
        case 5: // the user asks to transfer money from account to another
            Cash_Transfer(head,&head);
            break;
        case 6: // break to exit from while
            break;
        default: //the user entered a number out the range
            printf("Enter a number from 1 to 6\n");
            break;
        }
    }
    return 0;
}
