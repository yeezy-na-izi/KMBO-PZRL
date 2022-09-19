// make algorithm for sqrt of number, number = float number get from cmd


#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    float number = atof(argv[1]);
    float result = 1;
    for (int i = 0; i < 100; i++) {
        result = (result + number / result) / 2;
    }
    printf("Result %f", result);
}