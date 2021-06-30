cmake_minimum_required(VERSION 3.17)
project(elaborato)

set(CMAKE_CXX_STANDARD 14)

add_executable(elaborato main.cpp chat.cpp chat.h message.cpp message.h user.cpp user.h)