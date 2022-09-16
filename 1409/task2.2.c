// calculate square and perimert of rectangle by 2 side


#include <stdio.h>


int main() {
    float a;
    float b;
    float p;
    float s;

    printf("Please enter a value: ");
    scanf("%f", &a);
    printf("Please enter b value: ");
    scanf("%f", &b);

    p = (a + b) * 2;
    s = a * b;

    printf("Square: %.4f\n", s);
    printf("Perimeter: %.4f", p);
    return 0;
}