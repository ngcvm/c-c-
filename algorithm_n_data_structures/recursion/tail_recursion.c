#include <stdio.h>

void fun(int n) {
    if (n > 0) {
        printf("%d ", n);
        fun(n - 1);
    }
}

int main (int argc, char* argv[]) {
    int n = 3;
    fun(n);
    
    return 1;
}
