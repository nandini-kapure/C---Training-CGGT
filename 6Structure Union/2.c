// 2. Program to handle financial transactions where each transaction (transaction ID, type) can be a deposit, withdrawal, or transfer. Use structs to define transactions and unions to represent transaction-specific details (e.g., amount, source account, destination account). Implement functions to process different types of transactions, update account balances, and generate transaction reports. Use dynamic memory to handle transaction data. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNT_LENGTH 50
#define MAX_TRANSACTIONS 100

#define DEPOSIT 'D'
#define WITHDRAWAL 'W'
#define TRANSFER 'T'

typedef union {
    float amount;                // For deposit and withdrawal
    struct {
        float amount;            // For transfer
        int source_account;      // Source account for transfer
        int destination_account; // Destination account for transfer
    } transfer_details;
} TransactionDetails;

// Struct to represent a financial transaction
typedef struct {
    int transaction_id;
    char transaction_type;  // 'D' for Deposit, 'W' for Withdrawal, 'T' for Transfer
    TransactionDetails details;
} Transaction;

// Struct to represent an account
typedef struct {
    int account_id;
    float balance;
} Account;

// Array to store transactions
Transaction *transactions[MAX_TRANSACTIONS];
int transaction_count = 0;

// Array to store accounts
Account *accounts[MAX_TRANSACTIONS];
int account_count = 0;

// Function to add a new account
void add_account(int account_id, float initial_balance) {
    if (account_count >= MAX_TRANSACTIONS) {
        printf("Cannot add more accounts. Max limit reached.\n");
        return;
    }

    Account *new_account = (Account *)malloc(sizeof(Account));
    new_account->account_id = account_id;
    new_account->balance = initial_balance;
    accounts[account_count++] = new_account;

    printf("Account with ID %d added successfully.\n", account_id);
}

// Function to deposit money into an account
void deposit(int account_id, float amount) {
    for (int i = 0; i < account_count; i++) {
        if (accounts[i]->account_id == account_id) {
            accounts[i]->balance += amount;
            printf("Deposited $%.2f into account %d. New balance: $%.2f\n", amount, account_id, accounts[i]->balance);
            return;
        }
    }
    printf("Account ID %d not found.\n", account_id);
}

// Function to withdraw money from an account
void withdraw(int account_id, float amount) {
    for (int i = 0; i < account_count; i++) {
        if (accounts[i]->account_id == account_id) {
            if (accounts[i]->balance >= amount) {
                accounts[i]->balance -= amount;
                printf("Withdrew $%.2f from account %d. New balance: $%.2f\n", amount, account_id, accounts[i]->balance);
            } else {
                printf("Insufficient funds in account %d.\n", account_id);
            }
            return;
        }
    }
    printf("Account ID %d not found.\n", account_id);
}

// Function to transfer money between two accounts
void transfer(int source_account_id, int destination_account_id, float amount) {
    Account *source = NULL, *destination = NULL;

    for (int i = 0; i < account_count; i++) {
        if (accounts[i]->account_id == source_account_id) {
            source = accounts[i];
        }
        if (accounts[i]->account_id == destination_account_id) {
            destination = accounts[i];
        }
    }

    if (source == NULL) {
        printf("Source account %d not found.\n", source_account_id);
        return;
    }

    if (destination == NULL) {
        printf("Destination account %d not found.\n", destination_account_id);
        return;
    }

    if (source->balance >= amount) {
        source->balance -= amount;
        destination->balance += amount;
        printf("Transferred $%.2f from account %d to account %d. New balances - Source: $%.2f, Destination: $%.2f\n",
               amount, source_account_id, destination_account_id, source->balance, destination->balance);
    } else {
        printf("Insufficient funds in source account %d.\n", source_account_id);
    }
}

// Function to create a new transaction
void create_transaction(int transaction_id, char transaction_type, TransactionDetails details) {
    if (transaction_count >= MAX_TRANSACTIONS) {
        printf("Cannot add more transactions. Max limit reached.\n");
        return;
    }

    Transaction *new_transaction = (Transaction *)malloc(sizeof(Transaction));
    new_transaction->transaction_id = transaction_id;
    new_transaction->transaction_type = transaction_type;
    new_transaction->details = details;

    transactions[transaction_count++] = new_transaction;
    printf("Transaction ID %d of type %c added successfully.\n", transaction_id, transaction_type);
}

// Function to generate a transaction report
void generate_transaction_report() {
    printf("\nTransaction Report:\n");
    for (int i = 0; i < transaction_count; i++) {
        printf("Transaction ID: %d\n", transactions[i]->transaction_id);
        printf("Transaction Type: %c\n", transactions[i]->transaction_type);

        if (transactions[i]->transaction_type == DEPOSIT) {
            printf("Amount Deposited: $%.2f\n", transactions[i]->details.amount);
        } else if (transactions[i]->transaction_type == WITHDRAWAL) {
            printf("Amount Withdrawn: $%.2f\n", transactions[i]->details.amount);
        } else if (transactions[i]->transaction_type == TRANSFER) {
            printf("Amount Transferred: $%.2f\n", transactions[i]->details.transfer_details.amount);
            printf("From Account ID: %d to Account ID: %d\n",
                   transactions[i]->details.transfer_details.source_account,
                   transactions[i]->details.transfer_details.destination_account);
        }
        printf("\n");
    }
}

// Main function to test the system
int main() {
    int choice, account_id, source_account, dest_account, transaction_id;
    float amount;
    
    // Adding some initial accounts
    add_account(1001, 1000.0);
    add_account(1002, 500.0);

    while (1) {
        printf("\nFinancial Transaction System\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Transfer\n");
        printf("4. Generate Transaction Report\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter account ID to deposit into: ");
                scanf("%d", &account_id);
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                deposit(account_id, amount);

                // Log the deposit transaction
                transaction_id = transaction_count + 1;
                TransactionDetails deposit_details = { .amount = amount };
                create_transaction(transaction_id, DEPOSIT, deposit_details);
                break;

            case 2:
                printf("Enter account ID to withdraw from: ");
                scanf("%d", &account_id);
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                withdraw(account_id, amount);

                // Log the withdrawal transaction
                transaction_id = transaction_count + 1;
                TransactionDetails withdrawal_details = { .amount = amount };
                create_transaction(transaction_id, WITHDRAWAL, withdrawal_details);
                break;

            case 3:
                printf("Enter source account ID: ");
                scanf("%d", &source_account);
                printf("Enter destination account ID: ");
                scanf("%d", &dest_account);
                printf("Enter transfer amount: ");
                scanf("%f", &amount);
                transfer(source_account, dest_account, amount);

                // Log the transfer transaction
                transaction_id = transaction_count + 1;
                TransactionDetails transfer_details = { .amount = amount, .transfer_details = { amount, source_account, dest_account } };
                create_transaction(transaction_id, TRANSFER, transfer_details);
                break;

            case 4:
                generate_transaction_report();
                break;

            case 5:
                printf("Exiting the system.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
