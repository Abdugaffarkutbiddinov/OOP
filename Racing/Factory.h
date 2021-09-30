//
// Created by 444 on 30.10.2020.
//

#ifndef LAB3NEW_FACTORY_H
#define LAB3NEW_FACTORY_H


#include "Transport.h"

class Factory {
public:
    virtual Transport *createTransport(const std::string &name) = 0;
    virtual ~Factory() = default;
};


#endif //LAB3NEW_FACTORY_H
