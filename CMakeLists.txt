cmake_minimum_required(VERSION 3.23)
project(UC_IIC2552 CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE ALL_CPPS CONFIGURE_DEPENDS
     "${CMAKE_SOURCE_DIR}/problems/*.cpp"
     "${CMAKE_SOURCE_DIR}/contests/*.cpp")

foreach(FILE ${ALL_CPPS})
    file(RELATIVE_PATH REL ${CMAKE_SOURCE_DIR} ${FILE})
    string(REGEX REPLACE "\\.cpp$" "" REL ${REL})
    string(REPLACE "/" "_" EXEC_NAME ${REL})
    add_executable(${EXEC_NAME} ${FILE})
endforeach()
add_executable(D_La_biblioteca_fragmentada "problems/0924/D_La_biblioteca_fragmentada.cpp")