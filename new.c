#include <stdio.h>
#include <stdlib.h>
/*void fun1(int a1);
void main()
{
int a1=100;
printf("before func call a1 is %d\n",a1);
fun1(a1);
printf("after func call a1 is %d\n",a1);
}
void fun1(int a1)
{
printf("a1 in fun1 before changing %d\n",a1);
a1=200;
printf("a1 in fun1 after changing %d\n",a1);
}*/

/*void fun1(int *p); //using pointers
int main()
{
int a1=100;
printf("before func call a1 is %d\n",a1);
fun1(&a1); //call. address of a1
printf("after func call a1 is %d\n",a1);
}
void fun1(int *p)
{
printf("a1 in fun1 before changing %d\n",*p);
*p=200;
printf("a1 in fun1 after changing %d\n",*p);
}*/

/*void fun1(int *p); //using pointers
int main()
{
int a1=100; 
printf("before func call a1 is %d\n",a1);
fun1(&a1); //call. address of a1
printf("after func call a1 is %d *p=%d\n",a1);
}
void fun1(int *p)
{
int b=200;
printf("a1 in fun1 before changing %d\n",*p);
p=&b;
printf("a1 in fun1 after changing %d\n",*p);
}*/

/*void swap(int *a, int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}
int main()
{
int a=100;
int b=200;
printf("before call a is %d and b is %d\n",a,b);
swap(&a,&b);
printf("after call a is %d and b is %d\n",a,b);
return 0;
}*/

/*void f1(int);
void f2(int*);
void f3(int);
void f4(int*);
int* f5(int*);
int* f6();

int main()
{
int x=100;
f1(x);
printf("after f1 x is %d\n",x);
double y=6.5;
f1(y);
printf("after f1 y is %d\n",y);
int *p=&x;
f2(p);
printf("after f2 x is %d and *p is %d\n",x,*p);
f3(*p);
printf("after f2 x is %d and *p is %d\n",x,*p); */

/*int main()
{
int m1[10][10], m2[10][10], product[10][10];
int r1,c1,r2,c2;
int i,j,k;
scanf("%d%d",&r1,&c1);
scanf("%d%d",&r2,&c2);
if(c1!=r2)
{
printf("matrix multiplication not possible");
exit(0);
}
for(i=0;i<r1;i++)
for(j=0;j<c1;j++) //nested for loop. no bracket. no indent. continuous for loops
scanf("%d",&m1[i][j]);
for(i=0;i<r2;i++)
for(j=0;j<c2;j++)
scanf("%d",&m2[i][j]);
for(i=0;i<r1;i++)
{
for(j=0;j<c2;j++)
{
product[i][j]=0;
}
}
for(i=0;i<r1;i++)
{
	for(j=0;j<c2;j++)
{
	for(k=0;k<c1;k++)
{
product[i][j]=product[i][j]+m1[i][k]*m2[k][j]; //running the loop twice. but same i
}
}
}
for(i=0;i<r1;i++)
{
	for(j=0;j<c2;j++) //to print the product
{
printf("%d ",product[i][j]);
}
printf("\n");
}
return 0;
} */

/*int main()
{
int row, col;
int i,j;
scanf("%d%d",&row,&col);
int matrix[row][col];
int (*p)[col];
p=matrix;
for(i=0;i<row;i++)
for(j=0;j<col;j++)
scanf("%d",(*(p+i)+j));

for(i=0;i<row;i++)
{
	for(j=0;j<col;j++)
{
	 printf("%d ",*(*(p+i)+j)); //another * to deference to display 
}
printf("\n");
}
return 0;
}*/

/*int find_the_sum(int n);
int main()
{
int n;
printf("enter the number: ");
scanf("%d",&n);
int res=find_the_sum(n);
if(res==-1)
printf("error in sum\n");
else
printf("sum of numbers from 0 to %d is %d\n",n,res);
return 0;
}
int find_the_sum(int n)
{
if(n>0)
return n+find_the_sum(n-1);
else if(n==0)
return 0;
else
return -1;
}*/

int search(int *,int,int);
int main()
{
int i,n,m;
int a[20];
printf("enter the size of array: ");
scanf("%d",&n);
printf("enter the elements: ");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);  //alternative representation are a+i, i+a
}
printf("enter the element to be searched: ");
scanf("%d",&m);
if(search(a,n,m)) //func call
printf("present in the array");
else
printf("not present in the array");
return 0;
}
int search(int *a,int n,int m) //no ; since this is the func definition 
{
int i, flag=0;
printf("the size of *a=%d",sizeof(*a));
for(i=0;i<n;i++)
{
if(m==*a++)
{
flag=1;
break;
}
}
return flag;
}


