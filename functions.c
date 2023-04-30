//
// Created by matze on 4/25/2023.
//

#include "functions.h"


// Function to generate the classroom with the specified rows and columns
struct seat **generateClassroom(int rows, int cols, char *roomname) {
    // Allocate memory for the 2D array of seats
    struct seat **classroom = (struct seat **) calloc(rows, sizeof(struct seat *));
    for (int i = 0; i < rows; i++) {
        classroom[i] = (struct seat *) calloc(cols, sizeof(struct seat));
        for (int j = 0; j < cols; j++) {
            classroom[i][j].ID[0] = '\0';
            strcpy(classroom[i][j].roomname, roomname);
            classroom[i][j].infected = -1;
            classroom[i][j].directNeighbour = -1;
            classroom[i][j].indirectNeighbour = -1;
        }
    }
    return classroom;
}


// Menu for: Generate Room, uses generateClassroom function

void base_menu(int input, int cols, int rows, struct seat **classroom, char roomname[10], char roompath[250], FILE *roomfile, char *argv[]){
    input = fgetc(stdin)-48;
    printf("Please select what you want to do by entering the menu points digit:\n  1) Generate a Room\n  2) Load a room\n  3) Save Room to file\n  4) Add Students to a Room \n  5) Mark a Student as Infected\n  6) Get direct neighbours of a Room\n  7) Get indirect neigbours of a room  ");

    if(input > 0 && input < 10){
        switch(input){
            case 1:
                menu_1generateRoom(&rows, &cols, classroom, roomname, argv);
                break;
            case 2:
                menu_2saveRoom(roomfile, roompath, classroom, argv);
                break;
            default:
                printf("No really just why default");
        }
    }
}

void
menu_1generateRoom(int *rows, int *cols, struct seat **classroom, char roomname[MAX_ROOMNAME_LENGTH], char *argv[]) {
    printf("please enter the Name of your room:");
    fflush(stdin);
    fgets(roomname, 10, stdin);
    printf("Please enter the number of your rows and hit enter:");
    fflush(stdin);
    *rows = fgetc(stdin)-48;
    printf("Please enter the number of your cols and hit enter:");
    fflush(stdin);
    *cols = fgetc(stdin)-48;
    classroom = generateClassroom(*rows, *cols, roomname);
}


// Menu for: Save Room, uses get_filepath, saveRoom_toCSV
void menu_2saveRoom(FILE *roomfile, char roompath[250], struct seat **classroom, char *argv[0]) {
    roompath = get_Filepath(argv);
    roomfile = fopen(roompath, "r+");
    if (classroom != NULL) {
        printf("You have a room. It has the name '%s'. Do you want to save it? Y/N", classroom[0][0].roomname);
        char answer;
        if (toupper(answer = fgetc(stdin)) == 'Y') {
            char *filepath = get_Filepath(argv);
            saveRoom_toCSV(classroom, filepath);
        }
    } else {
        printf("You dont have a Room loaded -> generate one first, returning back to main menu");


    }
}

char *get_Filepath(char *argv[]) {
    char roomname[MAX_ROOMNAME_LENGTH];
    char *filepath = calloc(MAX_FILEPATH_LENGTH, sizeof(char));
    int i = 0;
    printf("Please type in your desired Roomname and hit enter:");
    fflush(stdin);
    fgets(roomname, 18, stdin);
    while (argv[0][i] != '\0') {
        i++;
    }
    while (argv[0][i] != '/' || argv[0][i] != '\\') {
        i--;
    }
    for (int j = 0; j <= i; j++) {
        filepath[j] = argv[0][j];
    }
    strcat(filepath, roomname);
    return filepath;
}

void saveRoom_toCSV(struct seat **classroom, char *csv_path) {
    int rows = LEN(classroom)+1;
    int cols = LEN(classroom[0])+1;
    FILE *csv = fopen(csv_path, "w");
    fprintf(csv, "%d,%d,", rows, cols);
    for (int k = 2; k < cols; k++) {

        fprintf(csv, ",");
    }
    fprintf(csv, "\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (classroom[i][j].ID[0] != '\0') {    // check for empty seat!
                fprintf(csv, "%s %d %d %d,", classroom[i][j].ID, classroom[i][j].infected,
                        classroom[i][j].directNeighbour, classroom[i][j].indirectNeighbour);
            } else { fprintf(csv, ","); }
        }
        fprintf(csv, "\n");
    }
    fclose(csv);
}

void readRoom_fromCSV(struct seat **classroom, char *csv_path) {
    int rows = 0, cols = 0, i = 0, j = 0, k = 0;
    char *cursor;
    char line[MAX_CSV_LINE_LENGTH] = {0};
    int commacounter = 0, linecounter = 0;
    FILE *csv = fopen(csv_path, "r");
    while (fgets(line, sizeof line, csv) != NULL) {
        while (line[i] != '\n') {
            if (line[i++] == ',') {
                commacounter++;
                continue;
            }
            if (rows == 0) {
                rows = strtol(line, &cursor, 10);
                while (*(cursor + k) != ',') {
                    k++;
                    i++;
                }
                if (line[i++] == ',') {
                    commacounter++;
                    k++;
                }

                if ((cols = strtol((cursor + k), &cursor, 10)) == 0) {  // cursor + 1 for: skipping the ","
                    printf("File seems to be corrupted; second element of first row doesnt contain a valid number for Colum Value");
                    EXIT_FAILURE;
                }
                while (cursor[j] != '\n') {
                    if (cursor[j++] == ',')
                        commacounter++;
                }
                if (commacounter != cols) {
                    printf("File seems to be corrupted; number of columns doesnt match the number of Commas in the first line");
                    EXIT_FAILURE;
                }
                linecounter++;
            } else {
                int l = 0, lengthID = 0;
                k = 0, i = 0, commacounter = 0;
                int statuses = 0;
                while (line[i] != '\n') {
                    if (line[i++] == ',') {
                        commacounter++;
                        continue;
                    }
                    i += sprintf(classroom[k][l].ID, "%s", line) +
                         1;      // Statuses: infected directNeighbour indirectNeighbour
                    statuses = strtol(&line[i], &cursor, 10);
                    classroom[k][l].infected = statuses;
                    statuses = strtol(cursor + 1, &cursor, 10);
                    classroom[k][l].directNeighbour = statuses;
                    statuses = strtol(cursor + 1, &cursor, 10);
                    classroom[k][l].indirectNeighbour = statuses;
                }


            }
        }

    }



}