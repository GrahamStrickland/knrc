cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c89 -g")
set(CMAKE_C_COMPILER "/usr/bin/gcc")

project(qsort VERSION 0.0.0)

set(HEADERS
    qsort.h
)

set(SOURCES
    qsort.c
    testqsort.c
)

add_executable(qsort ${SOURCES})

