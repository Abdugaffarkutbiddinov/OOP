cmake_minimum_required(VERSION 3.15)
project(lab3new)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab3new main.cpp Transport.h AirTransport.h LandTransport.h BactrianCamel.h FastCamel.h HybridShoes.h Centaur.h CarpetPlane.h Stupa.h Metla.h Race.h CommonFactory.h AirFactory.h LandFactory.h Engine.h Factory.h)