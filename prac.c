#include <stdio.h>
/*void main()
{
int i,j,spc,rows,k,t=1;
printf("input number of rows: ");
scanf("%d",&rows);
spc=rows+4-1;
for(i=1;i<=rows;i++)
{
for(k=spc;k>=1;k--)
{
printf(" ");
}
for(j=1;j<=i;j++)
{
printf("%d ",t++);  //do not put semicolon infront of loops
}
printf("\n");
spc--;
}
}*/

/*int main()
{
int low,high,i,flag;
printf("enter 2 numbers: ");
scanf("%d %d",&low,&high);
printf("prime numbers between %d and %d are: ",low,high);
while(low<=high)
{
flag=0;
for(i=2;i<=low/2;++i)
{
if(low%i==0)
{
flag=1;
break;
}
}
if(flag==0)
printf("%d ",low);
++low;
}
return 0;
}*/

/*int main()
{
for(int i=1;i<=8;i++)
{
if(i==4)
continue; //takes u back to the for loop. starts from 5. pass. opposite of continue
printf("%d ",i);
}
printf("\n");
return 0;
}*/

/*int main()
{
int a;

printf("Bank management system\n");
printf("1. create customer acc\n");
printf("2. check balance acc\n");
printf("3. deposit\n");
printf("4. withdraw acc\n");

printf("enter choice: ");s
scanf("%d",&a);

switch(a)
{
case 1: printf("create customer acc\n");break;
case 2: printf("check balance\n");break;
return 0;
}
}*/

/*int main()
{  //p storing a address
int a=10;
int *p;
p=&a; //address
printf("%d",*p);  //*p is a dereference
return 0;
}*/

/*int main()
{
int *p;
int a=10;
p=&a;
printf("1=%d\n",(*p)+1);
printf("2=before *p++ p=%d\n",p);
printf("3=%d\n",*p++);
printf("4=after *p++ p=%d\n",p); //+4 jump since int takes 4 spaces
printf("5 *p=%d\n",*p);
printf("6 (*p)++=%d\n",(*p)++);
printf("7 *p=%d\n\n\n\n\n\n",*p);
return 0;
}*/

/*int main()
{ //pointer arithmatic
int *p, x=20;
char *q;

p=&x;
printf("p=%d\n",p);
printf("p+1=%d\n",sizeof(*q));
printf("p+1=%d\n",(char*)p+1);
printf("p+1=%d\n",(float*)p+1);
printf("p+1=%d\n",(double*)p+1);
return 0;
}*/


/*int main()
{
int a[]={12,55,77,33,99};
int *p=a;
int i;
for(i=0;i<5;i++)
p[i]=a[i];
for(i=0;i<5;i++)
printf("%d\t",(*p)++);
return 0;
}*/

/*int main()
{
int a[]={12,55,77,33,99};
int i;
for(i=0;i<5;i++)
printf("%d\t",(*a)++);
return 0;
}*/

/*int main()
{
int arr[]={12,44,22,33,55};  int *p=arr; int i;
for(i=0;i<5;i++) printf("%d\t",p[i]);
for(i=0;i<5;i++) printf("%d\t",*(p+i));
return 0;
}*/

int main()
{
printf("😍\n");
return 0;
}