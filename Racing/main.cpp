#include <iostream>
#include "CommonFactory.h"
#include "AirFactory.h"
#include "Engine.h"
#include "LandFactory.h"

int main() {
    try {
        Factory* factory = new LandFactory();
        Engine engine(factory);

        engine.createRace(10000);
        engine.addTransport("BactrianCamel");
        engine.addTransport("FastCamel");
        engine.addTransport("Centaur");
        engine.addTransport("HybridShoes");
        std::cout << engine.startRace()->getName() << "\n";

        delete factory;
        factory = new AirFactory();
        engine.setFactory(factory);
        engine.createRace(10000);
        engine.addTransport("CarpetPlane");
        engine.addTransport("Stupa");
        engine.addTransport("Metla");
        std::cout << engine.startRace()->getName() << "\n";

        delete factory;
        factory = new CommonFactory();
        engine.setFactory(factory);
        engine.createRace(10000);
        engine.addTransport("CarpetPlane");
        engine.addTransport("Stupa");
        engine.addTransport("Metla");
        engine.addTransport("BactrianCamel");
        engine.addTransport("FastCamel");
        engine.addTransport("Centaur");
        engine.addTransport("HybridShoes");
        std::cout << engine.startRace()->getName() << "\n";
        delete factory;
    }
    catch (const std::runtime_error& error) {
        std::cout << error.what() << "\n";
    }
    return 0;
}