//
// Created by 444 on 05.12.2020.
//

#ifndef LABA5_BANK_H
#define LABA5_BANK_H
//
//I got 1-2-3-4-5-6-7-8 M's in my bank account, yeah
//In my bank account, yeah
//In my bank account, yeah
//In my bank account, yeah
//In my bank account, yeah
//In my bank account, yeah
//
#include <vector>
#include <map>
#include "Client.h"
#include "BankAccount.h"
#include "Transactions.h"
#include "ClientBuilder.h"
#include "Date.h"
#include "DebitAccount.h"
#include "SuspiciousAccount.h"
#include "DepositAccount.h"
#include "CreditAccount.h"
#include "Withdrawal.h"
#include "Refill.h"
#include "Transfer.h"

class Bank {
private:
    std::map<int, Client> clients;
    std::map<int, std::vector<BankAccount *>> clientsAccounts;
    std::map<int, BankAccount *> accounts;
    std::map<int, Transactions *> transactions;
    int BankID;
    double annualInterestRate;
    double commission;
    double suspiciousLimit;
    double creditLimit;
public:
    Bank(int BankID, double annualInterestRate, double commission, double suspiciousLimit, double creditLimit) {
        this->BankID = BankID;
        this->annualInterestRate = annualInterestRate;
        this->commission = commission;
        this->suspiciousLimit = suspiciousLimit;
        this->creditLimit = creditLimit;
    }

    bool suspicious(const Client &client) {
        return (client.getPassportID().empty() || client.getAddress().empty());
    }

    void createDebit(Client &client) {
        BankAccount *bankAccount = new DebitAccount(getNextAccountID(), annualInterestRate);
        createAccount(client, bankAccount);
    }

    void createDeposit(Client &client, double depositSum, Date date) {
        BankAccount *bankAccount = new DepositAccount(getNextAccountID(), date, depositSum);
        createAccount(client, bankAccount);
    }

    void createCredit(Client &client) {
        BankAccount *bankAccount = new CreditAccount(getNextAccountID(), commission, creditLimit);
        createAccount(client, bankAccount);
    }

    void createAccount(Client &client, BankAccount *bankAccount) {
        if (suspicious(client)) {
            bankAccount->setIfSuspicious(true);
        }
        accounts[bankAccount->getAccountID()] = bankAccount;
        int id = getNextClientID();
        if (!containsClient(client)) {
            clientsAccounts[id] = std::vector<BankAccount *>();
            clients[id] = client;
        }
        clientsAccounts[id].push_back(bankAccount);
        std::cout << bankAccount->getIfSuspicious() << "\n";
    }

    void withdrawal(int accountID, double money) {
        if (!containsAccount(accountID))
            throw std::runtime_error("invalid account to withdrawal");
        BankAccount *bankAccount = accounts[accountID];

        if (bankAccount->getIfSuspicious()) {
            if (suspiciousLimit < money) {
                throw std::runtime_error("exceeds suspicious limit");
            }
        }

        Transactions *withdrawal = new Withdrawal(getNextTransactionId(), bankAccount, money);
        transact(withdrawal);
    }


    void refill(int accountID, double money) {
        if (!containsAccount(accountID))
            throw std::runtime_error("invalid account for refilling");
        BankAccount *bankAccount = accounts[accountID];
        Transactions *refill = new Refill(getNextTransactionId(), bankAccount, money);
        transact(refill);
    }

    void transfer(int accountID, int anotherAccountID, double money) {
        if (!containsAccount(accountID) || !containsAccount(anotherAccountID))
            throw std::runtime_error("invalid account id for transfer");
        BankAccount *bankAccount = accounts[accountID];
        BankAccount *anotherAccount = accounts[anotherAccountID];

        if (bankAccount->getIfSuspicious()) {
            if (suspiciousLimit < money) {
                throw std::runtime_error("exceeds suspicious limit!");
            }
        }

        Transactions *transfer = new Transfer(getNextTransactionId(), bankAccount, anotherAccount, money);
        transact(transfer);
    }

    void transact(Transactions *transaction) {
        transaction->Execute();
        transactions[transaction->getTransactionID()] = transaction;
    }

    void dataUpdate(const Client &client) {
        if (!containsClient(client))
            throw std::runtime_error("");
        int id;
        bool oldIsSus = false;
        for (auto &it : clients) {
            if (it.second == client) {
                oldIsSus = suspicious(it.second);
                it.second = client;
                id = it.first;
                break;
            }
        }
        if (!suspicious(client) && oldIsSus) {
            for (BankAccount *account : clientsAccounts[id]) {
                account->setIfSuspicious(false);
            }
        } else if (suspicious(client) && !oldIsSus) {
            for (BankAccount *account : clientsAccounts[id]) {
                account->setIfSuspicious(true);
            }
        }
    }


    void cancel(int transactionID) {
        if (!containsTransactions(transactionID))
            throw std::runtime_error("NO valid transaction");
        Transactions *transaction = transactions[transactionID];
        transaction->Cancel();
    }

    int getNextAccountID() {
        return accounts.size() + 1;
    }

    int getNextClientID() {
        return clients.size() + 1;
    }


    int getNextTransactionId() {
        return transactions.size() + 1;
    }

    bool containsClient(const Client &client) {
        for (const auto &it : clients) {
            if (it.second == client)
                return true;
        }
        return false;
    }

    bool containsAccount(int accountID) {
        return !(accounts.find(accountID) == accounts.end());
    }

    bool containsTransactions(int transactionID) {
        return !(transactions.find(transactionID) == transactions.end());
    }

    // probably i need interface debit+deposit
    void dailyInterestRate() {
        DebitAccount *daccount;
        for (auto &account : accounts) {
            if (account.second->getAccountType() != CREDIT_ACCOUNT) {
                account.second = (DebitAccount *) &daccount;
                Date now = Date::getNow();
                Date createdDay = daccount->getCreatedTime();
                if ((now - createdDay) > 0) {
                    daccount->addRestInterest();
                } else throw std::runtime_error("24 hours didnt pass yet");
            }
        }
    }

    void monthlyInterestRate() {
        DebitAccount *daccount;
        for (auto &account : accounts) {
            if (account.second->getAccountType() != CREDIT_ACCOUNT) {
                account.second = (DebitAccount *) &daccount;
                Date now = Date::getNow();
                //Date createdDay = daccount->getCreatedTime();
                if (now.getMDay() == 1) {
                    daccount->monthlyAccrual();
                } else throw std::runtime_error("1 month didnt pass yet");

            }
        }

    }

};

#endif //LABA5_BANK_H
