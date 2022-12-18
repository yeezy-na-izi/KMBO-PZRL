#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "hex.h"
#include "oct.h"
#include "bin.h"


int operation(int num1, int num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '&':
            return num1 & num2;
        case '|':
            return num1 | num2;
        case '^':
            return num1 ^ num2;
        default:
            return -1;
    }
}

void print(int num, int flag) {
    char *result;
    int len;
    switch (flag) {
        case 0:
            result = to_hex(num);
            len = strlen(result);
            if (len) {
                printf("0x%s (%d)\n", result, num);
            } else {
                printf("0x0 0\n");
            }
            break;
        case 1:
            result = to_oct(num);
            len = strlen(result);
            if (len) {
                printf("0%s (%d)\n", result, num);
            } else {
                printf("00 0\n");
            }
            break;
        case 2:
            result = to_bin(num);
            len = strlen(result);
            if (len) {
                printf("%s (%d)\n", result, num);
            } else {
                printf("0 0\n");
            }
            break;
        default:
            return;
    }
    free(result);
}

int check_system(char *str) {
    if (str[0] == '0' && str[1] == 'x') {
        return 0; // hex
    } else if (str[0] == '0') {
        return 1; // oct
    } else {
        return 2; // bin
    }
}

int convert(char *str, int flag) {
    switch (flag) {
        case 0:
            return from_hex(str);
        case 1:
            return from_oct(str);
        case 2:
            return from_bin(str);
        default:
            return -1;
    }
}

int for_one_number(char *str) {
    char *number = (char *) malloc(sizeof(char));
    for (int i = 1; i < strlen(str); i++) {
        number = (char *) realloc(number, (strlen(number) + 1) * sizeof(char));
        number[strlen(number) - 1] = str[i];
    }
    number = (char *) realloc(number, (strlen(number) - 1) * sizeof(char));
    int flag = check_system(str);
    int num = convert(number, flag);
    print(~num, flag);
    free(number);
    return 0;
}

int calculator(char *str) {
    char *num1 = (char *) malloc(sizeof(char));
    char *num2 = (char *) malloc(sizeof(char));
    char op[1];
    int flag = 0;
    int num1_int;
    int num2_int;
    int result;

    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) {
            continue;
        }
        if (str[i] == '+' ||
            str[i] == '-' ||
            str[i] == '*' ||
            str[i] == '/' ||
            str[i] == '&' ||
            str[i] == '|' ||
            str[i] == '^'
                ) {
            op[0] = str[i];
            flag = 1;
            continue;
        }
        if (flag == 0) {
            num1 = (char *) realloc(num1, (strlen(num1) + 1) * sizeof(char));
            num1[strlen(num1)] = str[i];
        } else {
            num2 = (char *) realloc(num2, (strlen(num2) + 1) * sizeof(char));
            num2[strlen(num2)] = str[i];
        }
    }
    if (num2[0] == '0' && num2[1] == 'x' && num1[0] == '0' && num1[1] == 'x') {
        flag = 1;
        num1_int = from_hex(num1);
        num2_int = from_hex(num2);
    } else if (num1[0] == '0' && num2[0] == '0') {
        flag = 0;
        num1_int = from_oct(num1);
        num2_int = from_oct(num2);
    } else if (num1[0] == '1' && num2[0] == '1') {
        flag = 2;
        num1_int = from_bin(num1);
        num2_int = from_bin(num2);
    } else {
        return 1;
    }

    free(num1);
    free(num2);

    result = operation(num1_int, num2_int, op[0]);

    print(result, flag);

    return 0;
}