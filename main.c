
#include "main.h"
#include "functions.h"


//need a function to make a classroom with the specified rows and columns and print it out
//need a function to assign a seat to a student with the specified ID and print it out
//need a function to get the direct neighbors of a student and print it out
//generate a classroom with rows and columns and print it out with user input


int main() {
    int rows, cols;
    int input = 0;
    printf("Please select what you want to do by entering the menu points digit:\n  1) Generate a Room\n  2) Add Students to the Room \n  3) Mark a Student as Infected\n  4) Get direct neighbours of a Room\n  5) Get indirect neigbours of a room  ");
    input = fgetc(stdin)-48;
    struct seat **classroom;
    if(input > 0 && input < 10){
        switch(input){
            case 1:  classroom = generateClassroom(4,5);
            for(int i = 0; i<4;i++){
                for(int j = 0; j<5;j++){
                    classroom[i][j].ID[0] = (i+'0')+(j+'0');
                    printf("%s -- %d\n", classroom[i][j].ID, j);
                }
            }
                break;
            case 2:
                printf("Just why");
            default:
                printf("No really just why default");
        }
    }
    return 0;
}
