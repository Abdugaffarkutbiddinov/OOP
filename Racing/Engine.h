//
// Created by 444 on 30.10.2020.
//

#ifndef LAB3NEW_ENGINE_H
#define LAB3NEW_ENGINE_H


#include "Race.h"
#include "CommonFactory.h"

class Engine {
public:
    Engine(Factory* factory) {
        this->factory = factory;
    }
    Transport* startRace() {
        if (!race)
            throw std::runtime_error("Null pointer exception\n");
        return race->start();
    }
    void addTransport(const std::string& name) {
        if (!race || !factory)
            throw std::runtime_error("Null pointer exception\n");
        race->addTransport(factory->createTransport(name));
    }

    void setFactory(Factory* factory) {
        if (this->factory) {
            delete this->race;
            race = nullptr;
            this->factory = nullptr;
        }

        this->factory = factory;
    }

    void createRace(double trackDistance) {
        if (race)
            delete race;
        race = new Race(trackDistance);
    }

    ~Engine() {
        delete race;
    }
private:
    Factory* factory = nullptr;
    Race* race = nullptr;
};


#endif //LAB3NEW_ENGINE_H
