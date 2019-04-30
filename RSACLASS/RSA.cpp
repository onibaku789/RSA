//
// Created by attilav on 4/30/19.
//

#include "RSA.h"

RSA *RSA::instance = nullptr;

RSA *RSA::getInstance() {
    if (instance == nullptr) {
        instance = new RSA();
    }
    return instance;
}

using longint =  unsigned long long int;

longint RSA::gcd(RSA::longint divident, RSA::longint divisor) {
    longint temp;
    while (divisor > 0) {
        temp = divisor;
        divisor = divident % divisor;
        divident = temp;

    }
    return divident;
}

longint RSA::mod(RSA::longint a, RSA::longint b, RSA::longint m) {

}

void RSA::setRelativePrimeTofiN(longint relativePrimeTofiN) {
    RSA::primesTofiN = relativePrimeTofiN;
}

void RSA::setPrimeProd() {
    RSA::primeProd = this->primeP * this->primeQ;
}

void RSA::setFiN() {
    RSA::fiN = (this->primeP - 1) * (this->primeQ - 1);
}

bool RSA::isRelativePrime(longint from, longint to) {
    return gcd(from, to) == 1 ? true : false;
}

longint RSA::generateRelativePrime(longint from) {
    return 0;
}


