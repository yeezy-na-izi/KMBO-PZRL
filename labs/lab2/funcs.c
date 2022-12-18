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
    int sign = 1;
    if (num < 0) {
        sign = -1;
        printf("-");
    }

    switch (flag) {
        case 0:
            result = to_hex(num * sign);
            len = strlen(result);
            if (len) {
                printf("0x%s (%d)\n", result, num);
            } else {
                printf("0x0 0\n");
            }
            break;
        case 1:
            result = to_oct(num * sign);
            len = strlen(result);
            if (len) {
                printf("0%s (%d)\n", result, num);
            } else {
                printf("00 0\n");
            }
            break;
        case 2:
            result = to_bin(num * sign);
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
    int i = 0;
    if (str[0] == '-') {
        i = 1;
    }
    if (str[i] == '0' && str[i + 1] == 'x') {
        return 0; // hex
    } else if (str[i] == '0') {
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
    char number[128];
    memset(number, 0, sizeof(number));
    for (int i = 1; i < strlen(str); i++) {
        number[strlen(number)] = str[i];
    }
    int flag = check_system(str);
    int num = convert(number, flag);
    print(~num, flag);
    return 0;
}

int for_two_numbers(char *str) {
    char number1[128];
    char number2[128];
    memset(number1, 0, sizeof(number1));
    memset(number2, 0, sizeof(number2));
    char op;
    int flag = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) {
            continue;
        }
        if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '&' || str[i] == '|' ||
             str[i] == '^') && flag == 1) {
            op = str[i];
            flag = 2;
            continue;
        }
        if (flag == 0 || flag == 1) {
            flag = 1;
            number1[strlen(number1)] = str[i];
        } else {
            number2[strlen(number2)] = str[i];
        }
    }
    int flag1 = check_system(number1);
    int flag2 = check_system(number2);
    if (flag1 != flag2) {
        return 1;
    }
    int num1 = convert(number1, flag1);
    int num2 = convert(number2, flag2);
    int result = operation(num1, num2, op);
    print(result, flag1);
    return 0;
}

int calculator(char *str) {
    if (str[0] == '~') {
        return for_one_number(str);
    } else {
        return for_two_numbers(str);
    }
}