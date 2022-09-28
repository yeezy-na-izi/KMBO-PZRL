// get two points and calculate equation


#include <stdio.h>


int main() {
    float x1;
    float y1;
    float x2;
    float y2;
    float k;
    float b;

    printf("Please enter x1 value: ");
    scanf("%f", &x1);
    printf("Please enter y1 value: ");
    scanf("%f", &y1);
    printf("Please enter x2 value: ");
    scanf("%f", &x2);
    printf("Please enter y2 value: ");
    scanf("%f", &y2);

    k = (y2 - y1) / (x2 - x1);
    b = y1 - k * x1;

    printf("First point - (%.2f, %.2f)\n", x1, y1);
    printf("Second point - (%.2f, %.2f)\n", x2, y2);
    printf("Equation: %.2fx + %.2f = y\n", k, b);
    return 0;
}