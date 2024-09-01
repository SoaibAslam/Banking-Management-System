#include <stdio.h>
#include <string.h>
#define MAX_TRANSACTIONS 100
#define MAX_PASSWORD_LENGTH 20
#define MAX_ACCOUNTS 10
#define INTEREST_RATE 0.03
typedef struct {
    float balance;
    char name[24];
    int accountNo;
    char password[MAX_PASSWORD_LENGTH];
    float depositHistory[MAX_TRANSACTIONS];
    float withdrawHistory[MAX_TRANSACTIONS];
    float transferHistory[MAX_TRANSACTIONS];
    int transactionCount;
} Account;
Account accounts[MAX_ACCOUNTS];
int accountCount = 0;
void printHeader() {
    printf("\n\t\t\t\tBANKING SYSTEM\n\n");
    printf("\t\t********************************************\n");
    printf("\t\t*                                          *\n");
    printf("\t\t*  WELCOME TO OUR CBI BANKING SYSTEM       *\n");
    printf("\t\t*                                          *\n");
    printf("\t\t********************************************\n");
}
void displayMenu() {
    printf("\nChoose what you want to do\n");
    printf("1 - Balance Enquiry\n");
    printf("2 - Deposit\n");
    printf("3 - Withdraw\n");
    printf("4 - Transfer\n");
    printf("5 - View Transaction History\n");
    printf("6 - Account Details\n");
    printf("7 - Change Password\n");
    printf("8 - Apply Interest\n");
    printf("9 - Exit\n");
}
int findAccount(int accountNo) {
    for(int i = 0; i < accountCount; i++) {
        if(accounts[i].accountNo == accountNo) {
            return i;
        }
    }
    return -1;
}

void deposit(Account *acc) {
    float dep;
    printf("\n\t\t\t*DEPOSIT AMOUNT*\n\n");
    printf("How much money do you want to deposit: ");
    scanf("%f", &dep);
    if(dep > 0 && dep <= 20000) {
        acc->balance += dep;
        acc->depositHistory[acc->transactionCount++] = dep;
        printf("\nYour %.2fRs deposited in your account.\n\n", dep);
    } else if(dep > 20000) {
        printf("\nYou can't deposit that much amount in one time.\n\n");
    } else {
        printf("\nInvalid deposit amount\n");
    }
}

void withdraw(Account *acc) {
    float draw;
    printf("\n\t\t*WITHDRAW AMOUNT*\n\n");
    printf("How much money do you want to withdraw: ");
    scanf("%f", &draw);
    if(draw <= acc->balance && draw <= 40000) {
        acc->balance -= draw;
        acc->withdrawHistory[acc->transactionCount++] = draw;
        printf("\nYou just withdrew %.2fRs\n\n", draw);
    } else if(draw > 40000) {
        printf("\nYou can't withdraw that much amount in one time.\n\n");
    } else {
        printf("\nYou don't have enough money\n\n");
    }
}

void transfer(Account *acc) {
    int account2Index;
    float transfer;
    int account2;
    printf("\t\t\tTRANSFER AMOUNT \n\n");
    printf("\n\t\tAccount You Want To Transfer: ");
    scanf("%d", &account2);
    account2Index = findAccount(account2);
    if(account2Index == -1) {
        printf("Account not found.\n");
        return;
    }
    printf("\nHow much amount?: ");
    scanf("%f", &transfer);
    if(acc->balance >= transfer) {
        acc->balance -= transfer;
        accounts[account2Index].balance += transfer;
        acc->transferHistory[acc->transactionCount++] = transfer;
        printf("\nYour %.2fRs successfully transferred\n\n", transfer);
    } else {
        printf("\nYou do not have sufficient balance\n\n");
    }
}

