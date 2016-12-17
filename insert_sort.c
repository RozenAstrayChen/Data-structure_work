#include<stdlib.h>
#include<stdio.h>
typedef struct{
    int data;
    struct node *next;
}node;
node* create_node(int);
void insert_node(node*, node*);
void  relink(node*,node*);
int show(node*);
void sort(node*,int count);
node* specify(node*,int);
int main(){
    //把資料創建
    node* lists = create_node(0);
    node* a = create_node(1);
    node* b = create_node(10);
    node* c = create_node(2);
    node* d = create_node(7);
    node* e = create_node(3);
    
    
    //link node
    insert_node(lists,a);//0->1
    insert_node(a,b);//0->1->2
    insert_node(lists,c);//0->3->1->2
    insert_node(c,d);//0->3->4->1->2
    insert_node(d,e);//0->3->4->5->1->2
	
	int count = show(lists);
	sort(lists,count);
    //print
    //show(lists);
    
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
int show(node* mynode){
    int time=0;
    //定義一struct
    node* n = mynode;
    while(n!=NULL){
        //printf("data =%d\n",n->data);
    
        
        time++;
       printf("%d -> ",n->data);
       n = n->next;
    }
    printf("\n\n");
    return time;
}
void sort(node* link,int count){
   
   int i,j;
   int tmp =0;
  
  //relink(specify(link,2),specify(link,3));
  for(j=0;j<count;j++){
      for(int i=-1;i<count;i++){
         // printf("%d is  %d\t",i,specify(link,i)->data);
          //printf("%d is  %d\n",i+1,specify(link,i+1)->data);
          if((specify(link,i+1)->data) >  (specify(link,i+2)->data)){
               //printf("is insert sort\n");
              relink(specify(link,i),specify(link,i+1));
          }
          //show(link);
      }
  }
  
  
  printf("\n");
  show(link);
    
}
node *specify(node* link,int count){
    for(int i=0;i<count & link->next!=NULL;i++){
        link = link->next;
    }
    return link;
}
//n1 抽出做排序
void relink(node* n1,node* n2){
   
 
 // n2->next = n1->next;
  node *tmp;
  n1->next = n2->next;
  n2->next = NULL;
  
  
  tmp = specify(n1,1)->next;
  specify(n1,1)->next = n2;
  n2->next = tmp;
  
  
  //insert_node(n1,tmp);
 
    
}