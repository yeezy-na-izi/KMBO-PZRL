// calculate square and perimert of circle by radius


#include <stdio.h>


int main() {
    float r;
    float p;
    float s;
    #define PI 3.14159

    printf("Please enter r value: ");
    scanf("%f", &r);

    p = 2.0 * PI * r;
    s = PI * r * r;

    printf("Square: %.4f\n", s);
    printf("Perimeter: %.4f", p);
    return 0;
}