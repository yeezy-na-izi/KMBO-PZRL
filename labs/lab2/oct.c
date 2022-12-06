#include "oct.h"
#include <string.h>
#include <stdlib.h>


int from_oct(char *number) {
    int result = 0;
    for (int i = 1; i < strlen(number); i++) {
        if (number[i] >= '0' && number[i] <= '7') {
            result = result * 8 + (number[i] - '0');
        }
    }
    return result;
}

char *to_oct(int number) {
    char *result = (char *) malloc(sizeof(char));
    int flag = 0;
    while (number > 0) {
        int digit = number % 8;
        if (digit >= 0 && digit <= 7) {
            result = (char *) realloc(result, (strlen(result) + 1) * sizeof(char));
            result[strlen(result)] = digit + '0';
        }
        number /= 8;
        flag = 1;
    }
    if (flag == 0) {
        result = (char *) realloc(result, (strlen(result) + 2) * sizeof(char));
        result[strlen(result) - 1] = '0';
        result[strlen(result)] = '0';
    }
    char *result_reversed = (char *) malloc(sizeof(char));
    for (int i = strlen(result) - 1; i >= 0; i--) {
        result_reversed = (char *) realloc(result_reversed, (strlen(result_reversed) + 1) * sizeof(char));
        result_reversed[strlen(result_reversed)] = result[i];
    }
    free(result);
    return result_reversed;
}