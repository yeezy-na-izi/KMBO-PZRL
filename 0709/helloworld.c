#include <stdio.h>


int main() {
    int x;
    float y;
    char z;

    printf("Please enter int value: ");
    scanf("%d", &x);
    printf("Please enter float value: ");
    scanf("%f", &y);
    printf("Please enter char value: ");
    scanf(" %c", &z);

    printf("x - int value: %d, size: %lu\n", x, sizeof(x) * 8);
    printf("y - float value: %f, size: %lu\n", y, sizeof(y) * 8);
    printf("z - char value: %c, size: %lu\n", z, sizeof(z) * 8);
    return 0;
}
