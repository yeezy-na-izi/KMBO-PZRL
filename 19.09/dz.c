// make algorithm for sqrt of number, number = float


#include <stdio.h>


int main(int argc, char **argv) {
    float number, result = 1;
    printf("Enter number: ");
    scanf("%f", &number);

    for (int i = 0; i < 100; i++) {
        result = (result + number / result) / 2;
    }

    printf("Result: %f\n", result);
    return 0;
}