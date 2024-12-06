#include <stdio.h>
float ci(float r,int t,int pr);
int acc[2];
int main()
{
    int t=1,bn=10000;
    while (t==1)
    {
        printf("\nBank management system\n1. Create account\n2. Check balance\n3. Deposit\n4.Withdraw\n5.Compound Interest calculator\n6.Exit\nEnter your choice :");
        int ch;
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
            {
              printf("\nEnter Name :");
              char str[30];
              scanf("%s",str);
              acc[0]=bn;
              acc[1]=0;
              printf("Enter initial deposit :");
              scanf("%d",&acc[1]);
              int *p=acc;
              printf("Account detalis are as follows :\nName :%s\naccount number :%d\nbalance :%d\n",str,*p,*(p+1));
              
              bn=bn+1;
              break;
            }
            case 2:
            {
              int *p=acc;
                printf("\nAccount number :%d\nBalance :%d",*p,*(p+1));
                break;
            }
            case 3:
            {
              int d;
              printf("\nEnter amount to be deposited :");
              scanf("%d",&d);
              acc[1]=acc[1]+d;
              printf("Sucessfully deposited");
              break;
            }
            case 4:
            {
              int w;
              printf("\nEnter amount to be withdrawn :");
              scanf("%d",&w);
              acc[1]=acc[1]-w;
              printf("Sucessfully withdrawn amount :%d",w);
              break;
            }
            case 5:
            {
              int *p=acc;
              int pr;
              printf("Enter Principal amount :");scanf("%d",&pr);
              if (pr > *(p+1))
              {
                printf("Insufficent balance \n");
              }
              else
              {
                float r,i;
                int t;
                printf("Enter amount of time in years ");

                scanf("%d",&t);
                printf("Enter rate or interest :");
                scanf("%f",&r);
                float amt;
                amt= ci(r,t,pr);
                printf("amount after interest =%.2f\n",amt);
              }
              break;
            }

            case 6:
            t=0;
        }
    }
    return 0;
}
float ci(float r,int t,int pr)
{
  float amt;
  amt=pr*r*1/100;
  if (t==0)
  return (pr);
  else
  {
    pr=pr+amt;
    return ci(r,t-1,pr);
  }
}