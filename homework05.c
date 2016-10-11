//math 2016-09-30
#include<stdio.h>
int main(){
    
    int x,n, ans =0;
    int p[4];
    
    printf("input one ");
    scanf("%d",&x);
    printf("input n");
    scanf("%d",&n);
   for(int i=0;i<4;i++){
       printf("%d\t",i);
       scanf("%d",&p[i]);
   }
    
    
    
    for(int i=0;i<=n;i++){
        ans = ans*x +p[i];
    }
    printf("ans is %d",ans);
    
    return 0;
}