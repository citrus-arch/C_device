#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int* p = (int*)malloc(sizeof(int)); //dynamic allocation for one integer
//address of that location is returned in p
*p = 10;
printf("p = %d", *p);
return 0;
}