void viewTransactionHistory(Account *acc) {
    printf("\nTransaction History:\n");
    printf("Deposits:\n");
    for(int i = 0; i < acc->transactionCount; i++) {
        if(acc->depositHistory[i] > 0) {
            printf("%.2fRs\n", acc->depositHistory[i]);
        }
    }
    printf("Withdrawals:\n");
    for(int i = 0; i < acc->transactionCount; i++) {
        if(acc->withdrawHistory[i] > 0) {
            printf("%.2fRs\n", acc->withdrawHistory[i]);
        }
    }
    printf("Transfers:\n");
    for(int i = 0; i < acc->transactionCount; i++) {
        if(acc->transferHistory[i] > 0) {
            printf("%.2fRs\n", acc->transferHistory[i]);
        }
    }
}

void accountDetails(Account *acc) {
    printf("\n\t\t\t*ACCOUNT DETAILS*\n\n");
    printf("Your name: %s\n", acc->name);
    printf("Your account no: %d\n", acc->accountNo);
    printf("Your current balance: %.2fRs\n", acc->balance);
}

void changePassword(Account *acc) {
    char newPassword[MAX_PASSWORD_LENGTH];
    printf("\nEnter your new password: ");
    scanf("%s", newPassword);
    strncpy(acc->password, newPassword, MAX_PASSWORD_LENGTH - 1);
    acc->password[MAX_PASSWORD_LENGTH - 1] = '\0'; 
    printf("Password successfully changed!\n");
}

void applyInterest(Account *acc) {
    float interest = acc->balance * INTEREST_RATE;
    acc->balance += interest;
    printf("Interest of %.2fRs has been applied to your account.\n", interest);
}
int main() {
    accounts[0].balance = 40000;
    strcpy(accounts[0].name, "Soaib Aslam");
    accounts[0].accountNo = 3641884681;
    strcpy(accounts[0].password, "Soaib@123"); 
    accountCount = 1; 

    int accountNo;
    char password[MAX_PASSWORD_LENGTH];
    int accountIndex;
    
    printHeader();
    printf("Please enter your account no.: ");
    scanf("%d", &accountNo);
    accountIndex = findAccount(accountNo);
    
    if (accountIndex == -1) {
        printf("Account not found.\n");
        return 1;
    }
    
    printf("Please enter your password: ");
    scanf("%s", password);
    
    if (strcmp(accounts[accountIndex].password, password) != 0) {
        printf("Incorrect password.\n");
        return 1;
    }

    int transaction = 1;
    while(transaction == 1) {
        int option;
        displayMenu();
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("\t\t\t*BALANCE ENQUIRY*\n\n");
                printf("Your current balance is: %.2fRs\n", accounts[accountIndex].balance);
                break;
            case 2:
                deposit(&accounts[accountIndex]);
                break;
            case 3:
                withdraw(&accounts[accountIndex]);
                break;
            case 4:
                transfer(&accounts[accountIndex]);
                break;
            case 5:
                viewTransactionHistory(&accounts[accountIndex]);
                break;
            case 6:
                accountDetails(&accounts[accountIndex]);
                break;
            case 7:
                changePassword(&accounts[accountIndex]);
                break;
            case 8:
                applyInterest(&accounts[accountIndex]);
                break;
            case 9:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid transaction\n");
        }
        printf("Do you want to do another transaction?\n");
        printf("1. Yes 2. No\n");
        scanf("%d", &transaction);
    }

    printf("\n\t\t\t    -----------------------");
    printf("\n\t\t\t\tCBI BANK LIMITED\n");
    printf("\t\t\t    -----------------------\n\n");
    printf("\t\t\tDate: 3/5/16\t   Time: 10:20 AM\n");
    printf("\n\t\t\tYour name: %s\n", accounts[accountIndex].name);
    printf("\t\t\tYour account no: %d\n", accounts[accountIndex].accountNo);
    printf("\t\t\tYour final balance: %.2fRs\n", accounts[accountIndex].balance);
    printf("\n\t\t\t\t    Thank you! \n");
    printf("\t\t\t   Welcome to CBI Banking System\n");
    printf("\t\t\t      www.CBIBANKINGSYSTEM.com\n");

    return 0;
}
