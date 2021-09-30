//
// Created by 444 on 30.10.2020.
//

#ifndef LAB3NEW_STUPA_H
#define LAB3NEW_STUPA_H
#include "AirTransport.h"

class Stupa : public AirTransport{
public:
    Stupa() {
        speed = 8;
    }
    std::string getName() override {
        return "Stupa";
    }
protected:
    double calcDistanceReducer(double trackDistance) override {
        return 0.06;
    }
};


#endif //LAB3NEW_STUPA_H
