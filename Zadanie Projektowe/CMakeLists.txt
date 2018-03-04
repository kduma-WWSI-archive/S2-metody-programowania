cmake_minimum_required(VERSION 3.7)
project(Zadanie_projektowe)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/Training.cpp src/Training.h src/Coach.cpp src/Coach.h src/Allocation.cpp src/Allocation.h src/TrainingCollection.cpp src/TrainingCollection.h src/CoachCollection.cpp src/CoachCollection.h src/AllocationCollection.cpp src/AllocationCollection.h src/Store.cpp src/Store.h src/UI.cpp src/UI.h src/logic.cpp src/logic.h)
add_executable(Zadanie_projektowe ${SOURCE_FILES})