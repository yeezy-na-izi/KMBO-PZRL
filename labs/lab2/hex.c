#include "hex.h"
#include <stdlib.h>
#include <string.h>

int from_hex(char *number) {
    int result = 0;
    int flag = 0;
    for (int i = 0; i < strlen(number); i++) {
        if (number[i] == 'x') {
            flag = 1;
            continue;
        }
        if (flag == 0) {
            continue;
        }
        if (number[i] >= '0' && number[i] <= '9') {
            result = result * 16 + (number[i] - '0');
        } else if (number[i] >= 'a' && number[i] <= 'f') {
            result = result * 16 + (number[i] - 'a' + 10);
        } else if (number[i] >= 'A' && number[i] <= 'F') {
            result = result * 16 + (number[i] - 'A' + 10);
        }
    }
    return result;
}


char *to_hex(int number) {
    char *result = (char *) malloc(sizeof(char));
    int flag = 0;
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
        flag = 1;
    }
    if (flag == 0) {
        result = (char *) realloc(result, (strlen(result) + 1) * sizeof(char));
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