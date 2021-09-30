//
// Created by 444 on 05.12.2020.
//

#ifndef LABA5_TRANSFER_H
#define LABA5_TRANSFER_H

#include "Transactions.h"

class Transfer : public Transactions {
private:
BankAccount *bankAccount;
double money;
BankAccount *anotherAccount;

public:
    Transfer(int transactionID,BankAccount *bankAccount,BankAccount *anotherAccount, double money) {
        this->transactionID = transactionID;
        this->money = money;
        this->bankAccount = bankAccount;
        this->anotherAccount = anotherAccount;

    }
    void Execute() const override {
        bankAccount->transfer(money,anotherAccount);
    }
    void Cancel() const override {
        bankAccount->transfer(money,anotherAccount);
    }

};
#endif //LABA5_TRANSFER_H
