#include<stdio.h>
//大小
#define SIZE 7
typedef struct{
    int x;
    int y;
}point;

point fk(int, int);
int rush(int[][SIZE], point,point);
void print(int[][SIZE]);



int main(){
    //迷宮
    int maze[SIZE][SIZE] ={
        //start (1,1)
        //end (5,5)
        {2,2,2,2,2,2,2},
        {2,0,2,0,0,0,2},
        {2,0,0,0,2,0,2},
        {2,0,2,0,2,0,2},
        {2,0,2,0,2,0,2},
        {2,0,2,0,2,0,2},
        {2,2,2,2,2,2,2}
        
       
    };
    if(!rush(maze,fk(1,1),fk(5,5))){
        printf("not go out!");
    }
   // printf("%d\n",maze);
    print(maze);
    
    
}
point fk(int x,int y){
    point p = {x, y};
    printf("call  x =%d\ty =%d\n",p.x,p.y);
    return p;
    
}
int rush(int maze[][SIZE],point start,point end){
    //判斷是否走出去
    if(!maze[start.x][start.y]){
        maze[start.x][start.y]=1;
       // printf("first your maze go%d\n",maze[start.x][start.y]);
         //判斷是否走到
            if(!maze[end.x][end.y] && 
            !(rush(maze, fk(start.x, start.y + 1), end) || 
              rush(maze, fk(start.x + 1, start.y), end) ||
              rush(maze, fk(start.x, start.y - 1), end) || 
              rush(maze, fk(start.x - 1, start.y), end))) {
                 maze[start.x][start.y] = 0;
                 printf("break point\n");
         }
    }
    //report
    return maze[end.x][end.y];
    
}
void print(int maze[][SIZE]) {
    int i, j;
    for(i = 0; i < SIZE; i++) { 
        for(j = 0; j < SIZE; j++) 
        switch(maze[i][j]) {
            case 0 : printf(" ");
            break;
            case 1 : printf("1"); 
            break;
            case 2 : printf("█"); 
        }
        printf("\n"); 
    }     
}