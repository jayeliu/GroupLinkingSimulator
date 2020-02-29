cmake_minimum_required(VERSION 3.15)
project(GroupLinkingSimulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(GroupLinkingSimulator main.cpp GroupLinking.cpp GroupLinking.h)