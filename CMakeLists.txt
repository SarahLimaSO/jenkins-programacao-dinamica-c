cmake_minimum_required(VERSION 3.16)

project(jenkins-programacao-dinamica-c C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(prog-dinamica
    src/str_format.c
    src/maior_subsequencia_comum.c
    src/main.c
)

target_include_directories(prog-dinamica PRIVATE include)