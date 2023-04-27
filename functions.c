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

void saveRoom_toCSV(struct seat **classroom, char *csv_path){
    int rows = LEN(classroom)+1;
    int cols = LEN(classroom[0])+1;
    FILE *csv = fopen(csv_path, "w");
    fprintf(csv, "%d,%d,", rows, cols);
    for(int k = 2; k<cols;k++){

        fprintf(csv,",");
    }
    fprintf(csv, "\n");
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(classroom[i][j].ID[0] != '\0'){
                fprintf(csv, "%s %d %d %d,", classroom[i][j].ID, classroom[i][j].infected, classroom[i][j].directNeighbour, classroom[i][j].indirectNeighbour);
            }
            else{ fprintf(csv, ",");}
        }
        fprintf(csv, "\n");
    }
    fclose(csv);
}

void readRoom_fromCSV(struct seat **classroom, char *csv_path){
    int rows = 0, cols = 0, i = 0, j = 0;
    char *cursor;
    char line[1000]= {0};
    int commacounter = 0, linecounter = 0;
    FILE *csv = fopen(csv_path, "r");
    while(fgets(line,sizeof line,csv)!= NULL){
        while(line[i] != '\n'){
            if(line[i] == ','){commacounter++;}
            if(rows == 0){
                rows = strtol(line, &cursor, 10);
                if(!isalpha((cols = strtol((cursor+1), &cursor, 10)))){
                    printf("File seems to be corrupted; second element of first row doesnt contain a valid number for Colum Value");
                    EXIT_FAILURE;
                }
                while(cursor[j] != '\n'){
                    if(cursor[j++] == ',')
                        commacounter++;
                }
                linecounter++;
            }
            else{
                int k = 0, l = 0, lengthID = 0;
                int statuses = 0;
                while(line[i] != '\n'){
                    if(line[i] == ','){
                        l++;
                    }
                    i += sprintf(classroom[k][l].ID, "%s", line);      // Statuses: infected directNeighbour indirectNeighbour
                    statuses = strtol(&line[i], &cursor, 10);
                    classroom[k][l].infected = statuses;
                    statuses = strtol(cursor, &cursor, 10);
                    classroom[k][l].directNeighbour = statuses;
                    statuses = strtol(cursor, &cursor, 10);
                    classroom[k][l].indirectNeighbour = statuses;


                }


            }
        }

    }
    fread(atol(rows), sizeof(int), 1, csv);


}