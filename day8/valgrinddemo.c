#include<stdio.h>
#include<stdlib.h>


int main(int argc,char const *argv[])
{   
    int *ptr=0;
    ptr=(int *)malloc(sizeof(int) * 10);
    free(ptr);

    return 0;
}