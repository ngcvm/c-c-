#include <stdio.h>

int fun (int);

int main (int argc, char* argv[]) {
    int n = 91;
    int result = fun(n);
    printf("%d\n", result);
    return 1;
}
 
int fun (int n) {
    if (n > 100) {
        return (n - 10);
    } else {
        return fun (fun (n + 11));
    }
}
