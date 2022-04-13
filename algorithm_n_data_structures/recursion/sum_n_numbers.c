#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int sum_using_recursion(int);
int sum_using_loop(int);
int sum_using_formula(int);

int main (int argc, char* argv[]) {
    int n = 100;

    auto start1 = high_resolution_clock::now();
    int result1 = sum_using_recursion(n);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "Result of sum function using recursion: " << result1 << " " << "Time: " << duration1.count() << " (microseconds)" << endl;
    
    auto start2 = high_resolution_clock::now();
    int result2 = sum_using_recursion(n);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Result of sum function using loop: " << result2 << " " << "Time: " << duration2.count() << " (microseconds)" << endl;

    auto start3 = high_resolution_clock::now();
    int result3 = sum_using_recursion(n);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "Result of sum function using formula: " << result3 << " " << "Time: " << duration3.count() << " (microseconds)" << endl;
    return EXIT_SUCCESS;
}

/*
* Using recursion
* Time: O(n)
* Space: O(n)
*/
int sum_using_recursion(int n) {
    if (n > 0) {
        return sum_using_recursion(n - 1) + n;
    }

    return 0;
}

/*
* Using for loop
* Time: O(n)
* Space: O(1)
*/
int sum_using_loop(int n) {
    if (n > 0) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        return sum;
    }

    return 0;
}

/*
* Using formula n*(n - 1)/2
* Time: O(1)
* Space: O(1)
*/
int sum_using_formula(int n) {
    if (n > 0) {
        return (n * (n - 1))/2;
    }

    return 0;
}