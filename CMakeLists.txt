cmake_minimum_required(VERSION 3.14)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project1 main.cpp Utils/utils.h Classes/Funcionario.h Classes/Funcionario.cpp Classes/Aeroporto.h Classes/Aeroporto.cpp Menu/Menu.cpp Menu/Menu.h Utils/utils.cpp Utils/sorts.h Utils/sorts.cpp)