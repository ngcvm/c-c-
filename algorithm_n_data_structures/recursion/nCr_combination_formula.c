#include <iostream>
using namespace std;

int nCr (int, int);

int nCr_recursive (int, int);

int factorial (int);

int main (int argc, char* argv[]) {
    cout << "nCr: " << nCr(5, 3) << endl;
    cout << "nCr using recursive: " << nCr_recursive(5, 3) << endl;
    return EXIT_SUCCESS;
}

int factorial (int n) {
    if (n == 0) {
        return 1;
    } else {
        return factorial(n - 1) * n;
    }
}

// Formula: nCr = n! / (r! * (n - r)!)

int nCr (int n, int r) {
    int t1, t2, t3;
    t1 = factorial(n);
    t2 = factorial(r);
    t3 = factorial(n - r);

    return t1 / (t2 * t3);
}

// See "Pascal Triangle" for more information.

int nCr_recursive (int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    } else {
        return nCr_recursive(n - 1, r - 1) + nCr_recursive(n - 1, r); 
    }
}