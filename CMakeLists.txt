cmake_minimum_required(VERSION 3.20)
project(LAB_String)

set(CMAKE_CXX_STANDARD 17)

set(Sources lib/String.cpp lib/String.h lib/BinString.cpp lib/BinString.h lib/NoteString.cpp lib/NoteString.h lib/Stack.cpp lib/Stack.h)

add_executable(LAB_String main.cpp ${Sources})

add_subdirectory(googletest)
