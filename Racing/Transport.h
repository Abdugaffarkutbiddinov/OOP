//
// Created by 444 on 30.10.2020.
//

#ifndef LAB3NEW_TRANSPORT_H
#define LAB3NEW_TRANSPORT_H

#include "string"
class Transport {
public:
    virtual double calcTime(double trackDistance) = 0;
    virtual ~Transport() = default;
    virtual std::string getName() = 0;
protected:
    double speed;
};


#endif //LAB3NEW_TRANSPORT_H
