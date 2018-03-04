cmake_minimum_required(VERSION 3.7)
project(Polimorfizm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/Shape.h src/Cone.cpp src/Cone.h src/Cylinder.cpp src/Cylinder.h src/Ball.cpp src/Ball.h src/Tetrahedron.cpp src/Tetrahedron.h src/Cuboid.cpp src/Cuboid.h src/Test.h src/Cube.cpp src/Cube.h)
add_executable(Polimorfizm ${SOURCE_FILES})