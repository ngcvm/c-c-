#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    TEA = 10,
    COFFEE = 20,
    BEER = 30,
    JUICE = 40
} Menu;

typedef int a;

a test = 1;

int main()
{
    Menu mario = TEA;
    Menu ngoc = JUICE;

    printf("Mario ordered: %d\n", mario);
    printf("I ordered: %d\n", ngoc);

    printf("%d\n", test);

    return EXIT_SUCCESS;
}
