cmake_minimum_required(VERSION 3.9.2)
project(Neuron)

set(CMAKE_CXX_STANDARD 11)

add_executable(neuron main.cpp src/Model.cpp src/Model.h src/Support.h src/Support.cpp)
