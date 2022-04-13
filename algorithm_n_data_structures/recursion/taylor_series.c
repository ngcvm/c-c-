#include <iostream>
using namespace std;

double taylor_series_using_recursive (int x, int n) {
    static double p = 1, f = 1;
    double r;
    if (n < 0) { 
        return 0;
    } else if (n == 0) {
        return 1;
    } else {
        r = taylor_series_using_recursive(x, n - 1);
        p = p * x;
        f = f * n;

        return r + p/f;
    }
}

double taylor_series_using_iterative (int x, int n) {
    double s = 1;
    int i;
    double num = 1;
    double den = 1;

    for (i = 1; i <= n; i++) {
        num*=x;
        den*=i;
        double r = num / den;
        s += r;
    }
    return s;
}

double taylor_series_using_horner_rule (int x, int n) {
    static double s;
    if (n == 0) {
        return s;
    } else {
        s = 1 + (x*s/n);
        reurn taylor_series_using_horner_rule(x, n - 1);
    }
}

int main (int argc, char* argv[]) {
    // cout << "Solve taylor series using recursive: " << taylor_series_using_recursive(1, 10) << endl;
    cout << "Solve taylor series using iterative: " << taylor_series_using_iterative(1, 10) << endl;

 
    return EXIT_SUCCESS;
}