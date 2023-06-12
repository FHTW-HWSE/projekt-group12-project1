#include <unistd.h>
#include "functions.h"



struct seat **menu_1generateRoom(int *rows, int *cols, struct seat **classroom, char roomname[MAX_ROOMNAME_LENGTH], char *argv[]) {
    printf("Please enter the Name of your room:");
    fflush(stdin);
    fgets(roomname, MAX_ROOMNAME_LENGTH, stdin);
    fflush(stdin);
    // Remove trailing newline character
    if ((strlen(roomname) > 0) && (roomname[strlen (roomname) - 1] == '\n'))
        roomname[strlen (roomname) - 1] = '\0';
    fflush(stdin);
    printf("Please enter the number of your rows and hit enter:");
    fflush(stdin);
    *rows = getMultidigit();
    printf("Please enter the number of your cols and hit enter:");
    fflush(stdin);
    *cols = getMultidigit();
    printf("You entered %d rows and %d colums\n\n", *rows, *cols);

    return generateClassroom(*rows, *cols, roomname);
}

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

void loadRoom_fromCSV(struct seat ***classroom, int *rows, int *cols, char *csv_path) {
    FILE *csv = fopen(csv_path, "r");
    if (csv == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    //cat the first 2 symbols of the csv_path then cut the last 4 symbols of the csv_path to get the roomname
    char *roomname = (char *)calloc(strlen(csv_path) - 2, sizeof(char));
    strncpy(roomname, csv_path + 2, strlen(csv_path) - 6);



    // Read the dimensions of the room from the first line of the CSV
    fscanf(csv, "%d,%d\n", rows, cols);

    // Allocate memory for the 2D array of seats
    *classroom = (struct seat **)calloc(*rows, sizeof(struct seat *));
    for (int i = 0; i < *rows; i++) {
        (*classroom)[i] = (struct seat *)calloc(*cols, sizeof(struct seat));
    }

    for (int i = 0; i < strlen(roomname); i++) {
        (*classroom)[0][0].roomname[i] = roomname[i];
    }
    (*classroom)[0][0].roomname[strlen(roomname)] = '\0';
    free(roomname);

    // Read the seat data from the CSV and populate the classroom
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            int MAX_SEAT_DATA_LENGTH;
            char seatData[MAX_SEAT_DATA_LENGTH];
            fscanf(csv, "%[^,\n]", seatData);
            fgetc(csv);  // Consume the comma or newline character

            // Parse the seat data and assign it to the corresponding seat in the classroom
            if (strlen(seatData) > 0) {
                sscanf(seatData, "%s %d %d %d", (*classroom)[i][j].ID, &(*classroom)[i][j].infected,
                       &(*classroom)[i][j].directNeighbour, &(*classroom)[i][j].indirectNeighbour);
            }
        }
    }

    fclose(csv);
}

void saveRoom_toCSV(struct seat **classroom, int rows, int cols) {
    if (classroom == NULL || classroom[0] == NULL) {
        printf("Invalid classroom data.\n");
        return;
    }

    // Assuming roomname is a null-terminated string in the struct seat
    char *roomname = classroom[0][0].roomname;
    char csv_path[MAX_ROOMNAME_LENGTH + 5]; // 4 for ".csv" extension and 1 for null-terminator
    char lineholder[MAX_CSV_LINE_LENGTH];
    // Create the csv_path by appending ".csv" to the room name
    snprintf(csv_path, sizeof(csv_path), "%s.csv", roomname);
    printf("\nSaving room to %s\n", csv_path);

    char cwd[PATH_MAX]; // Buffer to store the current working directory
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
    }



    FILE *csv = fopen(csv_path, "w");
    if (csv == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fprintf(csv, "%d,%d\n", rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j > 0) {
                fprintf(csv, ",");
            }
            if (classroom[i][j].ID[0] != '\0') {
                sprintf(lineholder, "%s %d %d %d",classroom[i][j].ID, classroom[i][j].infected,
                        classroom[i][j].directNeighbour, classroom[i][j].indirectNeighbour);
                fprintf(csv, "%s", lineholder);
            } else {
                fprintf(csv, "X"); // Print "X" for empty seats
            }
        }
        fprintf(csv, "\n");
    }
    printf("\nRoom saved successfully.\n");
    fclose(csv);
}

// Function to add a student to a room
void addStudentsToRoom(struct seat **classroom, int rows, int cols) {
    int row, col, len;
    char studentID[10];
    printf("Please enter the ID of the student you want to add:");
    fflush(stdin);
    fgets(studentID, 10, stdin);
    len = strlen(studentID);
    if (len > 0 && studentID[len - 1] == '\n') {
        studentID[len - 1] = '\0';
    }
    printf("Please enter the row of the seat you want to add the student to:");
    fflush(stdin);
    row = getMultidigit();
    printf("Please enter the column of the seat you want to add the student to:");
    fflush(stdin);
    col = getMultidigit();

    // Check if the seat coordinates are valid
    if (row < 1 || row > rows || col < 1 || col > cols) {
        printf("Invalid seat coordinates.\n");
        return;
    }

    // Check if the seat is already occupied
    if (classroom[row - 1][col - 1].ID[0] != 'X') {
        printf("The seat is already occupied.\n");
        return;
    }

    // Update the classroom data structure
    strcpy(classroom[row - 1][col - 1].ID, studentID);
    printf("Student %s added to seat %d-%d.\n", studentID, row, col);

    // Save the updated classroom to the CSV file
    saveRoom_toCSV(classroom, rows, cols);
}
//add student to room

