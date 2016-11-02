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

 
void before_Print() {
	node* temp = head;
	if(temp == NULL) return; // empty list, exit
	// Going to last Node
	while(temp->next != NULL) {
		temp = temp->next;
	}
	// Traversing backward using prev pointer

	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}
void sorting(int array[]){
    int i=0,j=0;
    int swap=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
              if( array[j] > array[i] ) {
                swap =array[j];
                array[j] = array[i];
                array[i] = swap;
            }
        }
    }
    
}
void catch_data(){
    	node* temp = head;
    	
    	int count=0;
	   	while(temp != NULL) {
		array[count]= temp->data;
		temp = temp->next;
		count++;
	    }
	    count=0;
	    //排序中..
	     sorting(array);
	    
	    /*for(int g=0;g<5;g++){
	        printf("%d\n",array[g]);
	    }*/
	    start_insert(array);
	   
}
void start_insert(int array[]){
     //排序完了
        node* temp = head;
	    printf("排序完開始插入\n");
	    int count =0;
	    
	    while(temp != NULL){
	        
	    temp->data = array[count];
	    //printf("%d",temp->data);
		temp = temp->next;
		count++;
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
	
	printf("輸入一個數字:");
	scanf("%d",&x);
	
	Insert(x);
	catch_data(array);
	
	//print
	show(); 
//	before_Print();

    printf("輸入一個數字:");
	scanf("%d",&x);
	
	Insert(x);
	catch_data(array);
	
	//print
	show(); 
//	before_Print();
    
	
}