cmake_minimum_required(VERSION 3.15)
project(laba5)

set(CMAKE_CXX_STANDARD 17)

add_executable(laba5 main.cpp Bank.h Client.h BankAccount.h DebitAccount.h DepositAccount.h CreditAccount.h ClientBuilder.h Transactions.h Withdrawal.h Refill.h Transfer.h Date.h SuspiciousAccount.h Bank.cpp AccountType.h)