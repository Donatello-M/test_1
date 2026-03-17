cmake_minimum_required(VERSION 3.10)
project(KrivoshapkinCW C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(task1 task1/task1.c)
add_executable(task2 task2/task2.c)
add_executable(task3 task3/task3.c)

target_compile_options(task1 PRIVATE -Wall)
target_compile_options(task2 PRIVATE -Wall)
target_compile_options(task3 PRIVATE -Wall)
