//
// Created by 444 on 30.10.2020.
//

#ifndef LAB3NEW_FASTCAMEL_H
#define LAB3NEW_FASTCAMEL_H

#include "LandTransport.h"

class FastCamel : public LandTransport {
public:
    FastCamel() {
        speed = 40;
        restInterval = 10;
    }
    std::string getName() override {
        return "FastCamel";
    }
protected:
    double calcRestInterval(int restCount) override {
        if (restCount < 1)
            return 5;
        else if (restCount < 2)
            return 6.5;
        else
            return 8;
    }
};


#endif //LAB3NEW_FASTCAMEL_H
