//
// Created by Tae Takemi on 18.04.2023.
//
#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "hello.h"

TEST_CASE("test assignSeat function") {
struct Classroom *classroom = generateClassroom(3, 3);
assignSeat(classroom, 1, 1, 1);
REQUIRE(classroom->seats[1][1] == 1);

assignSeat(classroom, 2, 1, 1); // this should fail because the seat is already occupied
REQUIRE(classroom->seats[1][1] == 1);
}

TEST_CASE("test getDirectNeighbors function") {
struct Classroom *classroom = generateClassroom(3, 3);
assignSeat(classroom, 1, 0, 0);
assignSeat(classroom, 2, 0, 1);
assignSeat(classroom, 3, 0, 2);
assignSeat(classroom, 4, 1, 0);
assignSeat(classroom, 5, 1, 1);
assignSeat(classroom, 6, 1, 2);
assignSeat(classroom, 7, 2, 0);
assignSeat(classroom, 8, 2, 1);
assignSeat(classroom, 9, 2, 2);

SECTION("getDirectNeighbors of student with ID 1") {
std::ostringstream output;
auto old_cout_buf = std::cout.rdbuf(output.rdbuf());

getDirectNeighbors(classroom, 1);

std::cout.rdbuf(old_cout_buf); // restore cout buffer
REQUIRE(output.str() == "[0, 1]\n[1, 0]\n[1, 1]\n");
}

SECTION("getDirectNeighbors of student with ID 5") {
std::ostringstream output;
auto old_cout_buf = std::cout.rdbuf(output.rdbuf());

getDirectNeighbors(classroom, 5);

std::cout.rdbuf(old_cout_buf); // restore cout buffer
REQUIRE(output.str() == "[0, 0]\n[0, 1]\n[0, 2]\n[1, 0]\n[1, 2]\n[2, 0]\n[2, 1]\n[2, 2]\n");
}

SECTION("getDirectNeighbors of non-existing student") {
std::ostringstream output;
auto old_cout_buf = std::cout.rdbuf(output.rdbuf());

getDirectNeighbors(classroom, 10);

std::cout.rdbuf(old_cout_buf); // restore cout buffer
REQUIRE(output.str() == "Student with ID 10 not found\n");
}
}

