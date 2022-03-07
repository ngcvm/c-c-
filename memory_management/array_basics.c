#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ARRAY_SIZE 4

typedef struct Person {
    int age;
    int id;
} Person;

int main(int argc, char* argv[]) {
    // Declare an array
    int numbers[] = { 1, 2, 3, 4 };

    const double floats[] = { 1.23, 1.45, 1.67, 1.99 };

    const char name[] = "Zach";

    const Person people[] = {
        { 47, 1},
        { 35, 2 }
    };

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("\nNumber: %d\n", numbers[i]);
        numbers[i] += 2;
    }

    assert(numbers == &numbers[0]);

    printf("\nStarting address of 'number' array by array name: %p\n", numbers);
    printf("\nStarting address of 'number' array by pointer to the first element: %p\n", &numbers[0]);

    return 1;
}