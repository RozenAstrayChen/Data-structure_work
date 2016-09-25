#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//pointer is going 
int mystr(char *one,char *two){
     printf("one is %s;two is %s\n",one,two);
    int i =0;
    int two_c=0;
     //strstr
    while(one[i]!='\0'){
         if(one[i]==two[0]){
             printf("i=%d\n",i);
             int x=i;
             while(1){
                
                if(one[x]!=two[two_c]){
                     if(two[two_c]=='\0'){
                            // printf("succful\n");
                            one[i]='\0';
                            printf("catch is =%s\n",one);
                             return 1;
                     }else{
                     printf("break! x=%d;c=%d",x,two_c);
                     break;
                     }
                    }
                  
                 x++;
                 two_c++;
             }
             
         }
         i++;
     }
     return 0;
    
}
int main(int argc, const char * argv[]) {
    char one[10];
    char two[10];
   printf("input your first string\t");
   scanf("%s",one);
   printf("input your twice string\t");
   scanf("%s",two);
  
  int t =  mystr(one,two);
  if(t==1){
      printf("succ");
      
  }else{
      printf("fail!");
  }
 
    
    return 0;
}
