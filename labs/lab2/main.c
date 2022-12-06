#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"


int main() {
    char *input;
    size_t input_size = 0;
    getline(&input, &input_size, stdin);
    int checker = calculator(input);
    if (checker == 1) {
        printf("Ошибка: системы счисления не совпадают");
    }

    free(input);

    return 0;
}