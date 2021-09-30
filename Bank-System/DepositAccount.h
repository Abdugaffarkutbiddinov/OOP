//
// Created by 444 on 05.12.2020.
//

#ifndef LABA5_DEPOSITACCOUNT_H
#define LABA5_DEPOSITACCOUNT_H

#include "BankAccount.h"
#include "DebitAccount.h"
#include "Date.h"
#include <ctime>
#include <chrono>
#include <iostream>

class DepositAccount : public DebitAccount {
private:
    Date forbiddenTillDate;
public:
    DepositAccount(int bankAccountID, Date forbiddenTillDate, double money) : DebitAccount(bankAccountID, calcInterestRate()) {
        this->forbiddenTillDate = forbiddenTillDate;
        this->money = money;
        this->accountType = DEPOSIT_ACCOUNT;
        //this->createdTime = Date::getNow();
    }
    //should be static?
     double calcInterestRate() {
        if(money < 50000) {
            return (money * 0.3)/365;
        } else if(money > 50000 && money < 100000) {
            return (money * 0.35)/365;
        } else
        return (money * 0.4)/365;
    }

    void withdrawal(double money_) override {
        Date now = Date::getNow();
        if(forbiddenTillDate < now) {
            DebitAccount::withdrawal(money_);
            //withdrawal(money_);
        }else throw std::runtime_error("operation forbidden");
    }


    void transfer(double money_, BankAccount *anotherAccount) override {
        Date now = Date::getNow();

        if (forbiddenTillDate < now) {
            DebitAccount::transfer(money_,anotherAccount);
        }else throw std::runtime_error("operation forbidden");
    }

};
#endif //LABA5_DEPOSITACCOUNT_H
