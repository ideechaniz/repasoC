cmake_minimum_required(VERSION 2.8)

project(EjemploBaseDatosSQLite)
add_executable(${PROJECT_NAME} "main.c" "sqlite3.c" "sqlite3.h")

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)

target_link_libraries(EjemploBaseDatosSQLite pthread ${CMAKE_DL_LIBS})

#set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-pthread" )

# Compila rapido con gcc main.c sqlite3.h sqlite3.c -Lpthread -Ldl -lpthread -ldl


