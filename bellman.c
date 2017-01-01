/**
 * 1.first we need create martix
 * 2.create every nodes
 * 3.connect nodes by martx
 * 4.count short path
 **/ 
#include<stdio.h>
#include<stdlib.h>
#define aryMax 5
#define E 666
typedef struct n{
    int data;
    struct n *next;
}node;
node *length[aryMax];
int graph[5][5] =
{
	{E,6,5,5,E},
	{E,E,E,E,-1},
	{E,-2,E,E,1},
	{E,E,-2,E,E},
	{E,E,E,E,E}

};

void connect(node **head, int item);
void print_bell(int dis[aryMax][aryMax]);
void print_p(node* path);
//void com_graph();
void bellman(int  dis[aryMax][aryMax],int end,int start);
void (*ptr_fuc)();//test
void free_path(node *head);
void cpNodes( node **head1, node *head2 );
int main(){
    int i;
    int dis[5][5];
    bellman(dis,aryMax,0);
    print_bell(dis);
   /* node *L1 = createNode(1);
    node *L2 = createNode(2);
    connect(L1,L2);
    print_p(L1);*/
    for(i=1;i<aryMax;i++){
        print_p(length[i]);
    }
    
}
/*node *com_graph(){
    int i,j;
    node *zero;
    for(i=0;i<aryMax;i++){
        if(i==0)zero = createNode(0);
        for(j=0;j<aryMax;j++){
            if(aryMax[i][j] != E){
                
            }
        }
    }
}*/
void bellman(int  dis[aryMax][aryMax],int n,int start){
    int i,j,k;
    for(i=0;i<n;i++)length[i] = NULL;//
    for(i=0;i<n;i++){
        dis[1][i] = graph[start][i];
        if(graph[start][i] != E){
            connect(&length[i],start);
            connect(&length[i],i);
        }
    }
    dis[1][start] = 0;
    for(i=2;i<n;i++){
        for(j=0;j<n;j++){
            dis[i][j] = dis[i-1][j]; //cp before
            for(k=0;k<n;k++){
                if(graph[k][j] == E)continue;
                if(dis[i][j] > dis[i-1][k] + graph[k][j]){
                   //reset
                   	free_path( length[j] );
					length[j] = NULL;
					cpNodes( &length[j], length[k] );
					connect( &length[j], j );
                    dis[i][j] = dis[i-1][k] + graph[k][j];
                }
            }
        }
    }
}

void print_bell(int  dis[aryMax][aryMax]){
    int i,j;
   /* for(i=0;i<aryMax;i++){
        printf("%d ",0);
    }
    printf("\n");*/
    for(i=1;i<aryMax;i++){
        for(j=0;j<aryMax;j++){
            if(dis[i][j] != E){
                printf("%d ",dis[i][j]);
            }else{
                printf("E ");
            }
        }
        printf("\n");
    }
}
void connect(node **head, int item){
  
    node  *newItem = (node *) malloc( sizeof(node) );
	newItem->data = item;
	newItem->next = NULL;
	node *i;
	if( *head == NULL )
	{
		*head = newItem;
		return;
	}
	for( i = *head; i->next != NULL; i = i->next );
    	i->next = newItem;
}
void free_path(node *head){
    node *i;
	for( i = head; i != NULL; i = head )
	{
		head = i->next;
		free(i);
	}
}
void cpNodes( node **head1, node *head2 ){
	node *cur, *copy;
	node *tmp;
	tmp = (node *) malloc( sizeof(node) );

	*tmp = *head2;
	*head1 = tmp;
	
	for( cur = head2->next, copy = *head1; cur != NULL; cur = cur->next, copy = copy->next )
	{   
	    //copy -> cur
		tmp = (node *) malloc( sizeof( node ) );
		*tmp = *cur;
		copy->next = tmp;
	}
}
void print_p(node *path){

   node *i;
   for(i=path;i!=NULL;i = i->next){
       printf("%d ->",i->data);
       
   }
    printf("\n");
}