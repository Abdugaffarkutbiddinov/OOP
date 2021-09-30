//
// Created by 444 on 30.10.2020.
//

#ifndef LAB3NEW_CARPETPLANE_H
#define LAB3NEW_CARPETPLANE_H

#include "AirTransport.h"

class CarpetPlane : public AirTransport {
public:
    CarpetPlane() {
        speed = 10;
    }
    std::string getName() override {
        return "CarpetPlane";
    }
protected:
    double calcDistanceReducer(double trackDistance) override {
        if (trackDistance < 1000)
            return 0;
        else if (trackDistance < 5000)
            return 0.03;
        else if (trackDistance < 10000)
            return 0.1;
        else return 0.05;
    }
};


#endif //LAB3NEW_CARPETPLANE_H
