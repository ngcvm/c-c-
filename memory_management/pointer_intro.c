#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
    int my_number = 10;

    // Declare a pointer
    int* my_pointer;

    // Getting the address of my_number using the "address operator - &"
    printf("The address of my number: %p\n", &my_number);

    // Initialize a pointer using the "address operator - &"
    my_pointer = &my_number;

    // Initialize a pointer using malloc
    char* name = (char*)malloc(8 * sizeof(char));

    // Deference a pointer to read a value at its address
    printf("My 'my_pointer' value: %d\n", *my_pointer);

    int my_copied_number = *my_pointer;

    printf("My 'my_copied_number' value: %d\n", my_copied_number);

    // Increase value of my_copied_number to see if my_number value changes also
    my_copied_number++;
    printf("My 'my_copied_number' value after increased: %d\n", my_copied_number);
    printf("My 'my_number' value after 'my_copied_number' increased: %d\n", my_copied_number);

    // Deference a pointer to assign a value to it
    *my_pointer = 20;

    printf("My 'my_pointer' after reassign value: %d\n", *my_pointer);

    free(name);
    return 0;
}