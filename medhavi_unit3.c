#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum MenuOption
{
    CREATE_ACCOUNT = 1,
    CHECK_BALANCE,
    DEPOSIT,
    WITHDRAW,
    EXIT,
    USERS
};

struct BankAccount
{
    int accNum;
    char name[100];
    int age;
    char gender;
    long long aadharNumber;
    int balance;
};

// Function Prototypes
void createAccount(struct BankAccount *accountList, int numberOfAccounts);
void checkBalance(struct BankAccount *accountList, int numberOfAccounts);
void deposit(struct BankAccount *accountList, int numberOfAccounts);
void withdraw(struct BankAccount *accountList, int numberOfAccounts);
void displayAccountDetails(struct BankAccount *accountList, int numberOfAccounts);

int main()
{
    struct BankAccount *accountList = NULL;
    int numberOfAccounts = 0;
    srand(time(NULL));
    int choice;

    do
    {
        printf("\n==== Bank Management System ====\n");
        printf("1. Create Account\n");
        printf("2. Check Balance\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("6. Show Users (Admin Only)\n");
        printf("===============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch ((enum MenuOption)choice)
        {
        case CREATE_ACCOUNT:
            numberOfAccounts += 1;
            accountList = (struct BankAccount *)realloc(accountList, numberOfAccounts * sizeof(struct BankAccount));
            createAccount(accountList, numberOfAccounts);
            printf("Customer account created successfully.\n");
            break;
        case CHECK_BALANCE:
            checkBalance(accountList, numberOfAccounts);
            break;
        case DEPOSIT:
            deposit(accountList, numberOfAccounts);
            break;
        case WITHDRAW:
            withdraw(accountList, numberOfAccounts);
            break;
        case EXIT:
            printf("Thank You for visiting our bank\n");
            break;
        case USERS:
            displayAccountDetails(accountList, numberOfAccounts);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != EXIT);

    free(accountList);
    return 0;
}


void createAccount(struct BankAccount *accountList, int numberOfAccounts)
{
    printf("\n");
    accountList[numberOfAccounts - 1].accNum = rand();
    printf("Enter your name: ");
    scanf("%s", accountList[numberOfAccounts - 1].name);
    printf("Enter your age: ");
    scanf("%d", &accountList[numberOfAccounts - 1].age);
    printf("Enter your gender (M/F): ");
    scanf(" %c", &accountList[numberOfAccounts - 1].gender);
    printf("Enter your Aadhar number: ");
    scanf("%lld", &accountList[numberOfAccounts - 1].aadharNumber);
    printf("Enter the initial deposit amount: ");
    scanf("%d", &accountList[numberOfAccounts - 1].balance);
}

void checkBalance(struct BankAccount *accountList, int numberOfAccounts)
{
    printf("\n");
    int accNum;
    printf("Enter your account number: ");
    scanf("%d", &accNum);
    for (int i = 0; i < numberOfAccounts; i++)
    {
        if (accountList[i].accNum == accNum)
        {
            printf("Account Number: %d\n", accountList[i].accNum);
            printf("Name: %s\n", accountList[i].name);
            printf("Balance: Rs. %d\n", accountList[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void deposit(struct BankAccount *accountList, int numberOfAccounts)
{
    printf("\n");
    int accNum, depositAmt;
    printf("Enter your account number: ");
    scanf("%d", &accNum);
    printf("Enter the amount to be deposited: ");
    scanf("%d", &depositAmt);
    for (int i = 0; i < numberOfAccounts; i++)
    {
        if (accountList[i].accNum == accNum)
        {
            accountList[i].balance += depositAmt;
            printf("Amount of Rs. %d deposited successfully.\n", depositAmt);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw(struct BankAccount *accountList, int numberOfAccounts)
{
    printf("\n");
    int accNum, withdrawAmt;
    printf("Enter your account number: ");
    scanf("%d", &accNum);
    printf("Enter the amount to be withdrawn: ");
    scanf("%d", &withdrawAmt);
    for (int i = 0; i < numberOfAccounts; i++)
    {
        if (accountList[i].accNum == accNum)
        {
            if (accountList[i].balance >= withdrawAmt)
            {
                accountList[i].balance -= withdrawAmt;
                printf("Amount of Rs. %d withdrawn successfully.\n", withdrawAmt);
                return;
            }
            else
            {
                printf("Insufficient balance.\n");
                return;
            }
        }
    }
    printf("Account not found.\n");
}

void displayAccountDetails(struct BankAccount *accountList, int numberOfAccounts)
{
    printf("\n");
    printf("\n======================================================================================================================\n");
    printf("| %-15s | %-15s | %-4s | %-6s | %-15s | %-10s\n", "Customer ID", "Name", "Age", "Gender", "Aadhar Number", "Balance");
    printf("======================================================================================================================\n");
    for (int i = 0; i < numberOfAccounts; i++)
    {
        printf("| %-15d | %-15s | %-4d | %-6c | %-15lld | Rs. %-8d\n", 
                accountList[i].accNum, 
                accountList[i].name, 
                accountList[i].age, 
                accountList[i].gender, 
                accountList[i].aadharNumber, 
                accountList[i].balance);
    }
    printf("======================================================================================================================\n");
}
