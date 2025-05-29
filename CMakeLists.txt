cmake_minimum_required(VERSION 3.28)
project(my-dear-logger)

file(GLOB CORE_SRC
    "src/*.c" 
    "src/*.h" 
    )

add_library(my-dear-logger STATIC ${CORE_SRC})