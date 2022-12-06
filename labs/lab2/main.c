#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculator(char *str) {
    char *num1 = (char *) malloc(sizeof(char));
    char *num2 = (char *) malloc(sizeof(char));
    char op[1];
    int flag = 0;
    int num1_int = 0;
    int num2_int = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
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

    flag = 0;
    if (num1[0] == '0' && num2[0] == '0') {
        flag = 0;

    } else if (num2[0] == '0' && num2[1] == 'x' && num1[0] == '0' && num1[1] == 'x') {
        flag = 1;

    } else if (num1[0] == '1' && num2[0] == '1') {
        flag = 2;

    } else {
        return 1;
    }


    return 0;
}


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