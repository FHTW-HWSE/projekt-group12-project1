//
// Created by matze on 4/25/2023.
//

#include "functions.h"


// Function to generate the classroom with the specified rows and columns
struct seat **generateClassroom(int rows, int cols) {
    // Allocate memory for the 2D array of seats
    struct seat **classroom = (struct seat**)calloc(rows, sizeof(struct seat*));
    for (int i = 0; i < rows; i++) {
        classroom[i] = (struct seat*)calloc(cols, sizeof(struct seat));

    }

    return classroom;
}


