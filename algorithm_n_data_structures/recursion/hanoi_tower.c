#include <iostream>
using namespace std;

void TOH (int, int, int, int);

int main (int argc, char* argv[]) {
    TOH(3, 1, 2, 3);
    return EXIT_SUCCESS;
}

void TOH (int n, int A, int B, int C) {
    if (n > 0) {
        TOH (n - 1, A, C, B);
        cout << "Move from " << A << " to " << C << endl;
        TOH (n - 1, B, A, C);
    }
}
