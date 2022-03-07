#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLUMNS 4

int main(int argc, char* argv[]) {
    // Declare and initialize a multi dimensional array containing 10 rows and 4 columns
    int matrix[ROWS][COLUMNS] = {
        { 1, 0, 1, 0 },
        { 0, 0, 1, 1 },
        { 1, 1, 1, 1 },
        { 0, 0, 1, 1 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 },
        { 1, 1, 1, 1 },
        { 1, 0, 0, 1 },
        { 1, 1, 0, 1 },
        { 0, 1, 1, 0 },
    };

    // Loop over column within each row
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            // Flip all the bits within each row - 0's will become 1's and 1's will become 0's
            matrix[i][j] = matrix[i][j] ^ 1;
        }
    }

    return 1;
}