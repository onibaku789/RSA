cmake_minimum_required(VERSION 3.14)
project(rsa)

set(CMAKE_CXX_STANDARD 17)

add_executable(rsa main.cpp RSACLASS/RSA.cpp RSACLASS/RSA.h random_device_wrapper.cpp random_device_wrapper.h)