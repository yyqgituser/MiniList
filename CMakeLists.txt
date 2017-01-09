cmake_minimum_required(VERSION 3.0.2)

project(MiniList)

enable_testing()

include_directories(.)
add_subdirectory(unittests)

install(FILES MiniList.h DESTINATION include) 
