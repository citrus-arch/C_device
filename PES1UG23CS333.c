#include <stdio.h>

int main()
{
int x=1;
int *p;
int my_acc[2];
int a;char name[50];
int acc_number=100;
int balance;  
int init_bal = 0;
int deposit;



balance=init_bal+deposit;
init_bal=balance;

while(x==1)
{
printf("Bank management system\n");
printf("1. create customer acc\n");
printf("2. check balance\n");
printf("3. deposit\n");
printf("4. withdraw\n");
printf("5. exit\n");

printf("enter choice: ");
scanf("%d",&a);

switch(a)
{
case 1: 
{
printf("enter your name: ");
scanf("%s",&name);
my_acc[0]=acc_number;
my_acc[1]=0;
int *p=my_acc;
printf("enter the initial deposit amount: ");
scanf("%d",&deposit);
printf("customer account created successfully!!\n");
printf("name: %s\n",name);
printf("account number: %d\n",*p);
printf("Initial balance: %d\n", *(p+1)); 
printf("Current balance: %d\n", deposit);
acc_number=acc_number+1;
break;
}
case 2:
{
int *p=my_acc;
printf("account number: %d\n",*p);
printf("balance: %d\n",deposit);
break;
}
case 3:
{
int n;
int *p=my_acc;
printf("\nEnter amount to be deposited :");
scanf("%d",&n);
deposit=deposit+n;
printf("Sucessfully deposited!\n");
break;
}
case 4:
{
int d;
int *p=my_acc;
printf("Enter amount to be withdrawn :");
scanf("%d",&d);
deposit=deposit-d;
printf("Withdrawn successfully!\n");
printf("current balance: %d\n",deposit);
break;
}
case 5:
{
x=0;
break;
}
}
}

return 0;
}