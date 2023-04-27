//
// Created by matze on 4/25/2023.
//

#include "functions.h"


// Function to generate the classroom with the specified rows and columns
struct seat **generateClassroom(int rows, int cols) {
    // Allocate memory for the 2D array of seats
    struct seat **classroom = (struct seat**)calloc(rows, sizeof(struct seat*));
    for (int i = 0; i < rows; i++) {
        classroom[i] = (struct seat*)calloc(cols, sizeof(struct seat));
        for(int j = 0; j < cols; j++){
            classroom[i][j].ID[0] = '\0';
        }

    }

    return classroom;
}
// Generate Room
void menu_1(int *rows, int *cols, struct seat **classroom, char roomname[10]) {
    printf("please enter the Name of your room:");
    fflush(stdin);
    fgets(roomname, 10, stdin);
    printf("Please enter the number of your rows and hit enter:");
    fflush(stdin);
    *rows = fgetc(stdin);
    printf("Please enter the number of your cols and hit enter:");
    fflush(stdin);
    *cols = fgetc(stdin);
    classroom = generateClassroom(*rows, *cols);
}


// Save Room
void menu_2(FILE *roomfile, char roompath[250], struct seat **classroom){
        printf("Please paste/type in the path to the room you want to load and hit enter");
        fflush(stdin); fgets(roompath, 250, stdin);
        roomfile =fopen(roompath, "r+");
        if (*classroom != NULL){
            printf("Warning! You already have a room. do you want to save it first? Y/N");
            char answer;
            if (toupper(answer =fgetc(stdin)) == 'Y'){
                saveClassroom();
            }
        }
        else{

        }
}

void saveRoom_toCSV(struct seat **classroom, FILE *csv_path){
    int rows = LEN(classroom)+1;
    int cols = LEN(classroom[0])+1;
    fopen(csv_path, "w");
    fprintf(csv_path, "%d,d%,", rows, cols);
    for(int k = 2; k<cols;k++){
        fprintf(csv_path,",");
    }
    fprintf(csv_path, "\n");
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(classroom[i][j].ID[0] != '\0'){
                fprintf(csv_path, "%s %d %d %d,", classroom[i][j].ID, classroom[i][j].infected, classroom[i][j].directNeighbour, classroom[i][j].indirectNeighbour);
            }
            else{ fprintf(csv_path, ",");}
        }
        fprintf(csv_path, "\n");
    }
    fclose(csv_path);
}

void readRoom_fromCSV(struct seat **classroom, FILE *csv_path){}