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

struct Bank_Acc
{
    int accNum;
    char name[100];
    int age;
    int balance;
};

// Function Prototypes
void create_Acc();
void check_Bal();
void deposit_amount(struct Bank_Acc *accountList, int numberOfAccounts);
void withdraw_amount(struct Bank_Acc *accountList, int numberOfAccounts);
void display_account_details(struct Bank_Acc *accountList, int numberOfAccounts);
void loadAccounts(struct Bank_Acc **accountList, int *numberOfAccounts);
void saveAccount(const struct Bank_Acc *account);

int main()
{
    struct Bank_Acc *accountList = NULL;
    int numberOfAccounts = 0;
    srand(time(NULL));
    int choice;

    loadAccounts(&accountList, &numberOfAccounts);

    const char *menu = "\nBank Management System\n"
                       "1. Create Account\n"
                       "2. Check Balance\n"
                       "3. Deposit\n"
                       "4. Withdraw\n"
                       "5. Exit\n"
                       "6. Show Users\n"
                       "Enter your choice: ";

    do
    {
        printf("%s", menu);
        scanf("%d", &choice);

        switch ((enum MenuOption)choice)
        {
        case CREATE_ACCOUNT:
            create_Acc();
            break;
        case CHECK_BALANCE:
            check_Bal();
            break;
        case DEPOSIT:
            deposit_amount(accountList, numberOfAccounts);
            break;
        case WITHDRAW:
            withdraw_amount(accountList, numberOfAccounts);
            break;
        case EXIT:
            printf("Thank You for visiting our bank\n");
            break;
        case USERS:
            display_account_details(accountList, numberOfAccounts);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != EXIT);

    free(accountList);
    return 0;
}

void create_Acc()
{
    struct Bank_Acc newAccount;
    newAccount.accNum = rand();
    printf("\nEnter your name: ");
    scanf("%s", newAccount.name);
    printf("Enter your age: ");
    scanf("%d", &newAccount.age);
    printf("Enter the initial deposit amount: ");
    scanf("%d", &newAccount.balance);

    saveAccount(&newAccount);

    printf("Customer account created successfully.\n");
}

void saveAccount(const struct Bank_Acc *account)
{
    FILE *file = fopen("accounts.csv", "a");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(file, "%d,%s,%d,%d\n",
            account->accNum,
            account->name,
            account->age,
            account->balance);

    fclose(file);
}

void check_Bal()
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

    struct Bank_Acc account;
    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%d,%[^,],%d,%d",
               &account.accNum,
               account.name,
               &account.age,
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

void deposit_amount(struct Bank_Acc *accountList, int numberOfAccounts)
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

            
            FILE *file = fopen("accounts.csv", "w");
            if (file == NULL)
            {
                printf("Error opening file!\n");
                exit(1);
            }
            for (int j = 0; j < numberOfAccounts; j++)
            {
                fprintf(file, "%d,%s,%d,%d\n",
                        accountList[j].accNum,
                        accountList[j].name,
                        accountList[j].age,
                        accountList[j].balance);
            }
            fclose(file);

            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw_amount(struct Bank_Acc *accountList, int numberOfAccounts)
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

                
                FILE *file = fopen("accounts.csv", "w");
                if (file == NULL)
                {
                    printf("Error opening file!\n");
                    exit(1);
                }
                for (int j = 0; j < numberOfAccounts; j++)
                {
                    fprintf(file, "%d,%s,%d,%d\n",
                            accountList[j].accNum,
                            accountList[j].name,
                            accountList[j].age,
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

void display_account_details(struct Bank_Acc *accountList, int numberOfAccounts)
{
    printf("| %-15s | %-15s | %-4s | %-10s\n", "Customer ID", "Name", "Age", "Balance");
      for (int i = 0; i < numberOfAccounts; i++)
    {
        printf("| %-15d | %-15s | %-4d | Rs. %-8d\n", 
                accountList[i].accNum, 
                accountList[i].name, 
                accountList[i].age, 
                accountList[i].balance);
    }
}
void loadAccounts(struct Bank_Acc **accountList, int *numberOfAccounts)
{
    FILE *file = fopen("accounts.csv", "r");
    if (file == NULL)
    {
        return;
    }

    struct Bank_Acc account;
    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%d,%[^,],%d,%d",
               &account.accNum,
               account.name,
               &account.age,
               &account.balance);

        *numberOfAccounts += 1;
        *accountList = (struct Bank_Acc *)realloc(*accountList, *numberOfAccounts * sizeof(struct Bank_Acc));
        (*accountList)[*numberOfAccounts - 1] = account;
    }

    fclose(file);
}