//
// Created by 444 on 07.12.2020.
//

#ifndef LABA5_SUSPICIOUSACCOUNT_H
#define LABA5_SUSPICIOUSACCOUNT_H

#include "BankAccount.h"

class SuspiciousAccount : public BankAccount {
protected:
    BankAccount *bankAccount;
    double limit;
public:
    SuspiciousAccount(BankAccount *bankAccount, double limit) {
        this->limit = limit;
        this->bankAccount = bankAccount;
    }

    void withdrawal(double money_) override {
        if(money_ < limit) {
            bankAccount->withdrawal(money_);
            limit -= money_;
        }else throw std::runtime_error("forbidden withdrawal operation for suspicious account\n");
    }

    void transfer(double money_, BankAccount *anotherAccount) override {
        if(money_ < limit) {
            bankAccount->transfer(money_,anotherAccount);
            limit -= money_;
        }else throw std::runtime_error("forbidden transfer operation for suspicious account\n");
    }

    void refill(double money_) override {
        bankAccount->refill(money_);
    }

    BankAccount* release() {
        return bankAccount;
    }
};
#endif //LABA5_SUSPICIOUSACCOUNT_H
