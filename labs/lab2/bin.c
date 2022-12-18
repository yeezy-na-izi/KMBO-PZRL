#include "bin.h"
#include <string.h>
#include <stdlib.h>

int from_bin(char *number) {
    int result = 0;
    for (int i = 0; i < strlen(number); i++) {
        if (number[i] >= '0' && number[i] <= '1') {
            result = result * 2 + (number[i] - '0');
        }
    }
    return result;
}

char *to_bin(int number) {
    char *result = (char *) malloc(sizeof(char));
    while (number > 0) {
        int digit = number % 2;
        result = (char *) realloc(result, (strlen(result) + 1) * sizeof(char));
        result[strlen(result)] = digit + '0';
        number /= 2;
    }
    char *result_reversed = (char *) malloc(sizeof(char));
    for (int i = strlen(result) - 1; i >= 0; i--) {
        result_reversed = (char *) realloc(result_reversed, (strlen(result_reversed) + 1) * sizeof(char));
        result_reversed[strlen(result_reversed)] = result[i];
    }
    free(result);
    return result_reversed;
}
