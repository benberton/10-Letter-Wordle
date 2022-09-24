cmake_minimum_required(VERSION 3.20)
project(Wordle)

set(CMAKE_CXX_STANDARD 14)

add_executable(Wordle main.cpp Wordle.cpp Game.cpp)
