cmake_minimum_required(VERSION 3.31)
project(ChemistryReactionCalculator VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP REQUIRED jsoncpp)
find_package(Python REQUIRED)
find_package(nanobind CONFIG REQUIRED)

include_directories(main/Core)

add_library(ChemistryReactionCalculator SHARED
        main/Core/DataType.h
        main/Core/ChemistryCore.cpp
        main/Core/ChemistryCore.h
        main/Core/EquationSolver/Equation.h
        main/Core/EquationSolver/ISolver.h
        main/Core/EquationSolver/EquationRegistry.cpp
        main/Core/EquationSolver/EquationRegistry.h
        main/Core/EquationSolver/Equations.h
        main/Core/Registry/IRegistry.h
        main/Core/Registry/Registry.h
        main/Core/Registry/Registry.cpp
        main/Core/Registry/RegistryBuilder.h
)

set_target_properties(ChemistryReactionCalculator PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        LIBRARY_OUTPUT_DIRECTORY main/Lib
        ARCHIVE_OUTPUT_DIRECTORY main/Lib)

target_link_libraries(ChemistryReactionCalculator PUBLIC ${JSONCPP_LIBRARIES})
target_include_directories(ChemistryReactionCalculator PUBLIC ${JSONCPP_INCLUDE_DIRS})
