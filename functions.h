//
// Created by matze on 4/25/2023.
//

#ifndef PROJEKT_GROUP12_PROJECT1_FUNCTIONS_H
#define PROJEKT_GROUP12_PROJECT1_FUNCTIONS_H
#define MAX_ID_LENGTH
#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


struct seat {
    bool infected;
    bool directNeighbour;
    bool indirectNeighbour;
    char ID[MAX_ID_LENGTH];
};

struct seat **generateClassroom(int rows, int cols);
void saveRoom_toCSV(struct seat **classroom, FILE *csv_path);

void menu_1(int *rows, int *cols, struct seat **classroom, char roomname[10]); // Generate Room
void menu_2(FILE *roomfile, char roompath[250], struct seat **classroom); // Load Room




#endif //PROJEKT_GROUP12_PROJECT1_FUNCTIONS_H
