//
// Created by 444 on 30.10.2020.
//

#ifndef LAB3NEW_AIRTRANSPORT_H
#define LAB3NEW_AIRTRANSPORT_H

#include "Transport.h"

class AirTransport : public Transport{
public:
    double calcTime(double trackDistance) override {
        return trackDistance * (1 - calcDistanceReducer(trackDistance)) / speed;
    }
    ~AirTransport() override = default;
protected:
    virtual double calcDistanceReducer(double trackDistance) = 0;
};


#endif //LAB3NEW_AIRTRANSPORT_H
