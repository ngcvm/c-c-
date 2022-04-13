#include <stdio.h>

int power_using_recursive(int, int);
int power_using_recursive_optimized(int, int);
int power_using_loop(int, int);

int main (int argc, char* argv[]) {
    int n = 10;
    int m = 2;
    printf("Using recursive %d^%d = %d\n", m, n, power_using_recursive(m, n));
    printf("Using recursive (optimized) %d^%d = %d\n", m, n, power_using_recursive(m, n));
    printf("Using loop %d^%d = %d\n", m, n, power_using_loop(m, n));

    return 1;
}

int power_using_recursive (int m, int n) {
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else {
        return power_using_recursive(m, n - 1) * m;
    }
}

int power_using_recursive_optimized (int m, int n) {
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        return power_using_recursive_optimized(m * m, n/2);
    } else {
        return m * power_using_recursive_optimized(m * m, (n - 1)/2);
    }
}

int power_using_loop (int m, int n) {
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= m;
        }
        return result;
    }
}