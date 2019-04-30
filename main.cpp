#include <iostream>

#include <random>
#include <iostream>
#include <algorithm>
#include <functional>
#include "random_device_wrapper.h"

using longint = unsigned long long int;
auto rd = std::random_device{};
auto seedseq = random_device_wrapper{rd};
auto mt = std::mt19937_64{seedseq};

longint generateRandomNum() {
    return mt();
}

int main() {

    std::cout << generateRandomNum();

}

