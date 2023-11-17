# Bank Management System

This is a simple command-line Bank Management System implemented in C. The program allows users to create accounts, log in, and perform various banking operations such as checking balance, depositing, withdrawing, applying for a home loan, and more.

## Table of Contents

1. [Features](#features)
2. [How to Use](#how-to-use)
3. [Functions](#functions)
4. [Requirements](#requirements)
5. [Compilation](#compilation)

## Features

- Account creation with a unique username and password.
- Secure login system.
- Basic banking operations such as deposit, withdrawal, and balance inquiry.
- Fixed Deposit and Recurring Deposit options.
- Credit card application based on annual income.
- Home loan application with eligibility criteria.
- Account closure functionality.
- User-friendly command-line interface.

## How to Use

1. Run the program and choose from the main menu options.
2. Create a new account by providing necessary details.
3. Log in using your username and password.
4. Explore various banking functionalities.
5. Log out or exit the program when done.

## Functions

- `createAccount`: Create a new bank account with initial details.
- `createCustomer`: Create a new customer with a username and password.
- `deposit`: Deposit funds into an account.
- `withdraw`: Withdraw funds from an account.
- `applyHomeLoan`: Apply for a home loan based on eligibility criteria.
- `calculateRecurringDeposit`: Calculate the maturity amount for a recurring deposit.
- `generateCreditCard`: Generate a credit card based on annual income.
- `findCustomer`: Find a customer by username and password.
- `closeAccount`: Close a bank account.
- `displayAccountDetails`: Display details of a bank account.

## Requirements

- C compiler (e.g., GCC)

## Compilation

```bash
gcc -c final_bms.c
gcc final_bms.o
a.exe 
```

