// calculate square and perimert of triangle by 3 side


#include <stdio.h>
#include <math.h>


int main() {
    float a;
    float b;
    float c;
    float p;
    float s;

    printf("Please enter a value: ");
    scanf("%f", &a);
    printf("Please enter b value: ");
    scanf("%f", &b);
    printf("Please enter c value: ");
    scanf("%f", &c);

    p = (a + b + c);
    s = (p / 2) * ((p / 2) - a) * ((p / 2) - b) * ((p / 2) - c);
    s = sqrt(s);

    printf("Square: %.4f\n", s);
    printf("Perimeter: %.4f\n", p);
    return 0;
}