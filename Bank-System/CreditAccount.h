//
// Created by 444 on 05.12.2020.
//

#ifndef LABA5_CREDITACCOUNT_H
#define LABA5_CREDITACCOUNT_H

#include "BankAccount.h"

class CreditAccount : public BankAccount {
private:
    double commission;
    double limit;
public:
    CreditAccount(int bankAccountID, double commission, double limit) {
        this->bankAccountID = bankAccountID;
        this->commission = commission;
        this->limit = limit;
        this->accountType = CREDIT_ACCOUNT;
        this->createdTime =  Date::getNow();
        //this->money = 0;
    }

    void withdrawal(double money_) override {
        if(limit >= money_ && money <= 0) {
            BankAccount::withdrawal(money_*commission);
            limit -= money_;
        }
          else throw std::runtime_error("exceeds credit limit\n");
    }

    void transfer(double money_,BankAccount *anotherAccount) override {
        if(limit >= money_ && money <= 0) {
            BankAccount::transfer(money_ * commission,anotherAccount);
        }
    }
};
#endif //LABA5_CREDITACCOUNT_H
