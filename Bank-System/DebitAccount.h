//
// Created by 444 on 05.12.2020.
//

#ifndef LABA5_DEBITACCOUNT_H
#define LABA5_DEBITACCOUNT_H


#include <iostream>
#include "BankAccount.h"

class DebitAccount : public BankAccount{
private:
    double interestRate;
    double pennyBank;
public:
    DebitAccount(int bankAccountID, double interestRate) {
        this->bankAccountID = bankAccountID;
        this->interestRate = interestRate/365;
        this->accountType = DEBIT_ACCOUNT;
        this->createdTime = Date::getNow();
        //this->money = 0;
    }

    void withdrawal(double money_) override  {
        if (money >= money_) {
            BankAccount::withdrawal(money_);
        }else throw std::runtime_error("lack of money in your Bank Account\n");
    }

    void transfer(double money_, BankAccount *anotherAccount) override {
        BankAccount::transfer(money_,anotherAccount);
    }

    void addRestInterest() {
        pennyBank += money * interestRate;
    }

    void monthlyAccrual() {
        money += pennyBank;
    }

    double getInterestRate () {
        return interestRate;
    }

    double getPennyBank() {
        return pennyBank;
    }

};
#endif //LABA5_DEBITACCOUNT_H
