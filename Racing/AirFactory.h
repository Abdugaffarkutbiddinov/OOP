//
// Created by 444 on 30.10.2020.
//

#ifndef LAB3NEW_AIRFACTORY_H
#define LAB3NEW_AIRFACTORY_H

#include "CommonFactory.h"

class AirFactory : public Factory {
public:
    Transport* createTransport(const std::string& name) override {
        if (name == "CarpetPlane")
            return new CarpetPlane();
        if (name == "Stupa")
            return new Stupa();
        if (name == "Metla")
            return new Metla();
        throw std::runtime_error("Invalid transport!");
    }
};


#endif //LAB3NEW_AIRFACTORY_H
