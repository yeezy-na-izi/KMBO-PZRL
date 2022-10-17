#include <stdio.h>

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int result = 0;

    while (n > 0) {
        if (n & 1) {
            result++;
        }
        n >>= 1;
    }

    printf("Result %d\n", result);
    return 0;
}