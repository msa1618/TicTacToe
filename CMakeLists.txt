cmake_minimum_required(VERSION 3.29)
project(tictactoe VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

add_executable(
  tictactoe main.cpp
  tictactoe.hpp
  colours.hpp
)
