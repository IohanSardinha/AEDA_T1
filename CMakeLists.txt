cmake_minimum_required(VERSION 3.14)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project1 main.cpp Utils/utils.h Classes/Funcionario.h Classes/Funcionario.cpp Classes/Aeroporto.h Classes/Aeroporto.cpp Menu/Menu.cpp Menu/Menu.h Utils/utils.cpp Utils/sorts.h Utils/sorts.cpp Menu/MainMenu.cpp Menu/MainMenu.h Menu/ListarAeroportoMenu.cpp Menu/ListarAeroportoMenu.h Menu/AcessarAeroportoMenu.cpp Menu/AcessarAeroportoMenu.h Menu/FuncionariosMenu.cpp Menu/FuncionariosMenu.h Menu/AviaoMenu.cpp Menu/AviaoMenu.h Menu/VooMenu.cpp Menu/VooMenu.h)