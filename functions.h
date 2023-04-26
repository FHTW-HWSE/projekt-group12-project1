//
// Created by matze on 4/25/2023.
//

#ifndef PROJEKT_GROUP12_PROJECT1_FUNCTIONS_H
#define PROJEKT_GROUP12_PROJECT1_FUNCTIONS_H
#define MAX_ID_LENGTH

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

struct seat {
    bool infected;
    bool directNeighbour;
    bool indirectNeighbour;
    char ID[MAX_ID_LENGTH];
};

struct seat **generateClassroom(int rows, int cols);


#endif //PROJEKT_GROUP12_PROJECT1_FUNCTIONS_H
