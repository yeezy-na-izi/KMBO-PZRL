#include <stdio.h>

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int result = 1;

    printf("2^%d = %d\n", n, result << n);
    return 0;
}