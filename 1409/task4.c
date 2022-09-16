// calculate m = (n * p * (1 + p)^y) / (12 * ((1 + p)^y – 1)),

#include <stdio.h>
#include <math.h>


int main() {
    float n;
    float p;
    float y;
    float m;
    float s;

    printf("Please enter n value: ");
    scanf("%f", &n);
    printf("Please enter p value: ");
    scanf("%f", &p);
    printf("Please enter y value: ");
    scanf("%f", &y);

    m = (n * p * pow((1 + p), y)) / (12 * (pow((1 + p), y) - 1));
    s = m * 12 * y;

    printf("Mth payment value: %010.2f\n", m);
    printf("All payment value: %010.2f", s);
    return 0;
}