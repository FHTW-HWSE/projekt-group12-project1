//
// Created by Emad on 18/04/2023.
//

#ifndef PROJEKT_GROUP12_PROJECT1_HELLO_H
#define PROJEKT_GROUP12_PROJECT1_HELLO_H
struct Classroom *generateClassroom(int rows, int cols);
void assignSeat(struct Classroom *classroom, int studentId, int row, int col);
void getDirectNeighbors(struct Classroom *classroom, int studentId);

#endif //PROJEKT_GROUP12_PROJECT1_HELLO_H
