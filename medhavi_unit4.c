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
void createAccount();
void checkBalance();
void deposit(struct BankAccount *accountList, int numberOfAccounts);
void withdraw(struct BankAccount *accountList, int numberOfAccounts);
void displayAccountDetails(struct BankAccount *accountList, int numberOfAccounts);
void loadAccounts(struct BankAccount **accountList, int *numberOfAccounts);
void saveAccount(const struct BankAccount *account);

int main()
{
    struct BankAccount *accountList = NULL;
    int numberOfAccounts = 0;
    srand(time(NULL));
    int choice;

    loadAccounts(&accountList, &numberOfAccounts);

    const char *menu = "\n==== Bank Management System ====\n"
                       "1. Create Account\n"
                       "2. Check Balance\n"
                       "3. Deposit\n"
                       "4. Withdraw\n"
                       "5. Exit\n"
                       "6. Show Users (Admin Only)\n"
                       "===============================\n"
                       "Enter your choice: ";

    do
    {
        printf("%s", menu);
        scanf("%d", &choice);

        switch ((enum MenuOption)choice)
        {
        case CREATE_ACCOUNT:
            createAccount();
            break;
        case CHECK_BALANCE:
            checkBalance();
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

void createAccount()
{
    struct BankAccount newAccount;
    newAccount.accNum = rand();
    printf("\nEnter your name: ");
    scanf("%s", newAccount.name);
    printf("Enter your age: ");
    scanf("%d", &newAccount.age);
    printf("Enter your gender (M/F): ");
    scanf(" %c", &newAccount.gender);
    printf("Enter your Aadhar number: ");
    scanf("%lld", &newAccount.aadharNumber);
    printf("Enter the initial deposit amount: ");
    scanf("%d", &newAccount.balance);

    saveAccount(&newAccount);

    printf("Customer account created successfully.\n");
}

void saveAccount(const struct BankAccount *account)
{
    FILE *file = fopen("accounts.csv", "a");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(file, "%d,%s,%d,%c,%lld,%d\n",
            account->accNum,
            account->name,
            account->age,
            account->gender,
            account->aadharNumber,
            account->balance);

    fclose(file);
}

void checkBalance()
{
    printf("\nEnter your account number: ");
    int accNum;
    scanf("%d", &accNum);

    FILE *file = fopen("accounts.csv", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    struct BankAccount account;
    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%d,%[^,],%d,%c,%lld,%d",
               &account.accNum,
               account.name,
               &account.age,
               &account.gender,
               &account.aadharNumber,
               &account.balance);

        if (account.accNum == accNum)
        {
            printf("Account Number: %d\n", account.accNum);
            printf("Name: %s\n", account.name);
            printf("Balance: Rs. %d\n", account.balance);
            fclose(file);
            return;
        }
    }

    printf("Account not found.\n");
    fclose(file);
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

            // Save updated accounts back to the file
            FILE *file = fopen("accounts.csv", "w");
            if (file == NULL)
            {
                printf("Error opening file!\n");
                exit(1);
            }
            for (int j = 0; j < numberOfAccounts; j++)
            {
                fprintf(file, "%d,%s,%d,%c,%lld,%d\n",
                        accountList[j].accNum,
                        accountList[j].name,
                        accountList[j].age,
                        accountList[j].gender,
                        accountList[j].aadharNumber,
                        accountList[j].balance);
            }
            fclose(file);

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

                // Save updated accounts back to the file
                FILE *file = fopen("accounts.csv", "w");
                if (file == NULL)
                {
                    printf("Error opening file!\n");
                    exit(1);
                }
                for (int j = 0; j < numberOfAccounts; j++)
                {
                    fprintf(file, "%d,%s,%d,%c,%lld,%d\n",
                            accountList[j].accNum,
                            accountList[j].name,
                            accountList[j].age,
                            accountList[j].gender,
                            accountList[j].aadharNumber,
                            accountList[j].balance);
                }
                fclose(file);

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

void loadAccounts(struct BankAccount **accountList, int *numberOfAccounts)
{
    FILE *file = fopen("accounts.csv", "r");
    if (file == NULL)
    {
        return;
    }

    struct BankAccount account;
    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%d,%[^,],%d,%c,%lld,%d",
               &account.accNum,
               account.name,
               &account.age,
               &account.gender,
               &account.aadharNumber,
               &account.balance);

        *numberOfAccounts += 1;
        *accountList = (struct BankAccount *)realloc(*accountList, *numberOfAccounts * sizeof(struct BankAccount));
        (*accountList)[*numberOfAccounts - 1] = account;
    }

    fclose(file);
}
