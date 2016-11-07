#include<stdio.h>
#include<stdlib.h>
#define max 256
int flag=0;
//被乘數使用的node
typedef struct nno{
    int data;
    struct nno* next;
    struct nno* prev;
}node;
//乘數使用的node
typedef struct nni{
    int data;
    struct nni* next;
    struct nni* prev;
    
}node2;

//宣告頭
node* head;
node2* head2;
node* head_tot;
//創立個節點
node* create_node(int x){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    
    return newnode;
}
//乘數使用
node2* create_node_mup(int x){
    node2* newnode = (node2*)malloc(sizeof(node2));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    
    return newnode;
    
}
//結果節點相連
void insert_node_total(int x){
    node* temp = head_tot;
    node* newnode = create_node(x);
    if(head_tot == NULL){
        head_tot = newnode;
        return;
    }
    //呼應前面的 node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;//抓到最後一個
    }
    //開始連結
    temp->next = newnode;
    newnode->prev=temp;
}
//節點相連
void insert_node(int x){
    node* temp = head;
    node* newnode = create_node(x);
    if(head == NULL){
        head = newnode;
        return;
    }
    //呼應前面的 node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;//抓到最後一個
    }
    //開始連結
    temp->next = newnode;
    newnode->prev=temp;
}
//被乘數使用
void insert_node_mup(int x){
    node2* temp = head2;
    node2* newnode = create_node_mup(x);
    if(head2 == NULL){
        head2 = newnode;
        return;
    }
    //呼應前面的 node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;//抓到最後一個
    }
    //開始連結
    temp->next = newnode;
    newnode->prev=temp;
}

void show_front(){
    printf("被乘數 ==");
    node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
        
    }
    printf("\n");
    
    //show_behind();
}
//乘數使用
void show_front_mup(){
    printf("乘數 ==");
    node2* temp=head2;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
        
    }
    printf("\n");
    
    //show_behind();
}
void show_front_tot(){
    printf("total =");
    node2* temp=head_tot;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
        
    }
    printf("\n");
    
    //show_behind();
}

void show_behind(){
    printf("show behind ");
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
void insert2link(int cut_i){
    if(flag==0){
        // printf("被乘數\n");
        insert_node(cut_i);
        
    }else if(flag==1){
        // printf("乘數\n");
        insert_node_mup(cut_i);
    }
    
}
void cut_string(char  Mulit[max]){
    //printf("%s\n",Mulit);
    char my[4];
    int x=0;
    int test=0;
    int add=0;
    int sum=4;
    int count=0;
    int mod=0;
    while(Mulit[test]!='\0' )
        test++;
    // mod = test%5;
    // printf("總長度為%d mod =%d\n",test,mod);
    mod = test%4;
    while(Mulit[x]!='\0' ){
        
        if(x%4==0 && x!=0){
            //printf("sum=%d add=%d\n",sum,add);
            // printf("last=%d\n",test);
            memcpy(my, Mulit+add,sum);
            //printf("1==%s\n",my);
            //sum=sum+9;
            add+=4;
            
            x++;
            insert2link(atoi(my));
            
        }//為了讓運算更方便尾數要滿9個數值
        else if(x==0){
            //printf("mod count\n");
            if(mod!=0){
                printf("mod=%d\n",mod);
                
                memcpy(my, Mulit+add,mod);
                //printf("2==%s\n",my);
                //sum=sum+9;
                add+=mod;
            }else{
                memcpy(my, Mulit+add,4);
                //printf("3==%s\n",my);
            }
            
            x++;
            insert2link(atoi(my));
        } else{
            x++;
        }
        
    }
    
    flag=1;
}

node* catch_lastlinked_1(node* link){
    while(link->next!=NULL){
        link=link->next;
    }
    return link;
}
node* catch_lastlinked_2(node* link){
    while(link->next!=NULL){
        link=link->next;
    }
    return link;
}
//插入最新
void Insert_fuck(int x) {
    //	node* temp = head;
    node* newNode = create_node(x);//create_node
    if(head_tot == NULL) {
        printf("first node\n");//第一個所以不作串接
        head_tot = newNode;
        return;
    }
    /*while(temp->prev != NULL){
     temp = temp->prev; // 連到新一個
     }*/
    head_tot->prev = newNode;//指向前一個
    newNode->next = head_tot;//指向後一個
    head_tot=newNode;
}
node* count_link(int x){
    node* t = catch_lastlinked_1(head_tot);
    for(int i=0;i<x;i++){
        t=t->prev;
    }
    
    return t;
}
void Multiplication(){
    node* temp=head;
    node* temp_mul=head2;
    node* temp_total=head_tot;
    int catch_i=0;
    int run_link=0;
    //取最後一值開始相乘
    node* multiplicand;
    node* ans;
    // node* multiplicand = catch_lastlinked_1(temp);
    //取最後一值開始相乘
    node* multip = catch_lastlinked_2(head2);
    ans = catch_lastlinked_1(head_tot);
    
    printf("ans_after= %d\n",ans->data);
    while(multip!=NULL){
        
        printf("round\n");
        multiplicand = catch_lastlinked_1(head);
        
        ans=count_link(run_link);
        printf("link is %d\t run=%d\n",ans->data,run_link);
        //printf("data is %d\n",multiplicand->data);
        while(multiplicand!=NULL){
            
            printf("%d 乘與 %d + %d",multip->data,multiplicand->data,ans->data);
            ans->data+=(multip->data)*(multiplicand->data);
            
            printf("==%d\n",ans->data);
            catch_i=ans->data/10000;
            ans->data=ans->data%10000;
            printf("carry is %d\n",catch_i);
            
            multiplicand=multiplicand->prev;
            ans=ans->prev;
            if(ans==NULL){
                printf("head is null! add head\n");
                //進位
                Insert_fuck(catch_i);
            }else{
                ans->data+=catch_i;
            }
            show_front_tot();
        }
        //當乘數移動時結果也要移動
        run_link++;
        multip = multip->prev;
    }
    
    
    
    
    
    
}

int main(){
    //char t[];
    insert_node_total(0);
    for(int i =0;i<20;i++){
        Insert_fuck(0);
       
    }
    


    char  Multiplicand[max];
    char  Multip[max];
    printf("請輸入被乘數");
    scanf("%s",Multiplicand);
    //切割字串放進鏈結
    
    cut_string(Multiplicand);
    //printf("show\n");
    show_front();
    
    
    
    printf("請輸入乘數");
    scanf("%s",Multip);
    
    cut_string(Multip);
    //printf("%s",Multip);
    
    
    //printf("show_2\n");
    show_front_mup();
    //
     Multiplication();
    
    
    //show_front();
    //show_behind();
    
    
    // insert_node(1);
    //insert_node(2);
    //show_front();
    //int i=999999999;//1000萬
    //1674919425
    
    
    
}