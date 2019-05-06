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

using longint =    long long int;


std::vector<longint>  RSA::encode(std::string m , longint e) {
    std::vector<longint> enrypted ;

    for(char letter : m){
            char temp = letter;
            longint temp2 = (longint)temp;
         enrypted.emplace_back( fastPower(temp2, e));

    }

    return enrypted;

}

std::string RSA::decode(std::vector<longint> m, longint d) {
std::string decrypted;

  for(longint i :m) {
      decrypted += (char)decrypt(i,d);
  }
    return decrypted;

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





RSA::longint RSA::generateE() {

    longint random = 2;
    std::vector<longint> possiblePrivateteKey;

    while (random < 1000) {

        if  (isRelativePrime(primeProd, random) && random < fiN && isRelativePrime(random,fiN))
            possiblePrivateteKey.emplace_back(random);
        random++;


    }
    //  std::random_shuffle(possiblePrivateteKey.begin(), possiblePrivateteKey.end());
    return possiblePrivateteKey[0];
}

longint RSA::generateSmallNums() {

    return distr(mt);
}


RSA::longint RSA::generateD() {
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

    if (n <= 1)
    return false;
    if (n <= 3)
    return true;

    if (n%2 == 0 || n%3 == 0)
    return false;

    int  i = 5;
    while(i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        i += 6;
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
    setXY();
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

RSA::longint RSA::getPrimeP() const {
    return primeP;
}

RSA::longint RSA::getPrimeQ() const {
    return primeQ;
}

RSA::longint RSA::getD() const {
    return d;
}

RSA::longint RSA::getE() const {
    return e;
}

RSA::longint RSA::getPrimeProd() const {
    return primeProd;
}

RSA::longint RSA::getFiN() const {
    return fiN;
}



void RSA::setup() {

    setFiN();
    setPrimeProd();
    setXY();
    setE(generateE());
    setD(generateD());

}

std::vector<int> breakString(std::string sentence) {
    std::vector<int> msg;


    return msg;
};





int RSA::mod(int x, int y){
    if(x < y){
        return x;
    }
    return x%y;
}

longint RSA::generateRandomNums() {

    return mt();
}

std::tuple<int, int, int> RSA::extendedGCD(longint a, longint b) {
    if (b == 0)
        return std::make_tuple(a, 1, 0);

    longint gcd, x, y;

  std::tie(gcd, x, y) = extendedGCD(b, a%b);

    return std::make_tuple(gcd, y,(x - (a/b) * y));
}

longint RSA::fastPowerExtended(longint base, longint power,longint m) {

    longint result = 1;
    while (power > 0) {
        if (power & 1)
            result = (result * base) % m;

        base = (base * base) % m;
        power = power >>= 1;
    }
    return result;
}

longint RSA::decrypt(longint c, longint d) {

    return fastPowerExtended(c,d,primeProd);;
}

void RSA::setXY() {
    longint a,b;

        a=primeP;
        b =primeQ;

    std::tuple<int, int, int> t =extendedGCD(a,b);

    this->setX(std::get<1>(t));
    this->setY(std::get<2>(t));
}

void RSA::setX(longint x) {
    X = x;
}

void RSA::setY(longint y) {
    Y = y;
}



