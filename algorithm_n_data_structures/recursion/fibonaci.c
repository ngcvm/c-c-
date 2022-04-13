#include <iostream>
#include <algorithm>
using namespace std;

int fibonaci_using_recursive(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonaci_using_recursive(n - 2) + fibonaci_using_recursive(n - 1);
    }
}

int fibonaci_using_recursive_with_memorize (int n) {
    static int* memorize_arr;
    memorize_arr = (int*)malloc(sizeof(int) * n);

    if (n <= 1) {
        memorize_arr[n] = n;
        return n;
    } else {
        if (memorize_arr[n - 2] == -1) {
            memorize_arr[n - 2] = fibonaci_using_recursive_with_memorize(n - 2);
        }
        if (memorize_arr[n - 1] == -1) {
            memorize_arr[n - 1] = fibonaci_using_recursive_with_memorize(n - 1);
        }
        memorize_arr[n] = memorize_arr[n - 2] + memorize_arr[n - 1];
        return memorize_arr[n - 2] + memorize_arr[n -1];
    }
}

int fibonaci_using_loop (int n) {
    if (n <= 1) {
        return n;
    } else {
        int s;
        int t0 = 0, t1 = 1;
        for (int i = 2; i <= n; i++) {
            s = t0 + t1;
            t0 = t1;
            t1 = s;
        } 

        return s;
    }
}

int main (int argc, char* argv[]) {
    cout << "Fibonaci of nth number using recursive: " << fibonaci_using_recursive(15) << endl;
    cout << "Fibonaci of nth number using recursive with memorize: " << fibonaci_using_recursive_with_memorize(15) << endl;
    cout << "Fibonaci of nth number using loop: " << fibonaci_using_loop(15) << endl;

    return EXIT_SUCCESS;
}