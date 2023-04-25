cmake_minimum_required(VERSION 3.23)
project(projekt_group12_project1 C CXX)  # Add both C and CXX here to specify the languages

set(CMAKE_C_STANDARD 99)  # Set the C standard
set(CMAKE_CXX_STANDARD 14)  # Set the C++ standard

add_executable(projekt_group12_project1

        hello.c hello.h)
Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)

#FetchContent_MakeAvailable(Catch2)
#target_link_libraries(projekt_group12_project1 Catch2::Catch2)
