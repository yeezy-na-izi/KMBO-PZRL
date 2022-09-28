#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


float get_float_number(int min, int max, int accuracy) {
    float number;
    int min_int = min * pow(10, accuracy);
    int max_int = max * pow(10, accuracy);
    int number_int = rand() % (max_int - min_int + 1) + min_int;
    number = (float) number_int / pow(10, accuracy);
    return number;
}


int main() {
    int n;
    int m;
    int a;
    int b;


    printf("Please enter n: ");
    scanf("%d", &n);
    printf("Please enter m: ");
    scanf("%d", &m);
    printf("Please enter a: ");
    scanf("%d", &a);
    printf("Please enter b: ");
    scanf("%d", &b);

    float max_number = a;
    float min_number = b;
    float sum_number = 0.0;
    float number;

    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        number = get_float_number(a, b, m);
        printf("%f\n", number);
        if (number > max_number) {
            max_number = number;
        }
        if (number < min_number) {
            min_number = number;
        }
        sum_number += number;
    }
    printf("\n");
    printf("Max number: %f\n", max_number);
    printf("Min number: %f\n", min_number);
    printf("Avg number: %f\n", sum_number / n);
}