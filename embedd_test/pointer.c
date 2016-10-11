#include <stdio.h>
int main(){
   const  int a = 0x123456;
    int b = 12345;
    printf("fk is  %x\n",a);
   int *p = &b;
   //p+1 = &a
   //*(P+1);
   p[1] = 0x001;
   printf("fk is ch %x\n",a);
   
    
    return 0;
}