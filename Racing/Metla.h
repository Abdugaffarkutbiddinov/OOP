//
// Created by 444 on 30.10.2020.
//

#ifndef LAB3NEW_METLA_H
#define LAB3NEW_METLA_H

#include "AirTransport.h"

class Metla : public AirTransport {
public:
    Metla() {
        speed = 20;
    }
    std::string getName() override {
        return "Metla";
    }
protected:
    double calcDistanceReducer(double trackDistance) override  {
        return (int)(trackDistance / 1000) * 0.01;
    }
};


#endif //LAB3NEW_METLA_H
