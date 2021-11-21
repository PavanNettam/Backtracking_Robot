#include<stdio.h>
#include<stdlib.h>
#include "PES1UG20CS573_H.h"
#define MAXI 100
int main(){
    List l;
    readMap(&l);
    Stack s;
    initS(&s);
    if(findPath(&s,&l)){
        storePath(&s,&l);
        printf("\nOUTPUT IS WRITTEN INTO THE OUTPUT FILE\n");
    }else{
        printf("\nPATH NOT FOUND!!\n\n");
    }
}