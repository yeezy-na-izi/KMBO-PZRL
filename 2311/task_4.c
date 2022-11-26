#include <stdio.h>
#include <stdlib.h>

int check(char *str) {
    int *stack = (int *) malloc(sizeof(int) * 3);
    int cur_i = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            if (str[i] == '(') {
                stack[i] = 1;
            } else if (str[i] == '[') {
                stack[i] = 2;
            } else {
                stack[i] = 3;
            }
            int *tmp = (int *) realloc(stack, sizeof(int) * (cur_i + 1));
            if (tmp == NULL) {
                return 0;
            }
            stack = tmp;
            cur_i++;
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (str[i] == ')') {
                if (stack[cur_i - 1] != 1) {
                    return 0;
                }
            } else if (str[i] == ']') {
                if (stack[cur_i - 1] != 2) {
                    return 0;
                }
            } else {
                if (stack[cur_i - 1] != 3) {
                    return 0;
                }
            }
            cur_i--;
        }
    }
    return 1;
}


int main() {
    char str[100];
    scanf("%s", str);
    printf("%d\n", check(str));
    return 0;
}