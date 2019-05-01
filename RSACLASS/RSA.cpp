//
// Created by attilav on 4/30/19.
//

#include "RSA.h"

#include "../random_device_wrapper.h"


auto rd = std::random_device{};
auto seedseq = random_device_wrapper{rd};
auto mt = std::mt19937{seedseq};

std::uniform_int_distribution<int> distr(2, 10000);

RSA *RSA::instance = nullptr;


RSA *RSA::getInstance() {
    if (instance == nullptr) {
        instance = new RSA();
    }
    return instance;
}

using longint =   long long int;


void RSA::encode(int m, longint e) {


    longint enrypted = fastPower(m, e);
    std::cout << enrypted << std::endl;

}

void RSA::decode(int m, longint d) {

    longint enrypted = fastPower(m, d);

    std::cout << enrypted << std::endl;

}


longint RSA::gcd(RSA::longint divident, RSA::longint divisor) {
    longint temp;
    while (divisor > 0) {
        temp = divisor;
        divisor = divident % divisor;
        divident = temp;

    }
    return divident;
}


bool RSA::isRelativePrime(longint from, longint to) {
    return gcd(from, to) == 1;
}


longint RSA::generateRandomNums() {

    return mt();
}


longint RSA::generateE() {

    longint random = 2;
    std::vector<longint> possiblePrivateteKey;

    while (random < 10000) {

        if (isRelativePrime(fiN, random) && (isRelativePrime(primeProd, random)) && random < fiN)
            possiblePrivateteKey.emplace_back(random);
        random++;


    }
    std::random_shuffle(possiblePrivateteKey.begin(), possiblePrivateteKey.end());
    return possiblePrivateteKey[0];
}

longint RSA::generateSmallNums() {

    return distr(mt);
}


longint RSA::generateD() {
    double tempRes;
    int k = 0;


    while (true) {

        tempRes = (double) (1 + (k * fiN)) / (double) e;


        if (std::floor(tempRes) == tempRes)
            return tempRes;
        else
            k++;
    }

}

bool RSA::isPrime(longint n) {

    for (longint i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;

        }
    }
    return true;
}

void RSA::generatePrimes() {
    longint p = 0, q = 0, random;

    while (p == 0 || q == 0) {

        if (p == 0) {
            random = generateSmallNums();
            if (isPrime(random))
                p = random;
        } else if (q == 0) {
            random = generateSmallNums();
            if (isPrime(random))
                q = random;
        } else { break; }


    }
    this->setPrimeP(p);
    this->setPrimeQ(q);


}


void RSA::setD(longint d) {
    RSA::d = d;
}

void RSA::setE(longint e) {
    RSA::e = e;
}

void RSA::setPrimeP(longint primeP) {
    RSA::primeP = primeP;
}

void RSA::setPrimeQ(longint primeQ) {
    RSA::primeQ = primeQ;
}
void RSA::setPrimeProd() {
    RSA::primeProd = this->primeP * this->primeQ;
}

void RSA::setFiN() {
    RSA::fiN = (this->primeP - 1) * (this->primeQ - 1);
}

void RSA::test() {


    std::cout <<
              "D: " << d <<
              " E: " << e <<
              " fiN: " << fiN <<
              " GCD:" << gcd(d * e, fiN) <<
              " P: " << primeP <<
              " Q: " << primeQ <<
              " prod: " << primeProd << std::endl;
}

void RSA::init() {
    generatePrimes();
    setFiN();
    setPrimeProd();
    setE(generateE());
    setD(generateD());

}

longint RSA::fastPower(longint base, longint power) {

    longint result = 1;
    while (power > 0) {
        if (power & 1)
            result = (result * base) % primeProd;

        base = (base * base) % primeProd;
        power = power >>= 1;
    }
    return result;
}








