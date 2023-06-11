//
// Created by Raikhan Kushekova on 30/05/2023.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "functions.h"

TEST_CASE("addStudentsToRoom adds student to the specified seat") {
    //create a sample classroom
    int rows = 2;
    int cols = 2;
    struct seat** classroom = generateClassroom(rows, cols, "Test Room");

    //call the function to add a student
    addStudentsToRoom(classroom, rows, cols);

    //check if the student is added to the specified seat
    REQUIRE(strcmp(classroom[0][0].ID, "123456789") == 0);

    //free memory
    free(classroom);

}

TEST_CASE("markStudentAsInfected marks the specified student as infected") {
    //create a sample classroom
    int rows = 2;
    int cols = 2;
    struct seat** classroom = generateClassroom(rows, cols, "Test Room");

    //add a student to the classroom
    strcpy(classroom[0][0].ID, "123456789");

    //call the function to mark the student as infected
    markStudentAsInfected(classroom, rows, cols);

    //check if the student is marked as infected
    REQUIRE(classroom[0][0].infected == 1);

    //free memory
    free(classroom);

}

TEST_CASE("getDirectNeighbors returns the direct neighbors of the specified seat") {
    //create a sample classroom
    int rows = 2;
    int cols = 2;
    struct seat** classroom = generateClassroom(rows, cols, "Test Room");

    //add a student to the classroom
    strcpy(classroom[0][0].ID, "123456789");

    //call the function to get the direct neighbors of the specified seat
    struct seat** neighbors = getDirectNeighbors(classroom, rows, cols, 0, 0);

    //check if the direct neighbors are returned
    REQUIRE(strcmp(neighbors[0][0].ID, "123456789") == 0);
    REQUIRE(strcmp(neighbors[0][1].ID, "0") == 0);
    REQUIRE(strcmp(neighbors[1][0].ID, "0") == 0);
    REQUIRE(strcmp(neighbors[1][1].ID, "0") == 0);

    //free memory
    free(classroom);
    free(neighbors);

}

TEST_CASE("getIndirectNeighbors returns the indirect neighbors of the specified seat") {
    //create a sample classroom
    int rows = 2;
    int cols = 2;
    struct seat** classroom = generateClassroom(rows, cols, "Test Room");

    //add a student to the classroom
    strcpy(classroom[0][0].ID, "123456789");

    //call the function to get the indirect neighbors of the specified seat
    struct seat** neighbors = getIndirectNeighbors(classroom, rows, cols, 0, 0);

    //check if the indirect neighbors are returned
    REQUIRE(strcmp(neighbors[0][0].ID, "0") == 0);
    REQUIRE(strcmp(neighbors[0][1].ID, "0") == 0);
    REQUIRE(strcmp(neighbors[1][0].ID, "0") == 0);
    REQUIRE(strcmp(neighbors[1][1].ID, "0") == 0);

    //free memory
    free(classroom);
    free(neighbors);

}

TEST_CASE("generateClassroom generates a classroom with the specified rows and columns") {
    //create a sample classroom
    int rows = 2;
    int cols = 2;
    struct seat** classroom = generateClassroom(rows, cols, "Test Room");

    //check if the classroom is generated with the specified rows and columns
    REQUIRE(strcmp(classroom[0][0].ID, "0") == 0);
    REQUIRE(strcmp(classroom[0][1].ID, "0") == 0);
    REQUIRE(strcmp(classroom[1][0].ID, "0") == 0);
    REQUIRE(strcmp(classroom[1][1].ID, "0") == 0);

    //free memory
    free(classroom);

}

