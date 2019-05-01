#include <iostream>

#include <random>
#include <iostream>
#include <algorithm>
#include <functional>
#include "random_device_wrapper.h"
#include "RSACLASS/RSA.h"

using longint = unsigned long long int;

int main() {

    RSA *rsa = RSA::getInstance();

    rsa->init();


    rsa->test();

    int message, e, d;
    //std::cin >> message >> e;

    //rsa->encode(message,e);


    //  std::cin >> message >> d ;

    // rsa->decode(message,d);




}

