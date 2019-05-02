//
// Created by attilav on 4/30/19.
//

#ifndef RSA_RSA_H
#define RSA_RSA_H


#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <functional>

class RSA {
public:
    static RSA *getInstance();

    using longint =  long long int;

    void test();

    void init();

    longint encode(int m, longint e);

    longint decode(int m, longint d);

    const std::map<char, int> &getLetters() const;

    longint getPrimeP() const;

    longint getPrimeQ() const;

    longint getD() const;

    longint getE() const;

    longint getPrimeProd() const;

    longint getFiN() const;

    void setPrimeP(longint primeP);

    void setPrimeQ(longint primeQ);

    p();





private:


    static RSA *instance;

    RSA() = default;

    longint primeP, primeQ, d, e, primeProd,
            fiN;

    std::map<char, int> letters;

    bool isRelativePrime(longint from, longint to);

    longint generateE();

    void generatePrimes();

    longint gcd(longint counter, longint divider);

    longint generateRandomNums();

    longint generateD();

    longint generateSmallNums();

    longint fastPower(longint base, longint power);

    std::vector<int> breakString(std::string msg);

    std::string buildString(std::vector<int> msg);

    static bool isPrime(longint);


    void printPossibleE();

    void setD();

    void setE(longint e);

    void setPrimeProd();

    void setFiN();

    void setD(longint d);
};


#endif //RSA_RSA_H
