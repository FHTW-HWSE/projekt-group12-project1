
#include "main.h"
#include "functions.h"


//need a function to make a classroom with the specified rows and columns and print it out
//need a function to assign a seat to a student with the specified ID and print it out
//need a function to get the direct neighbors of a student and print it out
//generate a classroom with rows and columns and print it out with user input


int main(int argc, char *argv[]) {
    int rows, cols;
    int input = 0, exit = 0;

    char roomname[10];
    char roompath[250];
    FILE *roomfile;
    struct seat **classroom = NULL;
    setbuf(stdout, NULL);

    while (exit != 1) {
        printf("Please select what you want to do by entering the menu points digit:\n"
               "  0) Exit the program\n"
               "  1) Generate a Room\n"
               "  2) Load a room\n"
               "  3) Save Room to file\n"
               "  4) Add Students to a Room\n"
               "  5) Mark a Student as Infected\n"
               "  6) Get direct neighbours for a Room\n"
               "  7) Get indirect neigbours for a room\n");

        fflush(stdin);
        input = getMultidigit();
        if (input >= 0 && input < 10) {
            switch (input) {
                case 0:
                    exit = 1;
                    break;
                case 1:
                    classroom = menu_1generateRoom(&rows, &cols, classroom, roomname, argv);
                    break;
                case 2:
                    loadRoom_fromCSV(&classroom, &rows, &cols, get_Filepath(argv));
                    break;
                case 3:
                    //saveRoom_toCSV(&classroom,rows, cols);
                    break;
                case 4:
                    //add student to room menu_4addStudentsToRoom
                    if (classroom != NULL) {
                        addStudentsToRoom(classroom, rows, cols);
                    } else {
                        printf("Please generate or load a room first.\n");
                    }
                    break;
                case 5:
                    if (classroom != NULL) {
                        markStudentAsInfected(classroom, rows, cols);
                    } else {
                        printf("Please generate or load a room first.\n");
                    }
                    break;
                case 6:
                    if (classroom != NULL) {
                        getDirectNeighbours(classroom, rows, cols);
                    } else {
                        printf("Please generate or load a room first.\n");
                    }
                    break;
                case 7:
                    if (classroom != NULL) {
                        getIndirectNeighbours(classroom, rows, cols);
                    } else {
                        printf("Please generate or load a room first.\n");
                    }
                    break;
                default:
                    printf("Invalid input. Please try again.\n");
            }
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
    return 0;
}







