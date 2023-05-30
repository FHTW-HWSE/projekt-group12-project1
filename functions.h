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

/**
 * @brief Main menu for interacting with the program.
 *
 * This function displays the main menu options to the user, prompts for user input, and performs corresponding actions.
 * It handles options such as generating a new classroom, loading a classroom from a CSV file, saving the classroom to a CSV file,
 * adding students to the classroom, marking a student as infected, and retrieving the direct and indirect neighbors of a student.
 *
 * @param classroom The double pointer to the 2D array representing the classroom.
 * @param rows The number of rows in the classroom.
 * @param cols The number of columns in the classroom.
 * @param roomname The name of the room.
 * @param roompath The path to the room file.
 * @param roomfile A file pointer to the room file.
 * @param argv An array of command-line arguments.
 */
void base_menu(int input, int cols, int rows, struct seat **classroom, char roomname[10], char roompath[250], FILE *roomfile, char *argv[]);

// Generate Room
struct seat **menu_1generateRoom(int *rows, int *cols, struct seat **classroom, char roomname[10], char *argv[]);

/**
 * @brief Function to generate the classroom with the specified rows and columns.
 *
 * This function dynamically allocates memory for the 2D array representing the classroom.
 * It initializes the seats with empty IDs, sets the room name, and initializes the flags for infected,
 * direct neighbors, and indirect neighbors.
 *
 * @param rows The number of rows in the classroom.
 * @param cols The number of columns in the classroom.
 * @param roomname The name of the room.
 * @return The dynamically allocated 2D array representing the classroom.
 */
struct seat **generateClassroom(int rows, int cols, char *roomname);

/**
 * @brief Function to save the classroom to a CSV file.
 *
 * This function takes the 2D array representing the classroom, the number of rows and columns, and the file path as input.
 * It opens the file, writes the classroom data in CSV format, and closes the file.
 *
 * @param classroom The 2D array representing the classroom.
 * @param rows The number of rows in the classroom.
 * @param cols The number of columns in the classroom.
 * @param csv_path The path to the CSV file.
 */
void saveRoom_toCSV(struct seat **classroom, int rows, int cols);

/**
 * @brief Function to load the classroom from a CSV file.
 *
 * This function reads the classroom data from a CSV file and updates the classroom data structure accordingly.
 * It dynamically allocates memory for the 2D array representing the classroom based on the number of rows and columns in the file.
 *
 * @param classroom The double pointer to the 2D array representing the classroom.
 * @param rows A pointer to the variable to store the number of rows in the classroom.
 * @param cols A pointer to the variable to store the number of columns in the classroom.
 * @param csv_path The path to the CSV file.
 */
void loadRoom_fromCSV(struct seat ***classroom, int *rows, int *cols, char *csv_path);

/**
 * @brief Get the file path for loading a room.
 *
 * This function prompts the user to enter the file path of the CSV file to load the classroom.
 * It performs input validation and returns the file path as a string.
 *
 * @return A string containing the file path.
 */
char* get_Filepath();

//add students to room
/**
 * @brief Function to add a student to a room.
 *
 * This function prompts the user to enter the ID of the student to be added and the seat coordinates
 * where the student should be placed. It then updates the classroom data structure with the student's ID
 * and saves the updated room to a CSV file.
 *
 * @param classroom The 2D array representing the classroom.
 * @param rows The number of rows in the classroom.
 * @param cols The number of columns in the classroom.
 */
void addStudentsToRoom(struct seat **classroom, int rows, int cols);


/**
 * @brief Menu function for adding students to a room.
 *
 * This menu function prompts the user to enter the ID of the student to be added and the seat coordinates
 * where the student should be placed. It performs input validation and calls the addStudentsToRoom function
 * to add the student to the room.
 *
 * @param classroom The 2D array representing the classroom.
 * @param rows The number of rows in the classroom.
 * @param cols The number of columns in the classroom.
 */
void menu_4addStudentsToRoom(struct seat **classroom, int rows, int cols);

//mark student as infected
/**
 * @brief Function to mark a student as infected.
 *
 * This function prompts the user to enter the seat coordinates of the student to be marked as infected.
 * It performs input validation and updates the infected flag of the student in the classroom data structure.
 *
 * @param classroom The 2D array representing the classroom.
 * @param rows The number of rows in the classroom.
 * @param cols The number of columns in the classroom.
 */
void markStudentAsInfected(struct seat **classroom, int rows, int cols);

//get direct neighbours of a room
/**
 * @brief Function to get the direct neighbors of a student.
 *
 * This function prompts the user to enter the seat coordinates of the student for which to retrieve the direct neighbors.
 * It performs input validation and checks if the student is infected and if the student has any direct neighbors.
 * If both conditions are met, it prints the IDs of the direct neighbors.
 *
 * @param classroom The 2D array representing the classroom.
 * @param rows The number of rows in the classroom.
 * @param cols The number of columns in the classroom.
 */
void getDirectNeighbours(struct seat **classroom, int rows, int cols);

//get indirect neighbours of a room
/**
 * @brief Function to get the indirect neighbors of a student.
 *
 * This function prompts the user to enter the seat coordinates of the student for which to retrieve the indirect neighbors.
 * It performs input validation and checks if the student is infected and if the student has any indirect neighbors.
 * If both conditions are met, it prints the IDs of the indirect neighbors.
 *
 * @param classroom The 2D array representing the classroom.
 * @param rows The number of rows in the classroom.
 * @param cols The number of columns in the classroom.
 */
void getIndirectNeighbours(struct seat **classroom, int rows, int cols);



#endif //PROJEKT_GROUP12_PROJECT1_FUNCTIONS_H
