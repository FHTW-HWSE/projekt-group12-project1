// Created by Emad on 18/04/2023.
//

#ifndef PROJEKT_GROUP12_PROJECT1_HELLO_H
#define PROJEKT_GROUP12_PROJECT1_HELLO_H

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
}
#endif

#endif //PROJEKT_GROUP12_PROJECT1_HELLO_H
