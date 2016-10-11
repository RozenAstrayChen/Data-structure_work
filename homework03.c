#include<stdio.h>
#include<string.h>
//use strcpy 2016-09-30

int main(){
    char one[10] ;
    char two[10] ;
    char *find;
    //char *ptr;
    printf("one is ...");
    scanf("%s",one);
    printf("two is ...");
    scanf("%s",two);
    printf("you input one is %s\t;two is %s\n",one,two);
    
    find = strstr(one,two);
    int a = strlen(two);
    
    int b = strlen(find);
    
    printf("find is %s,size is   %d,find size is   %d \n",find,a,b);
   
    for(int i=0;i<=b-a;i++){
       
       // if(i==(b-a)){
           // find[i]= '\0';
       // }else{
             find[i] =  find[a+i];
        //}
       
    }
    printf("one is %s",one);
   
   
    
    return 0;
}