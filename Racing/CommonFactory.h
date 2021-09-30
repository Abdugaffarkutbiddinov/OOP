//
// Created by 444 on 30.10.2020.
//

#ifndef LAB3NEW_COMMONFACTORY_H
#define LAB3NEW_COMMONFACTORY_H

#include <stdexcept>
#include "string"
#include "Transport.h"
#include "BactrianCamel.h"
#include "FastCamel.h"
#include "Centaur.h"
#include "HybridShoes.h"
#include "CarpetPlane.h"
#include "Stupa.h"
#include "Metla.h"
#include "Factory.h"

class CommonFactory : public Factory {
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
        if (name == "CarpetPlane")
            return new CarpetPlane();
        if (name == "Stupa")
            return new Stupa();
        if (name == "Metla")
            return new Metla();
        else throw std::runtime_error("Invalid transport!");
    }
};


#endif //LAB3NEW_COMMONFACTORY_H
