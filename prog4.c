#include <stdio.h>
#include <math.h>
int main()
{
int n1,n;
int dec=0,i=0,d;

printf("enter bin: ");
scanf("%d",&n);
n1=n;
while(n!=0)
{
d=n%10;
dec=dec+d*pow(2,i);
n=n/10;
i++;
}
printf("dec number: %d\n",dec);
}



