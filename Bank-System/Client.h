//
// Created by 444 on 05.12.2020.
//

#ifndef LABA5_CLIENT_H
#define LABA5_CLIENT_H


#include <string>
#include <utility>

class Client {
private:
    std::string name;
    std::string surname;
    std::string passportID;
    std::string address;
public:
    void setName(const std::string& n)  {
        name = n;
    }
    void setSurname(const std::string& sn) {
        surname = sn;
    }
    void setPassportID(const std::string& pID) {
        passportID = pID;
    }
    void setAddress(const std::string& add) {
        address = add;
    }
    std::string getName() const {
        return name;
    }
    std::string getSurname() const {
        return surname;
    }
    std::string getPassportID() const  {
        return passportID;
    }
    std::string getAddress() const  {
        return address;
    }

    bool operator == (const Client& other) const {
        return name == other.name && surname == other.surname;
    }

    bool operator < (const Client& other) const {
        return name.length() < other.name.length();
    }

};
#endif //LABA5_CLIENT_H
