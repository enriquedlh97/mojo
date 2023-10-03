cmake_minimum_required(VERSION 3.12)
project(fibm_module)

set(CMAKE_CXX_STANDARD 14)

# Specify the path to pybind11Config.cmake
set(pybind11_DIR /usr/local/python/3.10.8/lib/python3.10/site-packages/pybind11/share/cmake/pybind11/)

find_package(pybind11 REQUIRED)

pybind11_add_module(fibm_module fibm.cpp)
