#include <stdio.h>


int main() {
    int x;
    int y;

    printf("Please enter x value: ");
    scanf("%d", &x);
    printf("Please enter y value: ");
    scanf("%d", &y);

    x += y;
    y = x - y;
    x -= y;

    printf("x value: %d\n", x);
    printf("y value: %d\n", y);
    return 0;
}