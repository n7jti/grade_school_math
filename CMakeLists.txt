cmake_minimum_required (VERSION 3.10)

project (grade_school_math)

add_executable(grade_school_math 
    src/main.cc 
    src/mul.cc
    inc/gsmath.h
)
target_include_directories(grade_school_math PRIVATE "${PROJECT_SOURCE_DIR}/inc")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
