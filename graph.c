#include<stdio.h>
#include<stdlib.h>
#define MAX_Martrix 10
//Adjacency Martrix
//Adjacency List
//dfs use stack
void dfs(int x);
void show();
int i,j,Martrix[MAX_Martrix][MAX_Martrix];
int visit[MAX_Martrix];
int count;
int main(){
	int in1,in2;
	printf("intput if you input <0,will output class\n");
	while(scanf("%d",&in1) != EOF){
		
		//printf("initlize");
		for(i=0;i<MAX_Martrix;i++){
			for(j=0;j<MAX_Martrix;j++){
				Martrix[i][j]=0;
			}
		}
		count=0;
		while(in1>=0){
			printf("in1=%d\n",in1);
			do scanf("%d",&in2);
			while(in2<0);
			printf("in2=%d\n",in2);
			Martrix[in1][in2]=1;
			Martrix[in2][in1]=1;
			printf("input in1\n");
			scanf("%d",&in1);
		}
		//init
		for(i=0;i<MAX_Martrix;i++)visit[i]=0;
		printf("out");
		for( i= 0; i<MAX_Martrix;i++ ){
			if( !visit[i] ){
				dfs(i);
				printf( "\n" );
				count++;
				
			}
		}
		show();
		printf( "have %d class\n", count );
		
		printf( "input:\n" );
	}
}
void show(){
	for(i=-1;i<10;i++)printf("%d ",i);
	for(i=-1;i<MAX_Martrix;i++){
		printf(" %d ",i);
		for(j=0;j<MAX_Martrix;j++){
			printf("%d ",Martrix[i][j]);
		}
		printf("\n");
	}
}
void dfs(int x){
	printf( "%d ", x );
	//visited turn 1
	visit[x] = 1;
	
	//stack
	for(int  i = 0; i < MAX_Martrix; i++ ){
		//serch y ...
		if( Martrix[x][i] && visit[i] == 0 ){
			dfs(i);
		}
			
		
	
	}
}
//j j j j  
//i
//i
//i
