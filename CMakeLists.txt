cmake_minimum_required(VERSION 3.10)
project(Neuron)

set(CMAKE_CXX_STANDARD 11)

add_executable(neuron main.cpp app/Model.cpp app/Model.h app/Dataset.h)
