cmake_minimum_required(VERSION 3.26)
project(Long_double_number)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(SOURCE_EXE cpu.cpp commands.cpp cpu.h memory.cpp memory.h commands.h stack.hpp Program.cpp)

add_executable(Source ${SOURCE_EXE})