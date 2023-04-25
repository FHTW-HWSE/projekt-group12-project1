#include <stdio.h>
#include <stdlib.h>
#include "hello.h"

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
void freeClassroom(struct Classroom *classroom) {
    for (int i = 0; i < classroom->rows; i++) {
        free(classroom->seats[i]);
    }
    free(classroom->seats);
    free(classroom);
}
// Function to get the direct and indirect neighbors of a student
void getNeighbors(struct Classroom *classroom, int id) {
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
    printf("Direct and indirect neighbors of student with ID %d are:\n", id);
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue; // skip the student themselves
            }
            int neighbor_row = row + i;
            int neighbor_col = col + j;
            if (neighbor_row < 0 || neighbor_row >= classroom->rows ||
                neighbor_col < 0 || neighbor_col >= classroom->cols) {
                continue; // skip out of bounds seats
            }
            if (classroom->seats[neighbor_row][neighbor_col] != 0) {
                printf("[%d, %d]\n", neighbor_row, neighbor_col);
            }
        }
    }
}

//need a function to make a classroom with the specified rows and columns and print it out
//need a function to assign a seat to a student with the specified ID and print it out
//need a function to get the direct neighbors of a student and print it out

//generate a classroom with rows and columns and print it out with user input
int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    struct Classroom *classroom = generateClassroom(rows, cols);
    printf("Classroom with %d rows and %d columns generated\n", rows, cols);
    //assign a seat to a student with the specified ID and print it out with user input
    int id=0, row=0, col=0;
    printf("Enter the student ID: ");
    scanf("%d", &id);
    printf("Enter the row: ");
    scanf("%d", &row);
    printf("Enter the column: ");
    scanf("%d", &col);
    if(row >= rows || col >= cols || row < 0 || col < 0) {
        printf("Invalid seat\n");
        return 0;
    }
    assignSeat(classroom, id, row, col);
    //get the direct neighbors of a student and print it out with user input
    printf("Enter the student ID: ");
    scanf("%d", &id);
    getDirectNeighbors(classroom, id);
    //get the direct and indirect neighbors of a student and print it out with user input
    printf("Enter the student ID: ");
    scanf("%d", &id);
    getNeighbors(classroom, id);
    freeClassroom(classroom);
    return 0;
}
