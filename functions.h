//
// Created by matze on 4/25/2023.
//

#ifndef PROJEKT_GROUP12_PROJECT1_FUNCTIONS_H
#define PROJEKT_GROUP12_PROJECT1_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

struct Classroom {
    int rows;
    int cols;
    int **seats;
};

struct Classroom *generateClassroom(int rows, int cols);
void assignSeat(struct Classroom *classroom, int studentId, int row, int col);
void getDirectNeighbors(struct Classroom *classroom, int studentId);
void freeClassroom(struct Classroom *classroom);
void getNeighbors(struct Classroom *classroom, int id);

#endif //PROJEKT_GROUP12_PROJECT1_FUNCTIONS_H
