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

    void doRsa();

private:


    static RSA *instance;

    RSA() = default;

    longint primeP, primeQ, primesTofiN, primeProd,
            fiN;

    void setRelativePrimeTofiN(longint primeTofiN);

    void setPrimeProd();

    void setFiN();


    bool isRelativePrime(longint from, longint to);

    longint generateRelativePrime(longint from);

    void generatePrimes();

    longint gcd(longint counter, longint divider);

    longint mod(longint a, longint b, longint m);


};


#endif //RSA_RSA_H
