
#include "main.h"
#include "functions.h"


//need a function to make a classroom with the specified rows and columns and print it out
//need a function to assign a seat to a student with the specified ID and print it out
//need a function to get the direct neighbors of a student and print it out
//generate a classroom with rows and columns and print it out with user input


int main() {
    int rows, cols;
    int input = 0;
    char roomname[10];
    char roompath[250];
    FILE *roomfile;


    printf("Please select what you want to do by entering the menu points digit:\n  1) Generate a Room\n  2) Load a room\n  3) Save Room to file\n  4) Add Students to a Room \n  5) Mark a Student as Infected\n  6) Get direct neighbours of a Room\n  7) Get indirect neigbours of a room  ");
    input = fgetc(stdin)-48;
    struct seat **classroom;
    if(input > 0 && input < 10){
        switch(input){
            case 1:
                menu_1(&rows,&cols, classroom,roomname);
                break;
            case 2:
                menu_2(roomfile, roompath, classroom);
                break;
                }
            default:
                printf("No really just why default");
        }
    }
    return 0;
}
