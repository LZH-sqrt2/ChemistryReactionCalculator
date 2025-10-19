cmake_minimum_required(VERSION 3.31)
project(ChemistryReactionCalculator VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP REQUIRED jsoncpp)
find_package(Python REQUIRED)

include_directories(main/core)

add_executable(ChemistryReactionCalculator
        main/core/DataType.h
        main/core/ChemistryCore.cpp
        main/core/ChemistryCore.h)

target_link_libraries(ChemistryReactionCalculator PUBLIC ${JSONCPP_LIBRARIES})
target_include_directories(ChemistryReactionCalculator PUBLIC ${JSONCPP_INCLUDE_DIRS})
