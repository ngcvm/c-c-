#include <stdio.h>

void fun(int n) {
    if (n > 0) {
        fun(n - 1);
        printf("%d ", n);
    }
}

int main (int argc, char* argv[]) {
    int n = 3;
    fun(n);
    
    return 1;
}
