//
// Created by 444 on 05.12.2020.
//

#ifndef LABA5_WITHDRAWAL_H
#define LABA5_WITHDRAWAL_H

#include "Transactions.h"

class Withdrawal : public Transactions{
private:

BankAccount *bankAccount;
double money;
public:
    Withdrawal(int transactionID,BankAccount *bankAccount,double money) {
        this->transactionID = transactionID;
        this->bankAccount = bankAccount;
        this->money = money;
    }
    void Execute() const override {
        bankAccount->withdrawal(money);
    }

    void Cancel() const override {
        bankAccount->refill(money);
}
};
#endif //LABA5_WITHDRAWAL_H
