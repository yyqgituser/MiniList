cmake_minimum_required(VERSION 2.6.4)

project(MiniList)

enable_testing()

include_directories(.)
add_subdirectory(unittests)

install(FILES MiniList.h DESTINATION include) 
