#include<stdio.h>
#include<math.h>
#include<headers.h>
int main(){
    int choice,day;
    float april[31];
    float may[32];
    float june[31];
    april[0]=0.0;may[0]=0.0;june[0]=0.0;
    for(int i=1;i<=31;i++)
    {
        april[i]=0.0;
        may[i]=0.0;
        june[i]=0.0;
    }
    may[32]=0.0;
    printf("Enter 1 for Deposit");
    printf("Enter 2 for Withdrawal");
    printf("Enter 3 for Balance check");
    printf("Enter 4 for Interest Calculation of a Savings Account");
    printf("Enter 5 for Calculation of Interest and Maturity amount of FD account");
    printf("Enter 6 for Home Loan EMI Calculation");
    printf("Enter 7 to exit the program")
    scanf("%d",&choice);
    int flag=1;
    while(flag==1)
    {
        switch (choice)
        {
            case 1:
            {
                int day,month;
                float *p;
                printf("Enter the starting balance on the 1st day of april");
                scanf("%f",&april[1]);
                float bal= april[1];
                printf("Enter the date followed by month");
                scanf("%d %d",&day,&month);
                float amount;
                printf("Enter the amount added");
                scanf("%f",amount);
                if(month==4) p=april;
                else if(month==5) p=may;
                else if(month==6) p=june;
                else printf("Invalid input");
                deposit(day,bal,amount,p);
                break;
            }
            case 2:
            {
                printf("Enter the starting balance on the 1st day of april");
                scanf("%f",&april[1]);
                float bal= april[1];
                int day,month;
                float* p;
                printf("Enter the date followed by month");
                scanf("%d %d",&day,&month);
                float amount;
                printf("Enter the amount added");
                scanf("%f",amount);
                if(month==4) p=april;
                else if(month==5) p=may;
                else if(month==6) p=june;
                else printf("Invalid input");
                withdrawal(day,bal,amount,p);
                break;
            }
            case 3:
            {
                int day,month;
                float* p;
                printf("Enter the date followed by month");
                scanf("%d %d",&day,&month);
                if(month==4) p=april;
                else if(month==5) p=may;
                else if(month==6) p=june;
                else printf("Invalid input");
                balancecheck(day,p);
                break;
            }
            case 4:
            {
                int day;
                float interest1,interest2,interest3;
                float bal,roipm;
                printf("Enter the days to see the interest");
                scanf("%d",&day);
                printf("Enter the starting balance");
                scanf("%f",&bal);
                printf("\nEnter the rate of interest:");
                scanf("%f",&roipm);
                savingsbankaccount(day,bal,roipm);
                break;
            }
            case 5:
            {
                float principal,rateofinterest,x;
                int maturitytimeperiod,timeperiod,compoundfrequency;
                printf("\nEnter the principal amount:");
                scanf("%f",&principal);
                printf("\nEnter the maturity time period:");
                scanf("%d",&maturitytimeperiod);
                printf("\nEnter the time period:");
                scanf("%d",&timeperiod);
                printf("\nEnter the rate of interest:");
                scanf("%f",&rateofinterest);
                printf("\nEnter the compounding frequency");
                scanf("%d",&compoundfrequency);
                x=fdaccount(principal,maturitytimeperiod,timeperiod,rateofinterest,compoundfrequency);
                printf("%.2f",x)
                break;
            }
            case 6:
            {
                float borrowedprincipalamt,rateofinterest3;
                int months;
                printf("Enter the principal amount:");
                scanf("%f",&borrowedprincipalamt);
                printf("Enter the repayment tenure in months:");
                scanf("%d",&months);
                printf("Enter the rate of interest per annum:");
                scanf("%f",&rateofinterest3);
                rateofinterest3=rateofinterest3/(12*100);
                homeloanemi(borrowedprincipalamt,months,rateofinterest3);
                break;
            }
            case 7:
            {
                flag=0;
                break;
            }
            default: printf("Invalid input");
        }
    }
}