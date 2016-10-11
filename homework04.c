//use replace  2016-09-30
#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<string.h>
//use strcpy 2016-09-30

int main(){
    char one[10] ;
    char two[10] ;
    char three[10];
    char *find;
    char temp[10];
    //char *ptr;
    printf("one is ...");
    scanf("%s",one);
    printf("two is ...");
    scanf("%s",two);
    printf("three is ....");
    scanf("%s",three);
    
    printf("you input one is %s\t;two is %s;three is %s\n",one,two,three);
    
    find = strstr(one,two);
    int a = strlen(two);
    int b = strlen(find);
    int c = strlen(three);
   
    printf("find is %s\t,size is   %d,find size is   %d \n",find,a,b);
   
   // strcpy(find,three);
    for(int i=0;i<(b-a);i++){
        
        temp[i] =  find[a+i];
    }
    int d = strlen(temp);
    int e = strlen(find);
   printf("temp is %s\n",temp);
  for(int i =0;i<=(c);i++){
      find[i] = three[i];
  }
  for(int i =0;i<d;i++ ){
      find[(e-1)+i] =  temp[i];
  }
  printf("%s",one);
  
   
   
    
    return 0;
}