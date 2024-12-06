#include <stdio.h>

int main() {
    int choice_number;
    char name[100];
    int account_number;
    int balance;  
    int initial_balance = 0;
    int deposit;

    balance=initial_balance+deposit;
    initial_balance=balance;

    printf("Bank Management System\n");
    printf("1. Create Customer Account\n");
    printf("2. Check Balance\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice_number); 

    switch (choice_number) {
        case 1:
            printf("Enter your name: ");
            scanf(" %[^\n]", name);  
            printf("Enter initial deposit amount: ");
            scanf("%d", &balance);  
            printf("Enter account number: ");
            scanf("%d", &account_number);
            printf("Customer account created successfully!\n");
            printf("Name: %s\n", name);
            printf("Account number: %d\n", account_number);
            printf("Initial balance: %d\n", initial_balance); 
            printf("Current balance: %d\n", balance); 
            break;
    }
    return 0;
}