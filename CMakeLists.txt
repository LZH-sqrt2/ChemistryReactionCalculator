cmake_minimum_required(VERSION 3.31)
project(ChemistryReactionCalculator VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP REQUIRED jsoncpp)
find_package(Python REQUIRED)
find_package(nanobind CONFIG REQUIRED)

include_directories(main/core)

add_library(ChemistryReactionCalculator SHARED
        main/core/DataType.h
        main/core/ChemistryCore.cpp
        main/core/ChemistryCore.h
        main/core/EquationSolver/Equation.h
        main/core/EquationSolver/ISolver.h
        main/core/EquationSolver/EquationRegistry.cpp
        main/core/EquationSolver/EquationRegistry.h
        main/core/EquationSolver/Equations.h
        main/core/Registry/IRegistry.h
        main/core/Registry/Registry.h
        main/Core/Registry/Registry.cpp
        main/Core/Registry/RegistryBuilder.h
)

set_target_properties(ChemistryReactionCalculator PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        LIBRARY_OUTPUT_DIRECTORY main/Lib
        ARCHIVE_OUTPUT_DIRECTORY main/Lib)

target_link_libraries(ChemistryReactionCalculator PUBLIC ${JSONCPP_LIBRARIES})
target_include_directories(ChemistryReactionCalculator PUBLIC ${JSONCPP_INCLUDE_DIRS})
