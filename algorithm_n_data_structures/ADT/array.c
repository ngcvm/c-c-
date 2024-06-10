#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("All elements of the array:\n");
    for (int i = 0; i < arr.length; i++) {
        printf("%d\n", arr.A[i]);
    }
}

int func1()
{
    struct Array arr;
    int n, i;
    printf("Enter the size of an array\t");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int));
    arr.length = 0;

    // Fill the array by a certain number of numbers.
    printf("Enter number of numbers\t");
    scanf("%d", &n);
    printf("Enter all elements\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr.A[i]);
    }
    // Update the length of the array
    arr.length = n;

    Display(arr);
    return 0;
}

int func2()
{
    // Another way to initialize the struct
    struct Array arr = {{2,3,4,5,6},20,5};
    Display(arr);
    return 0;
}

int main() 
{
    // func1();
    func2();
    return 0;
}

