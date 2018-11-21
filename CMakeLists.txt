cmake_minimum_required(VERSION 3.9.2)
project(Neuron)

set(CMAKE_CXX_STANDARD 11)

add_executable(neuron main.cpp app/Model.cpp app/Model.h app/Dataset.h app/Support.h app/Support.cpp)
