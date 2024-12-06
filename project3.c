#include <stdio.h>

int main()
{
int a;char name[80];
int acc_number=40;
int balance;  
int init_bal = 0;
int deposit;

balance=init_bal+deposit;
init_bal=balance;

printf("Bank management system\n");
printf("1. create customer acc\n");
printf("2. check balance acc\n");
printf("3. deposit\n");
printf("4. withdraw\n");
printf("5. exit\n");

printf("enter choice: ");
scanf("%d",&a);

switch(a)
{
case 1: 
printf("enter your name: ");
scanf("%s",&name);
printf("enter the initial deposit amount: ");
scanf("%d",&deposit);
printf("customer account created successfully!\n");
printf("name: %s\n",name);
printf("account number: %d\n",acc_number);
printf("Current balance: %d\n", deposit); 

return 0;
}
}