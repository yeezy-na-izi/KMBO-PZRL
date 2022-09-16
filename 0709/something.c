// swap value of to variables

#include <stdio.h>


int main() {
    int x;
    int y;

    printf("Please enter x value: ");
    scanf("%d", &x);
    printf("Please enter y value: ");
    scanf(" %d", &y);

    x += y;
    y = x - y;
    x -= y;

    printf("x value: %.2i\n", x);
    printf("y value: %i", y);
    return 0;
}