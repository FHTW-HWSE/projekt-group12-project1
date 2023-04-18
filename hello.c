#include <stdio.h>
#include <stdlib.h>

// Definition of the classroom data structure
struct Classroom {
    int rows;
    int cols;
    int **seats;
};

// Function to generate the classroom with the specified rows and columns
struct Classroom *generateClassroom(int rows, int cols) {
    struct Classroom *classroom = malloc(sizeof(struct Classroom));
    classroom->rows = rows;
    classroom->cols = cols;
    classroom->seats = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        classroom->seats[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            classroom->seats[i][j] = 0;
        }
    }
    return classroom;
}

// Function to assign a seat to a student with the specified ID
void assignSeat(struct Classroom *classroom, int id, int row, int col) {
    if (classroom->seats[row][col] == 0) {
        classroom->seats[row][col] = id;
        printf("Student with ID %d assigned to seat [%d, %d]\n", id, row, col);
    } else {
        printf("Seat [%d, %d] is already occupied\n", row, col);
    }
}

// Function to get the direct neighbors of a student
void getDirectNeighbors(struct Classroom *classroom, int id) {
    int row = -1;
    int col = -1;
    for (int i = 0; i < classroom->rows; i++) {
        for (int j = 0; j < classroom->cols; j++) {
            if (classroom->seats[i][j] == id) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1 && col != -1) {
            break;
        }
    }
    if (row == -1 || col == -1) {
        printf("Student with ID %d not found\n", id);
        return;
    }
    printf("Direct neighbors of student with ID %d are:\n", id);
    if (row > 0) {
        if (col > 0 && classroom->seats[row-1][col-1] != 0) {
            printf("[%d, %d]\n", row-1, col-1);
        }
        if (classroom->seats[row-1][col] != 0) {
            printf("[%d, %d]\n", row-1, col);
        }
        if (col < classroom->cols-1 && classroom->seats[row-1][col+1] != 0) {
            printf("[%d, %d]\n", row-1, col+1);
        }
    }
    if (col > 0 && classroom->seats[row][col-1] != 0) {
        printf("[%d, %d]\n", row, col-1);
    }
    if (col < classroom->cols-1 && classroom->seats[row][col+1] != 0) {
        printf("[%d, %d]\n", row, col+1);
    }
    if (row < classroom->rows-1) {
        if (col > 0 && classroom->seats[row+1][col-1] != 0) {
            printf("[%d, %d]\n", row+1, col-1);
        }
        if (classroom->seats[row+1][col] != 0) {
            printf("[%d, %d]\n", row+1, col);
        }
        if (col < classroom->cols-1 && classroom->seats[row+1][col+1] != 0) {
            printf("[%d, %d]\n", row+1, col+1);
        }
    }
}
