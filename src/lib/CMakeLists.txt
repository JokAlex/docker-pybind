cmake_minimum_required(VERSION 3.5)


project(LibraryForPyBind LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCES pylib.cpp printmap.cpp doublelistoperator.cpp)


find_package(pybind11 REQUIRED)
pybind11_add_module(bindlib ${SOURCES})
set_target_properties(bindlib PROPERTIES SUFFIX .so)
target_include_directories(bindlib PRIVATE include)
