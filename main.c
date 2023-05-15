
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
        printf("Please select what you want to do by entering the menu points digit:\n  1) Generate a Room\n  2) Load a room\n  3) Save Room to file\n  4) Add Students to a Room \n  5) Mark a Student as Infected\n  6) Get direct neighbours for a Room\n  7) Get indirect neigbours for a room  ");
        input = fgetc(stdin) - 48;
        if (input > 0 && input < 10) {
            switch (input) {
                case 1:
                    menu_1generateRoom(&rows, &cols, classroom, roomname, argv);
                    break;
                case 2:
                    menu_2saveRoom(roomfile, roompath, classroom, argv);
                    break;
                case 3:
                    printf("No really just why default");
                    break;
                case 4:
                    addStudentsToRoom(classroom, rows, cols);
                    break;
                case 5:
                    markStudentAsInfected(classroom, rows, cols);
                    break;


                default:
                    printf("No really just why default");
            }
        }
        return 0;
    }
}
