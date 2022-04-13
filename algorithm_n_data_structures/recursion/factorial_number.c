#include <iostream>
using namespace std;

int factorial_using_recursive(int);
int factorial_using_loop(int);

int main (int argc, char* argv[]) {
    int n = 5;
    cout << "Factorial using recursive of " << n << " is: " << factorial_using_recursive(n) << endl;
    cout << "Factorial using loop of " << n << " is: " << factorial_using_loop(n) << endl;

    return EXIT_SUCCESS;
}

int factorial_using_recursive (int n) {
    if (n < 0) {
        return 0;
    } else if (n == 0 || n == 1) {
        return 1;
    } else {
        return factorial_using_recursive(n - 1) * n;
    }
}

int factorial_using_loop (int n) {
    if (n < 0) {
        return 0;
    } else if (n == 0 || n == 1) {
        return 1;
    } else {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }
}