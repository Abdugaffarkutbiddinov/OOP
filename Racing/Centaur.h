//
// Created by 444 on 30.10.2020.
//

#ifndef LAB3NEW_CENTAUR_H
#define LAB3NEW_CENTAUR_H

#include "LandTransport.h"

class Centaur : public LandTransport {
public:
    Centaur() {
        speed = 15;
        restInterval = 8;
    }
    std::string getName() override {
        return "Centaur";
    }
protected:
    double calcRestInterval(int restCount) override {
        return 2;
    }
};


#endif //LAB3NEW_CENTAUR_H
