#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE 5
char queue_1[MAX_QUEUE]={0,0,0,0,0};
char queue_2[MAX_QUEUE]={0,0,0,0,0};
int front = 0,front_2=0, rear = 0,rear_2=0,in,out,got_1=0,got_2=0,buf_1,buf_2;
int flag = 0;
int flag_2 =0;//改良原本只能存放N-1個元素，加上此布林變數即可存放N個元素

int isFull(){
	return (rear % MAX_QUEUE == front);
}

int isEmpty(){
	return front == rear;
}

void Add(char* queue, int item){
   // printf("1 is  %d  ,2 is  %d  ,3 is  %d  ,4 is  %d\n",isFull(),flag == 1,rear == MAX_QUEUE - 1,front == -1);
  // printf("1 is  %d  ,2 is  %d  ,3 is  %d  ,4 is  %d\n",isFull(),flag == 1,rear == MAX_QUEUE,front == 0);
    //因為上次加完旗標已經立起,這次full函數就能判斷isFull回傳1
	if (isFull() && flag == 1 || rear == MAX_QUEUE  && front == 0) {
		printf("queue is full!\n");
		return;
	}
	printf("queue add: %c\n", item);
	queue[rear] = item;
	rear = (rear +1) % MAX_QUEUE;
	//queue[rear] = item;
	//rear +玩如果等於front 立起旗標,所以rear+1 = front的意思
	if (front == rear) flag = 1;
}

void Delete(char* queue){
	if (isEmpty() && flag == 0){
		printf("queue is empty!\n");
		return;
	}
	queue[front] = 0;
	front = (front + 1) % MAX_QUEUE;
	//queue[front] = 0;
	printf("%c is deleted.\n", queue[front]);
	if (front == rear) flag = 0;
}
//line 2
int isFull_2(){
	return (rear_2 % MAX_QUEUE == front_2);
}

int isEmpty_2(){
	return front_2 == rear_2;
}

void Add_2(char* queue, int item){
   // printf("1 is  %d  ,2 is  %d  ,3 is  %d  ,4 is  %d\n",isFull(),flag == 1,rear == MAX_QUEUE - 1,front == -1);
  // printf("1 is  %d  ,2 is  %d  ,3 is  %d  ,4 is  %d\n",isFull_2(),flag_2 == 1,rear_2 == MAX_QUEUE,front == 0);
    //因為上次加完旗標已經立起,這次full函數就能判斷isFull回傳1
	if (isFull_2() && flag_2 == 1 || rear_2 == MAX_QUEUE  && front_2 == 0) {
		printf("queue is full!\n");
		return;
	}
	printf("queue add: %c\n", item);
	queue_2[rear_2] = item;
	rear_2 = (rear_2 +1) % MAX_QUEUE;
	//queue[rear] = item;
	//rear +玩如果等於front 立起旗標,所以rear+1 = front的意思
	if (front_2 == rear_2) flag_2 = 1;
}

void Delete_2(char* queue){
	if (isEmpty_2() && flag_2 == 0){
		printf("queue is empty!\n");
		return;
	}
	queue_2[front_2] = 0;
	front_2 = (front_2 + 1) % MAX_QUEUE;
	//queue[front] = 0;
	printf("%c is deleted.\n", queue_2[front_2]);
	if (front_2 == rear_2) flag_2 = 0;
}
void show(){
     for(int i=0;i<MAX_QUEUE;i++){
            printf("line 1=%d,",queue_1[i]);
        }
        printf("\n");
      for(int i=0;i<MAX_QUEUE;i++){
            printf("line 2=%d,",queue_2[i]);
        }
        printf("\n");
}
int main(){
   /* for(int i=0;i<6;i++){
    add(queue_1,i);
    }
    show();
    printf("start delete,rear is %d;front is %d\n",rear,front);
    for(int i=0;i<10;i++){
         delete_queue(queue_1);
    }
    show();
    printf("second add ,rear is %d; front is %d\n",rear,front);
    for(int i=3;i<10;i++){
    add(queue_1,i);
    }
    show();*/
    while(1){
        printf("add is '1~100',delete is '0',you have two queue!\n");
        scanf("%d",&in);
        if(in==0){
           // printf("delete ; front is %d\n",front);
           printf("clean line 1 or line 2 ?");
           scanf("%d",&out);
           if(out==1){
                Delete(queue_1);
           }else if(out==2){
               Delete_2(queue_2);
           }
           
            
        }else{
             //printf("add rear is %d\n",rear);
             got_1=0,got_2=0,buf_1=0,buf_2=0;
             //return 0;
            for (int i=0;i<5;i++){
               buf_1 = queue_1[i];
               if(buf_1==0){
                   got_1++;
               }
            }
             for (int i=0;i<5;i++){
               buf_2 = queue_2[i];
               
               if(buf_2==0){
                   got_2++;
               }
            }
           
            if(got_1>got_2){
                printf("加入第一隊！\n");
                Add(queue_1,in);
            }else{
                printf("加入第二隊!\n");
                Add_2(queue_2,in);
            }
            
            
        }
        show();
    }
    
}