
/***************************** Prototypes ******************************************/
void CreateNewCustomer(node* head, node** head_ptr,deleted_node *del_head,deleted_node** del_head_ptr);

int Check_deleted(deleted_node** del_head_ptr,deleted_node* del_head,int ID);

void Edit_Customer(node* head,deleted_node* del_head, deleted_node** del_head_ptr);

void Delete_Customer(node* head,node** head_ptr,deleted_node** del_head_ptr,deleted_node* del_head);

void Print_Customer(node* head,deleted_node* del_head,deleted_node** del_head_ptr);

void DeleteDeletedCustomer(deleted_node* del_head, deleted_node** del_head_ptr,int ID);

void Cash_Transfer(node* head, node** head_ptr);
