#include <stdio.h>

int main() {
    float celsium;
    float fahrenheit;

    printf("Please enter celsium value: ");
    scanf("%f", &celsium);

    fahrenheit = celsium * 1.8 + 32;

    printf("Fahrenheit value: %f\n", fahrenheit);
    return 0;
}