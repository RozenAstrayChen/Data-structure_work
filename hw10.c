#include<stdio.h>
#define MAX_QUEUE 20
int line[MAX_QUEUE];
//rear = max is full
//環狀 rear = front is full
int rear=0,front=0,jude=0,input,ddelete;

void add_queue(int *queue,int n){
   if(rear==MAX_QUEUE){
       printf("queue is full!\n");
   }else{
        int l = n+rear;
        for(;rear<l;rear++){
             if(rear==MAX_QUEUE){
             printf("queue is full!\n");
             break;
             }
           line[rear] = 1;
       }
        
    printf("rear = %d\n",rear);
   }
}
void delete_queue(int *queue,int n){
    int hi = front+n;
    
    for(;front<hi;front++){
        if(front==rear){
            printf("%d is empty!",front);
            break;
        }
        line[front] = 0;
    }
    
    
}
void show(){
      for(int i=0;i<MAX_QUEUE;i++){
            printf("%d,",line[i]);
        }
        printf("\n");
}
int main(){
    while(1){
        printf("輸入要加入幾筆資料");
         scanf("%d",&input);
        add_queue(line,input);
         printf("after add line  = ");
       show();
         printf("輸入要刪除幾筆資料");
        scanf("%d",&ddelete);
         delete_queue(line,ddelete);
         printf("\nafter delete line  = ");
        show();
         
    }
    
}