#include <stdio.h>

int main() {
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    int n_counts[10] = {0};

    while (number != 0) {
        n_counts[number % 10] += 1;
        number = number / 10;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d: %d\n", i, n_counts[i]);
    }
    return 0;
}