#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
    int count = 4;
    int* my_ptr = (int*)malloc(count * sizeof(int));

    // 1. Simple pointer addition - notice how the address printed in the console are not incremented by 1 but by the total 
    for (int i = 0; i < count; i++) {
        printf("'my_ptr' address: %p\n", my_ptr + i);
    }

    int my_initial = 5;
    for (int i = 0; i < count; i++) {
        
    }



    return 0;
}