#include <iostream>

#include <random>
#include <iostream>
#include <algorithm>
#include <functional>
#include "random_device_wrapper.h"
#include "RSACLASS/RSA.h"



int main() {

    RSA *rsa = RSA::getInstance();

    RSA::longint a, b;
    std::cout << "Adja meg a prímszámokat: " << std::endl;
    std::cin >> a >> b;
    //std::cout <<  std::endl;


    rsa->setPrimeP(a);
    rsa->setPrimeQ(b);
    rsa->setup();

    //rsa->test();

    int message;
    std::cout << "Adja meg az üzenetet: " << std::endl;
    std::cin >> message;
    std::cout << "A publikus kulcs: " << rsa->getE() << std::endl;
    int enrypt = rsa->encode(message, rsa->getE());
    std::cout << "A kódolt üzenet: " << enrypt << std::endl;

    std::cout << "A privát kulcs: " << rsa->getD() << std::endl;
    std::cout << "A dekódolt üzenet: " << rsa->decode(enrypt, rsa->getD()) << std::endl;



}

