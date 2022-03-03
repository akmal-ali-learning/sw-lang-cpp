cmake_minimum_required(VERSION 3.0.0)
project(akmal-gl VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB SRC_FILES 
    src/*.cpp src/*.h 
    src/*/*.cpp src/*/*.h 
    src/*/*/*.cpp src/*/*/*.h 
    src/*/*/*.cpp src/*/*/*.h )

add_executable(akmal-cpp ${SRC_FILES}) 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
