#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int data;
    struct node *next;
}node;
node* create_node(int);
void insert_node(node*, node*);
void show(node*);
int main(){
    //把資料創建
   node* lists = create_node(0);
   node* a = create_node(1);
   node* b = create_node(2);
   node* c = create_node(3);
   node* d = create_node(4);
   node* e = create_node(5);
   
   
   //link node 
   insert_node(lists,a);//0->1
   insert_node(a,b);//0->1->2
   
   insert_node(lists,c);//0->3->1->2
   insert_node(c,d);//0->3->4->1->2
   insert_node(d,e);//0->3->4->5->1->2
   //print
   show(lists);
   
   printf("end\n");
    
    
    
}
node* create_node(int data)
{
    // 動態配置記憶體,放在函式return回去後會node會消失,必須用malloc來做
    node* n = (node*)malloc(sizeof(node));

    n->data = data;
    n->next = NULL;

    return n;
}
void insert_node(node* n1, node* n2)
{
    n2->next = n1->next;
    n1->next = n2;
}
void show(node* mynode){
    //定義一struct
    node* n = mynode;
    while(n!=NULL){
        //printf("data =%d\n",n->data);
        //指向下一個
        n = n->next;
        
       
            printf("data =%d\n",n->data);
        
    }
}