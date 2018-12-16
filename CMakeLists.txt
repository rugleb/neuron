cmake_minimum_required(VERSION 3.9.0)
project(Neuron)

set(CMAKE_CXX_STANDARD 11)

add_executable(neuron main.cpp src/Model.cpp src/Model.h src/vector.h src/vector.cpp)
