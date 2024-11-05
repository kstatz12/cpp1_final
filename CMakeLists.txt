cmake_minimum_required(VERSION 3.5)
cmake_policy(VERSION 3.5)

project(battleship)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

if(MSVC)
    # Compiler flags for Visual Studio
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX /O2")
else()
    # Compiler flags for other compilers (e.g., GCC, Clang)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -O2")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(HEADER_FILES src/types.h src/board.h src/guesser.h src/solver.h)

set(SRC_FILES src/board.cpp src/guesser.cpp src/solver.cpp)

add_executable(battleship src/main.cpp ${HEADER_FILES} ${SRC_FILES})
