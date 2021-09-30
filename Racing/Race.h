//
// Created by 444 on 30.10.2020.
//

#ifndef LAB3NEW_RACE_H
#define LAB3NEW_RACE_H

#include <vector>
#include "Transport.h"
#include "climits"

class Race {
public:
    Race(double trackDistance) {
        this->trackDistance = trackDistance;
    }

    Race() {
        trackDistance = 0;
    }

    void addTransport(Transport *transport) {
        racers.push_back(transport);
    }

    Transport *start() {
        Transport *winner;
        double bestTime = LONG_LONG_MAX;
        for (Transport *racer : racers) {
            double time = racer->calcTime(trackDistance);
            if (time < bestTime) {
                bestTime = time;
                winner = racer;
            }
        }
        return winner;
    }

    ~Race() {
        for (Transport* racer : racers) {
            delete racer;
        }
    }

private:
    std::vector<Transport *> racers;
    double trackDistance;
};


#endif //LAB3NEW_RACE_H
