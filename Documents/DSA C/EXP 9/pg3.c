//write a program in c to create a double linked list for account details of bank customers such as ac no,name,balance.store details of n bank account holders and find total balance for al account holders
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Account {
    int acNo;
    char name[100];
    float balance;
    struct Account *prev;
    struct Account *next;
} Account;

Account* createAccount(int acNo, char* name, float balance) {
    Account* newAccount = (Account*)malloc(sizeof(Account));
    if (newAccount == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newAccount->acNo = acNo;
    strcpy(newAccount->name, name);
    newAccount->balance = balance;
    newAccount->prev = NULL;
    newAccount->next = NULL;
    return newAccount;
}

void insertAccount(Account** head, int acNo, char* name, float balance) {
    Account* newAccount = createAccount(acNo, name, balance);
    if (*head == NULL) {
        *head = newAccount;
    } else {
        Account* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newAccount;
        newAccount->prev = last;
    }
}

void calculateTotalBalance(Account* head) {
    float totalBalance = 0;
    Account* temp = head;
    while (temp != NULL) {
        totalBalance += temp->balance;
        temp = temp->next;
    }
    printf("Total balance of all account holders: %.2f\n", totalBalance);
}

int main() {
    int n, acNo;
    char name[100];
    float balance;
    Account* head = NULL;

    printf("Enter the number of bank account holders: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter account holder %d details:\n", i + 1);
        printf("Account Number: ");
        scanf("%d", &acNo);
        printf("Name: ");
        scanf("%s", name); 
        printf("Balance: ");
        scanf("%f", &balance);

        insertAccount(&head, acNo, name, balance);
    }

    calculateTotalBalance(head);


    return 0;
}
