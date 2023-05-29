//
// Created by matze on 4/25/2023.
//

#ifndef PROJEKT_GROUP12_PROJECT1_FUNCTIONS_H
#define PROJEKT_GROUP12_PROJECT1_FUNCTIONS_H
#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))
#define MAX_ID_LENGTH
#define MAX_CSV_LINE_LENGTH 1000
#define MAX_ROOMNAME_LENGTH 50
#define MAX_FILEPATH_LENGTH 250


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


struct seat {
    int infected;
    int directNeighbour;
    int indirectNeighbour;
    char ID[10];                        // 10 is suboptimal, but i cant use a preprocessor constant because of flexible data type
    char roomname[MAX_FILEPATH_LENGTH];
    int grade;
    int assignment1;
    int assignment2;
};

void base_menu(int input, int cols, int rows, struct seat **classroom, char roomname[10], char roompath[250], FILE *roomfile, char *argv[]);

// Generate Room
struct seat **menu_1generateRoom(int *rows, int *cols, struct seat **classroom, char roomname[10], char *argv[]);
struct seat **generateClassroom(int rows, int cols, char *roomname);

void saveRoom_toCSV(struct seat **classroom, int rows, int cols);


void loadRoom_fromCSV(struct seat ***classroom, int *rows, int *cols, char *csv_path);


char* get_Filepath();
//add student to room
void addStudentsToRoom(struct seat **classroom, int rows, int cols);

//mark student as infected
void markStudentAsInfected(struct seat **classroom, int rows, int cols);

//get direct neighbours of a room
void getDirectNeighbours(struct seat **classroom, int rows, int cols);

//get indirect neighbours of a room
void getIndirectNeighbours(struct seat **classroom, int rows, int cols);

//add student to room
void addStudentsToRoom(struct seat **classroom, int rows, int cols);

#endif //PROJEKT_GROUP12_PROJECT1_FUNCTIONS_H
