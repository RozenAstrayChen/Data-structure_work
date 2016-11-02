/* Doubly Linked List implementation */
#include<stdio.h>
#include<stdlib.h>

typedef  struct  {
	int data;
	struct node* next;
	struct node* prev;
}node;

node* head; 
int array[5];//排序資料

//create node
node* GetNewNode(int x) {
	node* newNode
		= (node*)malloc(sizeof(node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}


//加入到頭左->右
void Insert(int x) {
	node* temp = head;
	node* newNode = GetNewNode(x);//create_node
	if(head == NULL) {
	    printf("first node\n");//第一個所以不作串接
		head = newNode;
		return;
	}
	while(temp->next != NULL){
	temp = temp->next; // 連到最後一個
	}
	temp->next = newNode;//指向後一個
	newNode->prev = temp;//指向前一個
}

//印出
void show() {
	node* temp = head;

	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

 
void delete(int x){
    node* temp = head;
    node* delete_be;
    while(temp != NULL){
        
        if(temp->data==x){
            printf("find data\n");
            
       
            if(temp->prev==NULL){
                printf("%d\n",head->data);
                head = temp->next;
            }else{
                delete_be->next = temp->next;
            }
            break;
        }
            delete_be=temp;//被刪除的前一個
            printf("not find!\n");
            temp = temp->next;
        
    }
    
}



int main() {
    int x;

	/*Driver code to test the implementation*/
	head = NULL; // empty list. set head as NULL. 
	
	// Calling an Insert and printing list both in forward as well as reverse direction. 
	Insert(2); 
	
	Insert(4);

	Insert(6); 

	Insert(8); 
	
	Insert(10);
	
    Insert(12);
    show();
    printf("delete what?");
    scanf("%d",&x);
    delete(x);
    show();
    
	
}