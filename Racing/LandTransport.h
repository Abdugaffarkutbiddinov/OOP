//
// Created by 444 on 30.10.2020.
//

#ifndef LAB3NEW_LANDTRANSPORT_H
#define LAB3NEW_LANDTRANSPORT_H

#include "Transport.h"

class LandTransport : public Transport {
public:
    double calcTime(double trackDistance) override {
        double restTime = 0;
        double distance = 0;
        int restCount = 0;
        while (distance < trackDistance) {
            distance += speed * restInterval;
            restTime += calcRestInterval(restCount++);
        }
        return trackDistance / speed + restTime;
    }
    ~LandTransport() override = default;
protected:
    double restInterval;
    virtual double calcRestInterval(int restCount) = 0;
};


#endif //LAB3NEW_LANDTRANSPORT_H
