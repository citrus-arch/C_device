#include <stdio.h>
int main()
/*{ //for loop
int i,n;
scanf("%d",&n);
for(i=1;i<=10;i++)
{
printf("%d*%d=%d\n",n,i,n*i);
}
return 0;
}
*/

/*{ //while loop
int a,b,rem;
printf("enter any two numbers: ");
scanf("%d%d",&a,&b);
while(b!=0)
{
rem=a%b;
a=b; //interchanging values
b=rem;
}
printf("gcd of two numbers is: %d",a);
return 0;
} */

/*{  //gcd
int a; int b;
scanf("%d%d",&a,&b);
printf("a: %d b: %d\n",a,b);
while (a!=0)
{
if (a>b)
{
a-=b;
}
else
{
b-=a;
}
}
printf("gcd: %d\n",a);
return 0;
}*/

/*{ //do-while
int i=1,n;
scanf("%d",&n);
do //executed atleast once even if condition is false 
{
printf("%d*%d=%d\n",n,i,n*i);
i++;
} while (i<=10); //if i<0 given, executes atleast once [no. x 1 = no. since condition]
return 0;
} */

{ //check for odd or even
int n;
scanf("%d",&n);
if (n%2==0)
goto even;
break
else
goto odd;
even:
{
printf("even number\n");
return 0;
}
odd:
{
printf("odd number\n");
return 0;
}
