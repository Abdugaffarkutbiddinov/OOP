//
// Created by 444 on 30.10.2020.
//

#ifndef LAB3NEW_LANDFACTORY_H
#define LAB3NEW_LANDFACTORY_H
#include "CommonFactory.h"

class LandFactory : public Factory {
public:
    Transport* createTransport(const std::string& name) override {
        if (name == "BactrianCamel")
            return new BactrianCamel();
        if (name == "FastCamel")
            return new FastCamel();
        if (name == "Centaur")
            return new Centaur();
        if (name == "HybridShoes")
            return new HybridShoes();
        else throw std::runtime_error("Invalid transport!");
    }
};


#endif //LAB3NEW_LANDFACTORY_H
