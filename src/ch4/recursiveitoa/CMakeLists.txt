cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c89 -g")
set(CMAKE_C_COMPILER "/usr/bin/gcc")

project(recursiveitoa VERSION 0.0.0)

set(HEADERS
    itoa.h
)

set(SOURCES
    itoa.c
    testitoa.c
)

add_executable(itoa ${SOURCES})
