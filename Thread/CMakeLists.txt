cmake_minimum_required(VERSION 2.8)

project(Thread)
add_executable(${PROJECT_NAME} "main.c")


set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-pthread")


