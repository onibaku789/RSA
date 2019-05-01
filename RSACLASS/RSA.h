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

    using longint = unsigned long long int;

    void test();

    void init();

    void encode(int m, longint e);

    void decode(int m, longint d);

//private:


    static RSA *instance;

    RSA() = default;

    longint primeP, primeQ, d, e, primeProd,
            fiN;



    bool isRelativePrime(longint from, longint to);

    longint generateE();

    void generatePrimes();

    longint gcd(longint counter, longint divider);

    longint generateRandomNums();

    longint generateD();

    longint generateSmallNums();

    longint fastPower(longint base, longint power);

    static bool isPrime(longint);

    void setPrimeP(longint primeP);

    void printPossibleE();

    void setPrimeQ(longint primeQ);

    void setD();

    void setE(longint e);

    void setPrimeProd();

    void setFiN();
};


#endif //RSA_RSA_H
