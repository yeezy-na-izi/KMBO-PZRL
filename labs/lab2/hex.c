#include "hex.h"
#include <stdlib.h>
#include <string.h>

int check_hex(char *number) {
    int i = 2;
    if (number[0] == '-') {
        i++;
    }
    for (; i < strlen(number); i++) {
        if ((number[i] >= '0' && number[i] <= '9') ||
            (number[i] >= 'A' && number[i] <= 'F') ||
            (number[i] >= 'a' && number[i] <= 'f')
                ) {
            continue;
        } else {
            return 1;
        }
    }
    return 0;
}

int from_hex(char *number) {
    int result = 0;
    int sign = 1;
    int i = 2;
    if (number[0] == '-') {
        sign = -1;
        i = 3;
    }
    for (; i < strlen(number); i++) {
        if (number[i] >= '0' && number[i] <= '9') {
            result = result * 16 + (number[i] - '0');
        } else if (number[i] >= 'a' && number[i] <= 'f') {
            result = result * 16 + (number[i] - 'a' + 10);
        } else if (number[i] >= 'A' && number[i] <= 'F') {
            result = result * 16 + (number[i] - 'A' + 10);
        }
    }
    return sign * result;
}


char *to_hex(int number) {
    char *result = (char *) malloc(sizeof(char));
    while (number > 0) {
        int digit = number % 16;
        if (digit >= 0 && digit <= 9) {
            result = (char *) realloc(result, (strlen(result) + 1) * sizeof(char));
            result[strlen(result)] = digit + '0';
        } else {
            result = (char *) realloc(result, (strlen(result) + 1) * sizeof(char));
            result[strlen(result)] = digit - 10 + 'A';
        }
        number /= 16;
    }

    char *result_reversed = (char *) malloc(sizeof(char));
    for (int i = strlen(result) - 1; i >= 0; i--) {
        result_reversed = (char *) realloc(result_reversed, (strlen(result_reversed) + 1) * sizeof(char));
        result_reversed[strlen(result_reversed)] = result[i];
    }
    free(result);
    return result_reversed;
}