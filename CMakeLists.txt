cmake_minimum_required(VERSION 3.23)
project(projekt_group12_project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(projekt_group12_project1
        catch2-testing.cpp
        hello.c hello.h)
Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)
target_link_libraries(projekt_group12_project1 Catch2::Catch2)
