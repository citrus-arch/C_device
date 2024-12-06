/*#include <stdio.h>
int main()
{
	/*int a=99;
	float c=9.8;
	int b=20;
	int d;
	printf("a : %d b : %d\n", a, b);
	a=30;
	printf("a : %d b : %d\n", a, b);
	int n = printf("PESU\n");
	printf("the return value of printf is %d\n",n);
	n=printf("%f",c);
	printf("\nthe return value of printf is %d\n",n);*/


	/*printf("enter the value of a and b with a comma\n");
	scanf("%d %d", &a, &b);
	printf("a : %d b : %d\n", a, b);
	printf("enter the value of d");
	n = scanf("%d", &d);
	printf("the return value of scanf is %d\n",n);
	printf("the value of d is %d",d);
	return 0;*/

	/*int a,b;
	a = 16,b=78;
	float c=2.1911;
	printf("%4.2f\n",c); //4 width 2 precision
	printf("%5.1f\n",c); //precision 1 so rounded off
	printf("%5d %d\n",16,b);
	printf("ravan \rram\n");//cursor goes to first letter of ravan
	printf("ram\nlakhan\n");
	printf("ram\tbheem\n");
	printf("\"mahabharath\"");
	return 0;*/

	int a=8;
	char p= 'c';
	double d= 89.7;
	int e=0113; //octal literal
	int h = 0xA;
	int i = 0b100;
	printf("%d\n",e); //octal to decimal form
	printf("%o\n",e); //prints without 0 in 0113
	printf("%X\n",e); //hexadecimal
	printf("%x\n",e);
	printf("%d\n",h);
	printf("%d\n",i);
	return 0;
}*/


#include<stdio.h>
#include<limits.h>
#include<float.h>
int main()
{gcc
printf("%d %d\n",INT_MAX,INT_MIN);
printf("%d %d\n",FLT_MAX,FLT_MIN);
printf("%d %d\n",CHAR_MAX,CHAR_MIN);
return 0;
}
