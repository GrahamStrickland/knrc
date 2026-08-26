cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c89 -g")

project(recursereverse VERSION 0.0.0)

set(HEADERS
    reverse.h
)

set(SOURCES
    reverse.c
    testreverse.c
)

add_executable(reverse ${SOURCES})
