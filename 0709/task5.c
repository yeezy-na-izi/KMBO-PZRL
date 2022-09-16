#include <stdio.h>


int main() {
    float kmh;
    float ms;

    printf("Please enter km/h value: ");
    scanf("%f", &kmh);

    ms = kmh / 3.6;

    printf("m/s value: %f\n", ms);
    return 0;
}