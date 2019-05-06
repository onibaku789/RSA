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
    std::vector<RSA::longint> enrypt;
    std::cout << "Adja meg a prímszámokat: " << std::endl;
   std::cin >> a >> b;
    std::cout <<  std::endl;


   rsa->setPrimeP(a);
    rsa->setPrimeQ(b);
    rsa->setup();



    rsa->test();

    std::string ws;
    std::getline(std::cin,ws);


    std::string message = "";
    std::cout << "Adja meg az üzenetet: " << std::endl;

   std::getline(std::cin, message);
    std::cout << "A publikus kulcs: " << rsa->getE() << std::endl;
    enrypt = rsa->encode(message, rsa->getE());
    std::cout << "A kódolt üzenet: " ;
    for(auto i : enrypt){
        std::cout << i;}
    std::cout <<std::endl;
    std::cout << "A privát kulcs: " << rsa->getD() << std::endl;
    std::cout << "A dekódolt üzenet: " << rsa->decode(enrypt, rsa->getD()) << std::endl;



}

