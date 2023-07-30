
#define NULL ((void*)0)
typedef struct node
{
    char name[50];
    char type[10];
    int ID;
    double cash;
    struct node* next;
}node;
/******************************************************************************************/
typedef struct deleted
{
    int ID;
    struct deleted* next;
}deleted_node;
/************************************ Declarations ***************************************/
node* LinkedList_Create(char* name,char* type,double cash , int ID);

void LinkedList_PushBack(node* head,node** head_ptr, char* name,char* type,double cash , int ID);

void LinkedList_PushBegin(node** head_add ,char* name,char* type,double cash , int ID);

void LinkedList_Print(node *head,int ID);

int LinkedList_PopStart(node **head_ptr);

//int LinkedList_PopEnd(node **head_ptr , node* head);

//void LinkedList_InsertIndex(node *head , node** head_ptr , int index , int data);

//int LinkedList_RemoveIndex(node *head , node** head_ptr , int index);

