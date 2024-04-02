cmake_minimum_required(VERSION 3.27)
project(TaskApp)

set(CMAKE_CXX_STANDARD 17)

add_executable(TaskApp main.cpp
        person.cpp
        h.cpp)
