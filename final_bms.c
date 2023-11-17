#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Account* createAccount(int accountNumber, const char* accountHolder, float initialBalance, long long int aadhaar, const char* profession);
struct Customer* createCustomer(const char* username, const char* password);
void deposit(struct Account* account, float amount);
void withdraw(struct Account* account, float amount);
void applyHomeLoan();
float calculateRecurringDeposit(float monthlyDeposit, float interestRate, int tenureMonths);
int generateCreditCard();
struct Customer* findCustomer(struct Customer* head, const char* username, const char* password);
void closeAccount(struct Customer* customer);
void displayAccountDetails(struct Account* account);

struct Account {
    int accountNumber;
    char accountHolder[100];
    float balance;
    long long int aadhaar;
    char profession[100];
    struct Account* next;
};

struct Customer {
    char username[100];
    char password[100];
    struct Account* account;
    struct Customer* next;
};

struct Account* createAccount(int accountNumber, const char* accountHolder, float initialBalance, long long int aadhaar, const char* profession) {
    struct Account* newAccount = (struct Account*)malloc(sizeof(struct Account));
    if (newAccount == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    newAccount->accountNumber = accountNumber;
    strncpy(newAccount->accountHolder, accountHolder, sizeof(newAccount->accountHolder));
    newAccount->balance = initialBalance;
    newAccount->aadhaar = aadhaar;
    strncpy(newAccount->profession, profession, sizeof(newAccount->profession));
    newAccount->next = NULL;
    return newAccount;
}

struct Customer* createCustomer(const char* username, const char* password) {
    struct Customer* newCustomer = (struct Customer*)malloc(sizeof(struct Customer));
    if (newCustomer == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strncpy(newCustomer->username, username, sizeof(newCustomer->username));
    strncpy(newCustomer->password, password, sizeof(newCustomer->password));
    newCustomer->account = NULL;
    newCustomer->next = NULL;
    return newCustomer;
}

void deposit(struct Account* account, float amount) {
    if (amount > 0) {
        account->balance += amount;
        printf("Deposited Rs.%.2f. New balance: Rs.%.2f\n", amount, account->balance);
    } else {
        printf("Invalid deposit amount. Please enter a positive amount.\n");
    }
}

void withdraw(struct Account* account, float amount) {
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrawn Rs.%.2f. New balance: Rs.%.2f\n", amount, account->balance);
    } else {
        printf("Invalid withdrawal amount or insufficient balance. Please check and try again.\n");
    }
}

void applyHomeLoan() {
    int employed;
    printf("Are you employed? (1 for Yes, 0 for No): ");
    scanf("%d", &employed);

        int salaried;
        printf("Salaried/business? (1 for salaried, 0 for business): ");
        scanf("%d", &salaried);

            int age;
            printf("Enter your age: ");
            scanf("%d", &age);

            if (age > 20 && age < 50) {
                float loanAmount;
                printf("Enter the amount needed for the loan: Rs.");
                scanf("%f", &loanAmount);

                if (loanAmount >= 1000000) {
                    char purpose[20];
                    printf("Enter the purpose of the loan (purchase/construction/repair): ");
                    scanf("%s", purpose);

                    float interestRate = 8.5; 

                    printf("\nLoan details:\n");
                    printf("Amount: Rs.%.2f\n", loanAmount);
                    printf("Interest Rate: %.2f%%\n", interestRate);
                    printf("Loan Tenure: 20 years\n");

                    float totalInterest = (loanAmount * interestRate * 20) / 100;

                    printf("Total Interest: Rs.%.2f\n", totalInterest);
                } 
                
                else {
                    printf("Loan amount is too low. Minimum loan amount is Rs. 10 lakh.\n");
                }
            } 
            
            else {
                printf("Age should be between 20 and 50 to apply for a home loan.\n");
            }
}

float calculateRecurringDeposit(float monthlyDeposit, float interestRate, int tenureMonths) {
    float monthlyInterestRate = interestRate / 1200.0;

    int totalPayments = tenureMonths;

    float maturityAmount = monthlyDeposit * (pow(1 + monthlyInterestRate, totalPayments) - 1) / monthlyInterestRate * (1 + monthlyInterestRate);

    return maturityAmount;
}

int generateCreditCard() {
    float annualIncome;
    printf("\nEnter your annual income (in lakhs): ");
    scanf("%f", &annualIncome);

    if (annualIncome >= 6.0) {
        unsigned long long int creditCardNumber = 100000000000 + rand() % 900000000000;
        printf("Congratulations! Your credit card number is: %llu\n", creditCardNumber);
        return 1; 
    } 
    else {
        printf("Sorry, your annual income is below 6 lakhs. You are not eligible for a credit card.\n");
        return 0; 
    }
}

struct Customer* findCustomer(struct Customer* head, const char* username, const char* password) {
    struct Customer* current = head;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0 && strcmp(current->password, password) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void closeAccount(struct Customer* customer) {
    if (customer->account != NULL) {
        free(customer->account);
        customer->account = NULL;
    }
}

void displayAccountDetails(struct Account* account) {
    printf("\nAccount Number: %d\n", account->accountNumber);
    printf("Account Holder: %s\n", account->accountHolder);
    printf("Aadhaar Card Number: %lld\n", account->aadhaar);
    printf("Profession: %s\n", account->profession);
    printf("Balance: Rs.%.2f\n", account->balance);
}

int main() {
    struct Customer* customerList = NULL;
    int nextAccountNumber = 1001;

    printf("Bank Management System\n\n");

    while (1) {
        int choice;
        printf("Main Menu:\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char username[100];
                char password[100];
                char accountHolder[100];
                char profession[30];
                float initialDeposit;
                long long int aadhaar;

                printf("\nUsername: ");
                scanf("%s", username);

                printf("Password: ");
                scanf("%s", password);

                printf("Account Holder Name: ");
                getchar();  
                fgets(accountHolder, sizeof(accountHolder), stdin);
                accountHolder[strcspn(accountHolder, "\n")] = '\0';  

                printf("Enter your 12 digit Aadhaar card number: ");
                scanf("%lld", &aadhaar);

                printf("Enter your profession: ");
                getchar();  
                fgets(profession, sizeof(profession), stdin);
                profession[strcspn(profession, "\n")] = '\0';
                
                printf("Initial Deposit: Rs.");
                scanf("%f", &initialDeposit);

                struct Customer* newCustomer = createCustomer(username, password);
                if (newCustomer == NULL) {
                    break;
                }
                struct Account* newAccount = createAccount(nextAccountNumber++, accountHolder, initialDeposit, aadhaar, profession);
                if (newAccount == NULL) {
                    free(newCustomer);
                    break;
                }
                newCustomer->account = newAccount;

                if (customerList == NULL) {
                    customerList = newCustomer;
                } 
                else {
                    
                    struct Customer* current = customerList;
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = newCustomer;
                }
                printf("Account created successfully. \n\n");
                break;
            }
            case 2: {
                char username[100];
                char password[100];

                printf("\nUsername: ");
                scanf("%s", username);

                printf("Password: ");
                scanf("%s", password);

                struct Customer* loggedInCustomer = findCustomer(customerList, username, password);
                if (loggedInCustomer != NULL) {
                    if (loggedInCustomer->account != NULL) {
                        printf("Authentication successful. Welcome, %s!\n\n", loggedInCustomer->account->accountHolder);
                        int loggedIn = 1;

                        while (loggedIn) {
                            int accountChoice;
                            printf("\nExplore your Account:\n");
                            printf("\n1. Check Balance\n");
                            printf("2. Deposit\n");
                            printf("3. Withdraw\n");
                            printf("4. Fixed Deposit\n");
                            printf("5. Recurring Deposit\n");
                            printf("6. Credit Card Application\n");
                            printf("7. Home Loan Application\n");
                            printf("8. Close Account\n");
                            printf("9. Logout\n");
                            printf("10. Exit\n\n");
                            printf("Enter your choice: ");
                            scanf("%d", &accountChoice);

                            switch (accountChoice) {

                                case 1:{
                                    displayAccountDetails(loggedInCustomer->account);
                                    break;
                                }

                                case 2: {
                                    float depositAmount;
                                    printf("\nEnter the amount to deposit: Rs.");
                                    scanf("%f", &depositAmount);
                                    deposit(loggedInCustomer->account, depositAmount);
                                    break;
                                }

                                case 3: {
                                    float withdrawAmount;
                                    printf("\nEnter the amount to withdraw: Rs.");
                                    scanf("%f", &withdrawAmount);
                                    withdraw(loggedInCustomer->account, withdrawAmount);
                                    break;
                                }

                                 case 4: {
                                    float fixedDepositAmount;
                                    int fixedDepositTerm;
                                    
                                    printf("\nEnter the amount to invest in Fixed Deposit: Rs.");
                                    scanf("%f", &fixedDepositAmount);

                                    printf("Enter the term of the Fixed Deposit (in months): ");
                                    scanf("%d", &fixedDepositTerm);

                                    if (fixedDepositAmount > 0 && fixedDepositTerm >= 1) {
                                        float interestRate = 0.05;  
                                        float interest = (fixedDepositAmount * interestRate * fixedDepositTerm) / 12.0;

                                        loggedInCustomer->account->balance += fixedDepositAmount + interest;
                                        
                                        printf("\nFixed Deposit of Rs.%.2f for %d months created successfully.\n", fixedDepositAmount, fixedDepositTerm);
                                        printf("Interest Earned: Rs.%.2f\n", interest);
                                        printf("New balance: Rs.%.2f\n", loggedInCustomer->account->balance);
                                    } else {
                                        printf("Invalid input for Fixed Deposit. Please enter a valid amount and term.\n");
                                    }
                                    break;
                                }

                                case 5: {
                                    float monthlyDeposit, interestRate;
                                    int tenureMonths;

                                    printf("\nEnter the monthly deposit amount: Rs.");
                                    scanf("%f", &monthlyDeposit);

                                    printf("Enter the annual interest rate: ");
                                    scanf("%f", &interestRate);

                                    printf("Enter the tenure in months: ");
                                    scanf("%d", &tenureMonths);

                                    float maturityAmount = calculateRecurringDeposit(monthlyDeposit, interestRate, tenureMonths);
                                    printf("\nMaturity Amount after %d months: Rs.%.2f\n", tenureMonths, maturityAmount);
                                    break;
                                }

                                case 6: {
                                    int result = generateCreditCard();
                                    if (result == 1) {
                                        printf("Credit card generated successfully!\n");
                                    }
                                    break;
                                }

                                case 7: {
                                    applyHomeLoan();
                                    break;
                                }

                                case 8: {
                                    closeAccount(loggedInCustomer);
                                    printf("Account closed.\n");
                                    loggedInCustomer = NULL; 
                                    loggedIn = 0;
                                    break;
                                }

                                case 9: {
                                    printf("Logging out. Thank You!\n");
                                    loggedInCustomer = NULL; 
                                    loggedIn = 0;
                                    break;
                                }

                                case 10: {
                                    printf("Thank You! Visit again!\n");
                                    exit(0);
                                }
                                
                                default:
                                    printf("Invalid choice. Please try again.\n");
                            }
                        }
                    } 
                    else {
                        printf("Account is closed. Please create a new account or contact customer support.\n");
                    }
                } 
                else {
                    printf("Authentication failed. Please try again.\n");
                }
                break;
            }
            
            case 3:
                printf("Thank You!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
