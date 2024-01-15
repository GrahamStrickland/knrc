cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c89 -g")
set(CMAKE_C_COMPILER "/usr/bin/gcc")

project(calc VERSION 0.0.0)

set(SOURCES
    getop.c
    getch.c
    main.c
    stack.c
)

add_executable(calc ${SOURCES})

