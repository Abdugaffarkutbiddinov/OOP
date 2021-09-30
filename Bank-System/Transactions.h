//
// Created by 444 on 05.12.2020.
//

#ifndef LABA5_TRANSACTIONS_H
#define LABA5_TRANSACTIONS_H

#include "BankAccount.h"
class Transactions {
protected:
    int transactionID;
public:
    virtual ~Transactions() = default;
    virtual void Execute() const = 0;
    virtual void Cancel() const = 0;
public:
    int getTransactionID() {
        return transactionID;
    }

};
#endif //LABA5_TRANSACTIONS_H
