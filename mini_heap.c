#include<stdlib.h>
#include<stdio.h>

int *Sorting(int *tree,int size);
void show(int tree[]);
void Swap(int *i,int *j);
void Print_tee(int *tree);
void insert(int data);
int  pop(int min_heap[]);
void sort();
int min_heap[10];
int max=0;

int main()
{
	int tree[] = {1,3,8,12,6,14,10,25,4,17};
	int *sort_tree,input;
	
	
	//printf("size is %d\n",size);
	
	//sort_tree = Sorting(tree,size);
	//insert
	
	for(int i =0;i<8;i++){
		insert(tree[i]);
	}
	printf("max is %d\n",max);
	printf("1.insert 2.pop 3.sort(rember don't input 0)\n");
	while(scanf("%d",&input) !=EOF){
		if(input==1){
			scanf("%d",&input);
			insert(input);
		}else if(input==2){
			pop(min_heap);
		}else{
			sort();
		}
	show(min_heap);	
	Print_tee(min_heap);
	printf("max is %d\n",max);
	}
		 
	return 0;
}
void sort(){
	for(int i=0;i<10;i++){
		printf("%d ", pop(min_heap));
		
	//printf("max is %d\n",max);
	}
	printf("\n");
}
//insert min_heap
void insert(int data){
	int index;
	if(max>=9){
		printf("is full!");
		return;
	}
	max++;
//printf("max= %d\n",max);
	
	min_heap[max] = data;
	index = max;
	while(index!=1){
		//index/2 is index father
		if(min_heap[index]>=min_heap[index/2]){
		//	printf("index:%d = %d ; index/2: = %d\n",index,min_heap[index],min_heap[index/2]);
			break;
		}
		Swap(&min_heap[index],&min_heap[index/2]);
		index = index/2;
	}

}
int  pop(int min_heap[]){
	int result = min_heap[1];
	if(max<1){
		printf("empty");
		return 0;
	}
	int tmp = min_heap[max];
	max--;
	int child = 2;
	int parent = 1;
	while( child <= max ){
		if( child < max && min_heap[child] > min_heap[ child + 1 ] ){ 
			child++;
			//printf("child > child+1\n");
		}
				if( min_heap[child] > tmp ) {break;}
				min_heap[parent] = min_heap[child];
				//min_heap[parent] = 0;
				parent = child;
				child *= 2;
	}
	min_heap[parent] = tmp;

	//printf("target child = %d\n target parent = %d\n",child,parent);
	return result;
	
}
//* is return array
int *Sorting(int *tree,int size){
	

	for(int i =0;i<size;i++){
		for(int j=0;j<size;j++){
			int swap;
			if(tree[i]<tree[j]){
			Swap(&tree[i],&tree[j]);
			
			}
		}
	}
	
	return tree;
	
}
void Swap(int *i,int *j){
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;

}
void show(int tree[]){
	printf("[");
	for(int i=0;i<11;i++){
		printf("%d ",tree[i]);
	}
	printf("]\n");
}
void Print_tee(int *tree){
	printf("---tree---\n");
	int temp=1,count =0,i;
	for(i=1;i<=max;i++){
		if(tree[i]!=0)
			printf("%2d ",tree[i]);
		count++;
		if(temp==count){
			printf("\n");
			count =0;
			temp *=2;
		}
		
	}
	printf("\n");
}

	

