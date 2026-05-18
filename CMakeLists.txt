cmake_minimum_required(VERSION 3.16)

project(CppPython LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PYBIND11_FINDPYTHON ON)
set(Python3_ROOT_DIR "C:/Program Files/Python312")
set(Python3_EXECUTABLE "C:/Program Files/Python312/python.exe")
find_package(Python3 3.12 REQUIRED COMPONENTS Interpreter Development)

include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG v2.13.6
)
FetchContent_MakeAvailable(pybind11)

pybind11_add_module(FopMath
    main.cpp
    functies.cpp
)
