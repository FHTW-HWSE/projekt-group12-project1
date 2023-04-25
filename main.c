
#include "main.h"
#include "functions.h"


//need a function to make a classroom with the specified rows and columns and print it out
//need a function to assign a seat to a student with the specified ID and print it out
//need a function to get the direct neighbors of a student and print it out
//generate a classroom with rows and columns and print it out with user input


int main() {
    int rows, cols;
    printf("Please select what you want to do:\n  1) Generate a Room\n  2) Add Students to the Room \n  3)  ")
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    struct Classroom *classroom = generateClassroom(rows, cols);
    printf("Classroom with %d rows and %d columns generated\n", rows, cols);
    //assign a seat to a student with the specified ID and print it out with user input
    int id, row, col;
    printf("Enter the student ID: ");
    scanf("%d", &id);
    printf("Enter the row: ");
    scanf("%d", &row);
    printf("Enter the column: ");
    scanf("%d", &col);
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
