cmake_minimum_required(VERSION 3.21)
project(Jeopardy-in-CPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(Jeopardy-in-CPP main.cpp Question.cpp Board.cpp Player.cpp SelectionSort.cpp)
#add_executable(Jeopardy-in-CPP testing.cpp Question.cpp Board.cpp Player.cpp SelectionSort.cpp)