void menu_4addStudentsToRoom(struct seat **classroom, int rows, int cols) {
    int row, col;
    char ID[10];
    printf("Please enter the ID of the student you want to add: ");
    fflush(stdin);
    fgets(ID, 10, stdin);
    printf("Please enter the row of the seat you want to add the student to: ");
    fflush(stdin);
    scanf("%d", &row);
    printf("Please enter the column of the seat you want to add the student to: ");
    fflush(stdin);
    scanf("%d", &col);

    // Check if the seat coordinates are valid
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        printf("Invalid seat coordinates.\n");
        return;
    }

    // Check if the seat is already occupied
    if (classroom[row][col].ID[0] != '\0') {
        printf("The seat is already occupied.\n");
        return;
    }

    strcpy(classroom[row][col].ID, ID);
    saveRoom_toCSV(classroom, rows, cols);
}

//mark a student as infected
void markStudentAsInfected(struct seat **classroom, int rows, int cols) {
    char studentID[10];
    printf("The students in the room are:\n");

// Display all the students IDs
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(strcmp(classroom[i][j].ID, "X") != 0) {
                printf("Student ID: %s, Seat: %d-%d\n", classroom[i][j].ID, i+1, j+1);
            }
        }
    }


    printf("Please enter the ID of the student to mark as infected:");
    fflush(stdin);
    fgets(studentID, 10, stdin); // Assumes IDs are at most 9 characters, plus the null terminator

    // Remove trailing newline character if it exists
    if ((strlen(studentID) > 0) && (studentID[strlen (studentID) - 1] == '\n')) {
        studentID[strlen (studentID) - 1] = '\0';
    }

    // Look for the student with the matching ID and mark them as infected
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (strcmp(classroom[i][j].ID, studentID) == 0) {
                classroom[i][j].infected = 1;
                printf("Student with ID %s in seat %d-%d marked as infected.\n", studentID, i+1, j+1);
                saveRoom_toCSV(classroom, rows, cols);
                return;
            }
        }
    }

    printf("Invalid student ID.\n");
}


// Function to get the direct neighbours of a student
void getDirectNeighbours(struct seat **classroom, int rows, int cols) {
    int row, col;
    printf("Please enter the row of the seat to get direct neighbors:");
    fflush(stdin);
    row = getMultidigit();
    printf("Please enter the column of the seat to get direct neighbors:");
    fflush(stdin);
    col = getMultidigit();

    // Check if the seat coordinates are valid
    if (row < 1 || row > rows || col < 1 || col > cols) {
        printf("Invalid seat coordinates.\n");
        return;
    }

    // Check if the student is infected
    if (classroom[row - 1][col - 1].infected != 1) {
        printf("The student in seat %d-%d is not infected.\n", row, col);
        return;
    }

    // Find and print the direct neighbors
    printf("Direct neighbors of student in seat %d-%d:\n", row, col);
    if (row - 2 >= 0) {
        printf("%s\n", classroom[row - 2][col - 1].ID);
    }
    if (row < rows) {
        printf("%s\n", classroom[row][col - 1].ID);
    }
    if (col - 2 >= 0) {
        printf("%s\n", classroom[row - 1][col - 2].ID);
    }
    if (col < cols) {
        printf("%s\n", classroom[row - 1][col].ID);
    }
}

//get indirect neighbours
void getIndirectNeighbours(struct seat **classroom, int rows, int cols) {
    int row, col;
    printf("Please enter the row of the seat to get indirect neighbors:");
    fflush(stdin);
    row = getMultidigit();
    printf("Please enter the column of the seat to get indirect neighbors:");
    fflush(stdin);
    col = getMultidigit();

    // Check if the seat coordinates are valid
    if (row < 1 || row > rows || col < 1 || col > cols) {
        printf("Invalid seat coordinates.\n");
        return;
    }

    // Check if the student is infected
    if (classroom[row - 1][col - 1].infected != 1) {
        printf("The student in seat %d-%d is not infected.\n", row, col);
        return;
    }

    // Find and print the indirect neighbors
    printf("Indirect neighbors of student in seat %d-%d:\n", row, col);
    if (row - 2 >= 0 && col - 2 >= 0) {
        printf("%s\n", classroom[row - 2][col - 2].ID);
    }
    if (row - 2 >= 0 && col < cols) {
        printf("%s\n", classroom[row - 2][col].ID);
    }
    if (row < rows && col - 2 >= 0) {
        printf("%s\n", classroom[row][col - 2].ID);
    }
    if (row < rows && col < cols) {
        printf("%s\n", classroom[row][col].ID);
    }
}



// i need a get_Filepath function - ITS WORKING
char* get_Filepath(){
    char roomname[MAX_ROOMNAME_LENGTH];
    char* filepath = calloc(MAX_FILEPATH_LENGTH, sizeof(char));

    printf("Please enter the name of the room you want to load: ");
    fflush(stdin);
    fgets(roomname, MAX_ROOMNAME_LENGTH, stdin);

    // Remove trailing newline character
    if (roomname[strlen(roomname) - 1] == '\n')
        roomname[strlen(roomname) - 1] = '\0';

    snprintf(filepath, MAX_FILEPATH_LENGTH, "./%s.csv", roomname);

    return filepath;
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

int getMultidigit() {
    char input[100];
    int number;
    bool isValid = false;

    while (!isValid) {
        //printf("Enter a positive multidigit number: ");
        fgets(input, sizeof(input), stdin);

        // Check if input contains any non-digit characters
        bool containsNonDigit = false;
        for (int i = 0; input[i] != '\n'; i++) {
            if (!isdigit(input[i])) {
                containsNonDigit = true;
                break;
            }
        }

        if (containsNonDigit) {
            printf("Invalid input. Please enter a positive number.\n");
        } else {
            number = atoi(input);
            if (number < 0) {
                printf("Invalid input. Please enter a non-negative number.\n");
            } else {
                isValid = true;
            }
        }
    }

    return number;
}