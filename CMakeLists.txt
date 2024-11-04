cmake_minimum_required(VERSION 3.5)
cmake_policy(VERSION 3.5)

project(battleship)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -O2")

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_executable(battleship src/main.cpp)
