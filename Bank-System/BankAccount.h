//
// Created by 444 on 05.12.2020.
//

#ifndef LABA5_BANKACCOUNT_H
#define LABA5_BANKACCOUNT_H


#include <iostream>
#include "AccountType.h"
#include "Date.h"

class BankAccount {
protected:
    double money;
    int bankAccountID;
    bool isSuspicious;
    AccountType accountType;
    Date createdTime;
public:

    bool getIfSuspicious() {
        return isSuspicious;
    }

    void setIfSuspicious(bool stat) {
        isSuspicious = stat;
    }
    virtual void withdrawal(double money_) {
        money -= money_;
        std::cout << money << " left in your Bank Account " <<  bankAccountID << "\n";


    }

    virtual void refill(double money_) {
        money += money_;
        std::cout << money <<"  in your Bank Account after refilling " << bankAccountID << "\n";
    }

    virtual void transfer(double money_, BankAccount *anotherAccount) {
        withdrawal(money_);
        anotherAccount->refill(money_);
        std::cout << money_  << " transferred to " << anotherAccount->getAccountID() << "\n";
    }

    double getMoney() {
        return money;
    }
    int getAccountID() {
        return bankAccountID;
    }

    AccountType getAccountType() {
        return accountType;
    }

    Date getCreatedTime() {
        return createdTime;
    }
    ~BankAccount() = default;
};
#endif //LABA5_BANKACCOUNT_H
