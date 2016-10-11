#include<stdio.h>
#define ABC(x)  #x
#define DAY(x)  day##x
int main(){
    //String
    const int t1 =  0xfffff;
    int t2 =  0x00;
    
    //define
    printf("i define ABC is %s\n",ABC("fk you!"));
    int day1 =20;
    int day2 =30;
    printf("use define prefix is %d\n",DAY(1));
    //pointer
    
    printf("first int is %x\n",t1);
    //displacement
    int *p = &t2;
    p[1] =  0x00000;
    
   
     printf("displacement int is %x\n",t1);
    
    return 0 ;
}