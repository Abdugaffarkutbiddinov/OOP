//
// Created by 444 on 06.12.2020.
//

#ifndef LABA5_DATE_H
#define LABA5_DATE_H

#include <chrono>
#include <iostream>

class Date {
private:
    tm time;
public:
//Write setters
    Date() {}

    Date(int mday, int mon) {
        time.tm_mday = mday;
        time.tm_year = 120;
        time.tm_mon = mon;
        time.tm_sec = 0;
        time.tm_yday = 0;
        time.tm_hour = 0;
        time.tm_isdst = 0;
        time.tm_wday = 0;
        time.tm_min = 0;
    }

    Date(tm time) {
    this->time = time;
}
    time_t getTimeT() {
        return mktime(&time);
    }

    bool operator <(Date& other) {
        return getTimeT() < other.getTimeT();
    }
    bool operator ==(Date& other) {
        return getTimeT() == other.getTimeT();
    }

    int operator -(Date &other) {
        return (int) difftime(getTimeT(),other.getTimeT()) / 86400;
}
    int getMDay()  {
        return time.tm_mday;
}

    static Date getNow()  {
        time_t now = std::time(nullptr);
        return  Date(*gmtime(&now));
}


};
#endif //LABA5_DATE_H
