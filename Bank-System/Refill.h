//
// Created by 444 on 05.12.2020.
//

#ifndef LABA5_REFILL_H
#define LABA5_REFILL_H

#include "Transactions.h"

class Refill : public Transactions {
private:
    BankAccount *bankAccount;
    double money;
public:
    Refill(int transactionID,BankAccount *bankAccount,double money) {
        this->transactionID = transactionID;
        this->money = money;
        this->bankAccount = bankAccount;
    }
    void Execute() const override {
        bankAccount->refill(money);
    }
    void Cancel() const override {
        bankAccount->withdrawal(money);
    }
};
#endif //LABA5_REFILL_H
