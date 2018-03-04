cmake_minimum_required(VERSION 3.7)
project(Zadanie_1_2_3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/Order.cpp src/Order.h src/OrdersCollection.cpp src/OrdersCollection.h)
add_executable(Zadanie_1_2_3 ${SOURCE_FILES})