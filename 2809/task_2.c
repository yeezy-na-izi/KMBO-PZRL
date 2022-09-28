#include <stdio.h>


int is_simple(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}


int main() {
    int n;

    printf("Please enter n: ");
    scanf("%d", &n);

    for (int i = 2; i <= n; ++i) {
        if (is_simple(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}