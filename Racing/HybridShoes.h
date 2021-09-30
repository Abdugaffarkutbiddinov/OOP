//
// Created by 444 on 30.10.2020.
//

#ifndef LAB3NEW_HYBRIDSHOES_H
#define LAB3NEW_HYBRIDSHOES_H

#include "LandTransport.h"

class HybridShoes : public LandTransport {
public:
    HybridShoes() {
        speed = 6;
        restInterval = 60;
    }
    std::string getName() override {
        return "HybridShoes";
    }
private:
    double calcRestInterval(int restCount) override {
        if (restCount < 1)
            return 10;
        else
            return 5;
    }
};


#endif //LAB3NEW_HYBRIDSHOES_H
