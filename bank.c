#include <stdio.h>

struct Bank
{
    int accno;
    char name[20];
    float balance;
};

struct Bank b;

// Create Account
void create()
{
    printf("Enter Account Number: ");
    scanf("%d", &b.accno);


    printf("Enter Name: ");
    scanf("%s", b.name);

    printf("Enter Initial Amount: ");
    scanf("%f", &b.balance);

    printf("Account Created Successfully!\n");
}

// Deposit
void deposit()
{
    float amt;
    printf("Enter Deposit Amount: ");
    scanf("%f", &amt);

    b.balance = b.balance + amt;
    printf("Amount Deposited Successfully!\n");
}

// Withdraw
void withdraw()
{
    float amt;
    printf("Enter Withdraw Amount: ");
    scanf("%f", &amt);

    if (amt <= b.balance)
    {
        b.balance = b.balance - amt;
        printf("Withdrawal Successful!\n");
    }
    else
    {
        printf("Insufficient Balance!\n");
    }
}

// Check Balance
void checkBalance()
{
    printf("\nAccount No : %d", b.accno);
    printf("\nName       : %s", b.name);
    printf("\nBalance    : %.2f\n", b.balance);
}

// Transaction History (Simple)
void history()
{
    printf("\nLast Balance : %.2f\n", b.balance);
}

int main()
{
    int ch;

    do
    {
        printf("\n--- BANK MANAGEMENT ---\n");
        printf("1.Create Account\n");
        printf("2.Deposit\n");
        printf("3.Withdraw\n");
        printf("4.Check Balance\n");
        printf("5.Transaction History\n");
        printf("6.Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: create(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: history(); break;
            case 6: printf("Thank You\n"); break;
            default: printf("Invalid Choice\n");
        }

    } while(ch != 6);

    return 0;
}