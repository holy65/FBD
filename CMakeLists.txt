cmake_minimum_required(VERSION 3.27)
project(FBD C)

set(CMAKE_C_STANDARD 23)

add_executable(FBD main.c
        include/joke.h
        include/cute_airlib.h)