//
//  main.c
//  class01
//
//  Created by 陳家麒 on 2016/9/23.
//  Copyright © 2016年 陳家麒. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    //char one[10];
    char one[10] ;
    char two[10] ;
    //char *ptr;
    printf("one is ...");
    scanf("%s",one);
    printf("two is ...");
    scanf("%s",two);
    printf("you input one is %s\t;two is %s\n",one,two);
    char *ptr = strstr(one,two);
    printf("is simaliar is %s\n",ptr);
    printf("after you input one is %s\t;two is %s\n",one,two);
    *ptr ='\0';
    printf("after is %s\n",one);
    
    return 0;
}
