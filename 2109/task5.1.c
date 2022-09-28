// print n element of fibonachi

#include <stdio.h>


int main() {
    int n;
    long long a = 0;
    long long b = 1;
    long long c;

    printf("Please enter n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    printf("%lld\n", a);
    return 0;
}