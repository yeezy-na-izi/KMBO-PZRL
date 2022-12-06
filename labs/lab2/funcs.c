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
    switch (flag) {
        case 2:
            printf("%s (%d)\n", to_bin(num), num);
            break;
        case 1:
            printf("%s (%d)\n", to_hex(num), num);
            break;
        case 0:
            printf("%s (%d)\n", to_oct(num), num);
            break;
        default:
            return;

    }
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
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
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

    if (num1[0] == '0' && num2[0] == '0') {
        flag = 0;
        num1_int = from_oct(num1);
        num2_int = from_oct(num2);
    } else if (num2[0] == '0' && num2[1] == 'x' && num1[0] == '0' && num1[1] == 'x') {
        flag = 1;
        num1_int = from_hex(num1);
        num2_int = from_hex(num2);
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