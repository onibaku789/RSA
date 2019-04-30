//
// Created by attilav on 4/30/19.
//

#ifndef RSA_RANDOM_DEVICE_WRAPPER_H
#define RSA_RANDOM_DEVICE_WRAPPER_H

#include <random>
#include <iostream>
#include <algorithm>
#include <functional>

class random_device_wrapper {
    std::random_device *m_dev;
public:
    using result_type = std::random_device::result_type;

    explicit random_device_wrapper(std::random_device &dev) : m_dev(&dev) {}

    template<typename RandomAccessIterator>
    void generate(RandomAccessIterator first, RandomAccessIterator last) {
        std::generate(first, last, std::ref(*m_dev));
    }
};


#endif //RSA_RANDOM_DEVICE_WRAPPER_H
