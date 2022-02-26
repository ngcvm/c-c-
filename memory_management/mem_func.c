/**
 * @file mem_func.c
 * @author ngcvm
 * @brief 
 * @version 0.1
 * @date 2022-02-26
 * 
 * @copyright Copyright (c) 2022
 * 
 * This file endeavors to show working code examples of the following:
 * 1. Including the "stdlib.h" standard library header file
 * 2. Allocating memory using malloc
 * 3. Allocating and initializing memory using calloc
 * 4. Changing the size of an already allocated block of memory using realloc
 * 5. Freeing allocated memory
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int number_count = 4;

    int* my_allocated_mem_ptr = (int*)malloc(sizeof(int) * number_count);
    printf("My allocated mem: %p\n", my_allocated_mem_ptr);

    for (int i = 0; i < number_count; i++) {
        *(my_allocated_mem_ptr + i) = i;
        printf("Added value %d to address %p: \n", i, my_allocated_mem_ptr + i);
    }

    printf("\n\n");

    int* my_other_allocated_mem_ptr = (int*)calloc(number_count, sizeof(int));
    printf("My other allocated mem: %p\n", my_other_allocated_mem_ptr);

    for (int i = 0; i < number_count; i++) {
        printf("Value in calloc'd addresses should be 0: %d\n", *(my_other_allocated_mem_ptr + i));
        *(my_other_allocated_mem_ptr + i) = i;
        printf("Added value %d to address %p: \n", i, my_other_allocated_mem_ptr + i);
    }

    printf("\n\n");

    my_allocated_mem_ptr = (int*)realloc(my_allocated_mem_ptr, (number_count + 2) * sizeof(int));
    printf("Showing the values 0 through 5 for a total of 6 integers for this resized block of memory\n");

    for (int i = 0; i < number_count + 2; i++) {
        if (i == number_count || i == number_count + 1) {
            *(my_allocated_mem_ptr + i) = i;
        }
        printf("Value in realloc'd block: %d\n", *(my_allocated_mem_ptr + i));
    }

    printf("\n\n");

    free(my_allocated_mem_ptr);
    free(my_other_allocated_mem_ptr);
    return 0;
}