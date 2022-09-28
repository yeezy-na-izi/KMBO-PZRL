#include <stdio.h>


int main() {
    int n;
    int count = 0;

    printf("Please enter n: ");
    scanf("%d", &n);

    while (n > 0) {
        if (n % 2 == 1) {
            count++;
        }
        n /= 2;
    }
    printf("%d\n", count);
    return 0;
}