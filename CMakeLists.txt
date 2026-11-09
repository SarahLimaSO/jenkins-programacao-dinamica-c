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

enable_testing()

add_test(
    NAME teste_1
    COMMAND bash
        ${CMAKE_SOURCE_DIR}/tests/executa_testes.sh
        $<TARGET_FILE:prog-dinamica>
        ${CMAKE_SOURCE_DIR}/tests/inputs/teste1_in.txt
        ${CMAKE_SOURCE_DIR}/tests/outputs/teste1_out.txt
)
add_test(
    NAME teste_2
    COMMAND bash
        ${CMAKE_SOURCE_DIR}/tests/executa_testes.sh
        $<TARGET_FILE:prog-dinamica>
        ${CMAKE_SOURCE_DIR}/tests/inputs/teste2_in.txt
        ${CMAKE_SOURCE_DIR}/tests/outputs/teste2_out.txt
)