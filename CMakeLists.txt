cmake_minimum_required(VERSION 3.14)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project1 main.cpp utils.h Funcionario.h Funcionario.cpp Aeroporto.h Aeroporto.cpp Menu.cpp Menu.h utils.cpp sorts.h sorts.cpp)