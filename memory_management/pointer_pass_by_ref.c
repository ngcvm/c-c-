#include <stdio.h>
#include <stdlib.h>

void print_int_by_value(int number);

void print_int_by_reference(int *number_ptr);

void malloc_int_dangerous(int *number_ptr);

void malloc_int_safe(int** number_double_ptr);

int main (int argc, char* argv[]) {
    //
    int my_number = 20;

    print_int_by_value(my_number);

    print_int_by_reference(&my_number);

    printf("The addresses printed above should be different! \n\n");

    int* number_ptr = &my_number;

    printf("'number_ptr' address before malloc: %p\n", number_ptr);

    // 1. Create a function that takes in a pointer to an int, attempts to malloc memory for it and return the pointer - 
    // this will not work (memory leak will occur... because the pointer passed int points to a memory on the stack)
    malloc_int_dangerous(number_ptr);

    printf("Original 'number_ptr' address after dangerous malloc: %p\n", number_ptr);
    printf("The above address for 'number_ptr' does not change!\n");

    // 2. Creat a function that takes in a double pointer to an int and malloc memory to the dereferenced double pointer 
    malloc_int_safe(&number_ptr); // Pass the address of 'number_ptr' pointer

    printf("'number_pointer' address after safe malloc: %p\n", number_ptr);

    free(number_ptr);

    number_ptr = NULL;
    return 0;
}

// The 'number' argument below is copied into the function scope
void print_int_by_value(int number) {
    printf("The number has this address and value: %p, %d\n", &number, number);
}

// Takes in an integer and print its address and value to the console
void print_int_by_reference(int *number_ptr) {
    printf("The number has this address and value: %p, %d\n", number_ptr, *number_ptr);
}

//
void malloc_int_dangerous(int *number_ptr) {
    number_ptr = (int*)malloc(sizeof(int));
    printf("[malloc_int_dangerous] => 'number_ptr' address after dangerous malloc: %p\n", number_ptr);
    printf("[malloc_int_dangerous] => ^^ That address space marks the memory-leaked block!\n\n");
    // 'number_ptr' now goes out of scope and you have a memory leak...
}

void malloc_int_safe(int **number_double_ptr) {
    *number_double_ptr = (int*)malloc(sizeof(int));
}