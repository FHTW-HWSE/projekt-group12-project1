//
// Created by matze on 4/25/2023.
//

#ifndef PROJEKT_GROUP12_PROJECT1_FUNCTIONS_H
#define PROJEKT_GROUP12_PROJECT1_FUNCTIONS_H
#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))
#define MAX_ID_LENGTH
#define MAX_CSV_LINE_LENGTH 1000
#define MAX_ROOMNAME_LENGTH 20
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

};

struct seat **generateClassroom(int rows, int cols, char *roomname);
void base_menu(int input, int cols, int rows, struct seat **classroom, char roomname[10], char roompath[250], FILE *roomfile, char *argv[]);
void saveRoom_toCSV(struct seat **classroom, char *csv_path);

void menu_1generateRoom(int *rows, int *cols, struct seat **classroom, char roomname[10], char *argv[]); // Generate Room
void menu_2saveRoom(FILE *roomfile, char roompath[250], struct seat **classroom, char *argv[0]); // Load Room


char *get_Filepath(char *argv[]);

//add student to room
void addStudentsToRoom(struct seat **classroom, int rows, int cols);

//mark student as infected
void markStudentAsInfected(struct seat **classroom, int rows, int cols);



#endif //PROJEKT_GROUP12_PROJECT1_FUNCTIONS_H
