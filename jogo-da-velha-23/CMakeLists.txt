cmake_minimum_required(VERSION 3.27)
project(jogo_da_velha_23)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(jogo_da_velha_23
        funcoesJogoDaVelha.cpp
        funcoesJogoDaVelha.h
        main.cpp)
