//
// Created by 444 on 30.10.2020.
//

#ifndef LAB3NEW_BACTRIANCAMEL_H
#define LAB3NEW_BACTRIANCAMEL_H

#include "LandTransport.h"

class BactrianCamel : public LandTransport {
public:
    BactrianCamel() {
        speed = 10;
        restInterval = 30;
    }
    std::string getName() override {
        return "BactrianCamel";
    }

protected:
    double calcRestInterval(int restCount) override {
        if (restCount < 1)
            return 5;
        else
            return 8;
    }
};


#endif //LAB3NEW_BACTRIANCAMEL_H
