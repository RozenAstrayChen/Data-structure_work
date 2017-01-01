#include<stdio.h>
#include<stdlib.h>
typedef struct n{
    int data;
    struct n *left;
    struct n *right;
}node;
node* createNode(int);
void print(node*);
int shortTest(node* head);
//int generalShortest(node* head);
int generalAVL(node* head);
int main(){
    node* (*newNode)(int);
    newNode = createNode;
   	node *head = newNode( 10 );
	node *cur = head;
	head->left = newNode( 20 );
	head->right = newNode( 2 );
	
	cur = head->left;
	cur->left = newNode(1);
	cur->right = newNode(2);

	cur = cur->left;
	cur->left = newNode(2);
	cur->right = newNode(4);

	cur = cur->left;
	cur->left = newNode(3);

	cur = head->right;
	cur->left = newNode(50);
	cur->right = newNode(40);

	cur = cur->left;
	cur->left = newNode(100);
    
    print(head);
    printf("\n");
   
}
node* createNode(int data){
    node* n;
   
    n = (node*)malloc(sizeof(node));
    n -> data = data;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}
void print(node* n){
    node* fk;
     int count=0;
     printf("left\n");
    for(fk=n;fk!=NULL;){
        printf("%d(%d) -> ",fk->data,generalAVL(fk));
        fk = fk -> left;
    }
    printf("\nright\n");
    for(fk=n;fk!=NULL;){
        printf("%d(%d) -> ",fk->data,generalAVL(fk));
        fk = fk -> right;
    }
}
int shortest(node* head){
    
  	if( head != NULL ){
  	    //printf("going to%d\n",head->data);
  	    return 1 + shortest(head->right);
  	}else return 0;
}
/*int generalShortest(node *head){
  
	int data = shortest(head);
	if( head->left != NULL ) generalShortest( head->left );
	if( head->right != NULL )generalShortest( head->right );
	return data;
}*/
int generalAVL(node* head){
    node* tree;
    int left=0,right=0;
    for(tree=head;tree->left!=NULL;left++){
        tree = tree->left;
    }
    for(tree=head;tree->right!=NULL;right++){
        tree = tree->right;
    }
    return left-right;
}