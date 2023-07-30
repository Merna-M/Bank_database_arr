#include "Linked_List.h"

/*****************************************************************************************************************/
node* LinkedList_Create(char* name,char* type,double cash , int ID)
{
    node *list = (node*)malloc(sizeof(node));
    strcpy(list->name,name);
    strcpy(list->type,type);
    list->cash = cash;
    list->ID = ID;
    list -> next = NULL;
    return list;
}
/***********************************s******************************************************************************/
void LinkedList_PushBack(node* head,node** head_ptr, char* name,char* type,double cash , int ID)
{
    node* new_node = LinkedList_Create(name,type,cash,ID);
    if(head == NULL)
    {
        *head_ptr = new_node;
    }
    while(head->next != NULL)
    {
        head = head->next;
    }
    head->next = new_node;
}
/*****************************************************************************************************************/
void LinkedList_PushBegin(node** head_add ,char* name,char* type,double cash , int ID)
{
    node* new_node = LinkedList_Create(name,type,cash,ID);
    new_node ->next = *head_add;
    *head_add = new_node;
}
/*****************************************************************************************************************/
void LinkedList_Print(node *head,int ID)
{
    if(head == NULL)
    {
        printf("ID not Found!");
    }
    else
    {
        while(head != NULL)
        {
            if(head->ID == ID)
            {
                printf("Name: %s\n",head->name);
                printf("Cash: %f\n",head->cash);
                printf("Type: %s\n",head->type);
                break;
            }
            head = head->next;
        }
        if(head == NULL)
        {
            printf("ID not Found!");
        }
    }
    printf("\n");
}
/*****************************************************************************************************************/
int LinkedList_PopStart(node **head_ptr)
{
    int data = 0;
    if(*head_ptr == NULL)
    {
        printf("ID not Found!");
    }
    else{
        data = (*head_ptr)->ID;
        node* temp = *head_ptr;
        *head_ptr = (*head_ptr)->next;
        free(temp);
    }
    return data;
}
/*****************************************************************************************************************/
/*int LinkedList_PopEnd(node **head_ptr , node* head)
{
    int data = 0;
    if(*head_ptr == NULL || (*head_ptr)->next == NULL)
    {
        data = LinkedList_PopStart(head_ptr);
    }
    else
    {
        node* temp;
        while(head->next->next != NULL)
        {
            head = head->next;
        }
        temp = head->next;
        data = head->next->value;
        head->next = NULL;
        free(temp);
    }
    return data;
}*/
/*****************************************************************************************************************/
/*void LinkedList_InsertIndex(node *head , node** head_ptr , int index , int data)
{
    node* new_node = LinkedList_Create(data);
    if(head == NULL)
    {
        *head_ptr = new_node;
    }
    int i;
    for(i=0 ; i<index-1 ; i++)
    {
        if(head->next == NULL)
        {
            break;
        }
        head = head->next;
    }
    new_node ->next = head->next;
    head->next = new_node;
}*/
/*****************************************************************************************************************/
/*int LinkedList_RemoveIndex(node *head , node** head_ptr , int index)
{
    int data = 0 , i;
    if(*head_ptr == NULL || (*head_ptr)->next == NULL)
    {
        data = LinkedList_PopStart(head_ptr);
    }
    if(index == 0)
    {
        LinkedList_PopStart(head_ptr);
    }
    else
    {
        node* temp;
        for(i=0 ; i<index-1 ; i++)
        {
            if(head->next->next == NULL)
            {
                break;
            }
            head = head->next;
        }
        temp = head->next;
        data = head->next->ID;

        if(i != index-1)
        {
            head->next = NULL;
        }
        else
        {
            head->next = head->next->next;
        }

        free(temp);
    }
    return data;
}*/
/*****************************************************************************************************************/
void LinkedList_RemoveByID(node *head , node** head_ptr , int ID)
{
    if(head==NULL)
    {
        printf("ID not Found!");
    }
    else if(head->next == NULL || head->ID==ID)
    {
        if(head->ID == ID)
        {
            LinkedList_PopStart(head_ptr);
            printf("ID has been deleted successfully\n");
        }
        else
        {
            printf("ID not Found!");
        }
    }
    else
    {
        node* temp;
        while(head->next != NULL)
        {
            if(head->next->ID == ID)
            {
                temp = head->next;
                if(head->next->next == NULL)
                {
                    head->next = NULL;
                }
                else
                {
                    head->next = head->next->next;
                }
                free(temp);
                printf("ID has been deleted successfully\n");
                break;
            }
            else
            {
                head = head->next;
            }
        }
        if(head->ID != ID)
        {
            printf("ID not Found!");
        }
    }
}
/*****************************************************************************************************************/

