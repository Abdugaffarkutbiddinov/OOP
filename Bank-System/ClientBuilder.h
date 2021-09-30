//
// Created by 444 on 05.12.2020.
//

#ifndef LABA5_CLIENTBUILDER_H
#define LABA5_CLIENTBUILDER_H

#include <utility>

#include "Client.h"

class ClientBuilder {
private:
    Client client;
public:
    ClientBuilder() {
        this->reset();
    }
    ClientBuilder& setName(const std::string& name) {
        client.setName(name);
        return *this;
    }
    ClientBuilder& setSurname(const std::string& surname) {
        client.setSurname(surname);
        return *this;
    }
    ClientBuilder& setPassportID(const std::string& passportID) {
        client.setPassportID(passportID);
        return *this;
    }
    ClientBuilder& setAddress(const std::string& address) {
        client.setAddress(address);
        return *this;
    }

    Client build() {
        return client;
    }
    void reset(){
        this->client = Client();
    }

    Client GetProduct() {
        Client result = this->client;
        this->reset();
        return result;
    }
};
#endif //LABA5_CLIENTBUILDER_H
