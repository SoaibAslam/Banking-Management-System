# Banking System Project

A simple command-line banking system implemented in C. This project simulates essential banking functionalities such as balance inquiry, deposits, withdrawals, fund transfers, transaction history, and password management.

## Table of Contents
- [Features](#features)
- [Setup and Usage](#setup-and-usage)
- [Account Management](#account-management)
- [Transactions](#transactions)
- [Contributing](#contributing)
- [License](#license)

## Features

- **Balance Inquiry**: Check your current account balance.
- **Deposits**: Deposit up to INR 40,000 per transaction.
- **Withdrawals**: Withdraw up to INR 40,000 per transaction.
- **Funds Transfer**: Transfer funds between accounts.
- **Transaction History**: View deposit, withdrawal, and transfer history.
- **Password Management**: Change account password for added security.
- **Interest Application**: Apply a 3% interest to the current balance.

## Setup and Usage

1. **Compile the Code**:
   - Use a C compiler like `gcc` to compile the code:
     ```bash
     gcc banking_system.c -o banking_system
     ```
2. **Run the Program**:
   - Run the compiled program:
     ```bash
     ./banking_system
     ```

## Account Management

1. **Create Account**:
   - Users can create a new account with a unique account number and password.
2. **Login**:
   - Use the account number and password to access existing accounts.
   
## Transactions

### Deposit
- Add money to your account (maximum limit of INR 40,000 per transaction).

### Withdraw
- Withdraw money from your account if sufficient balance is available (maximum limit of INR 40,000 per transaction).

### Transfer
- Transfer funds to another account within the system.

### Transaction History
- View a history of deposits, withdrawals, and transfers.

### Apply Interest
- Apply a 3% interest to the current balance to simulate annual interest accrual.

## Contributing

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit changes (`git commit -m 'Add a new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a Pull Request.

## License

This project is licensed under the MIT License.

Code : https://github.com/SoaibAslam/Banking-Management-System/blob/main/Banking%20Management%20System.cpp