#include<stdio.h>

void swap(int *n,int *m);
void show(int array[]);
int main(){

	int array[10] = {1,4,3,9,15,22,11,15,10,13};
	int min;
	for(int i=0;i<10;i++){
		min = i;
		for(int j=i+1;j<10;j++){
			if(array[j]<array[min]){
				min = j;
			}
		}
		if(min !=i){
			int l = array[min];
			array[min] = array[i];
			array[i] = l;
		}
	}
	show(array);

}
void swap(int *n,int *m){
	int *l;
	*l  = *n;
	*n = *m;
	*m = *l;

}
void show(int array[]){
	for(int i=0;i<10;i++)printf("%d ",array[i]);
}
