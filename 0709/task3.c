#include <stdio.h>

int main() {
    int x;
    int y;

    printf("Please enter first num: ");
    scanf("%d", &x);
    printf("Please enter second num: ");
    scanf("%d", &y);

    printf("x // y = %d\nx %% y = %d\n", x / y, x % y);
    return 0;
}