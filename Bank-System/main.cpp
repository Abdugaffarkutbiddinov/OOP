#include <iostream>
#include <chrono>
#include <sstream>
#include <ctime>
#include "Date.h"
#include "Client.h"
#include "ClientBuilder.h"
#include "Bank.h"

int main() {
//    auto now = std::chrono::system_clock::now();
//    time_t t_c = std::chrono::system_clock::to_time_t();
    tm time;

    try {

/*
        time.tm_mday = 1;
        time.tm_year = 120;
        time.tm_mon = 11;
        time.tm_sec = 0;
        time.tm_yday = 0;
        time.tm_hour = 0;
        time.tm_isdst = 0;
        time.tm_wday = 0;
        time.tm_min = 0;
        time_t time1 = mktime(&time);
        std::cout << ctime(&time1);*/
        ClientBuilder clientBuilder;
        clientBuilder.setName("Abdugaffar").setSurname("Kutbiddinov").setPassportID("AB4717171").setAddress("Zarafshan");
        Client newClient = clientBuilder.build();
        Bank bank(1, 0.04, 0.04, 40000, 40000);
        bank.createDebit(newClient);
        bank.refill(1, 30000);
        bank.withdrawal(1, 20000);
        /*newClient.setAddress("123");
        newClient.setPassportID("sdfgsdf");
        bank.dataUpdate(newClient);
        bank.withdrawal(1,10000);*/
        ClientBuilder clientBuilder2;
        clientBuilder2.setName("Bratan").setSurname("Bratanov");
        Client newClient2 = clientBuilder2.build();
        bank.createDebit(newClient2);
        bank.refill(2,50000);
        bank.withdrawal(2,10000);
        bank.transfer(2,1,10000);

        Date depositDate(10,11);
        bank.createDeposit(newClient,50000,depositDate);
        bank.refill(3,50000);
        bank.withdrawal(3,50000);
        bank.dailyInterestRate();
    }
    catch(const std::runtime_error& error) {
        std::cout << error.what();
    }
}