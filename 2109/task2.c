// get 2 numbers and operator and print result

#include <stdio.h>


int main() {
    int x;
    int y;
    char op;

//    if (op == '+') {
//        printf("%d + %d = %d", x, y, x + y);
//    } else if (op == '-') {
//        printf("%d - %d = %d", x, y, x - y);
//    } else if (op == '*') {
//        printf("%d * %d = %d", x, y, x * y);
//    } else if (op == '/') {
//        if (y == 0) {
//            printf("Division by zero");
//        } else {
//            printf("%d / %d = %d", x, y, x / y);
//        }
//    } else if (op == '%') {
//        printf("%d %% %d = %d", x, y, x % y);
//    } else {
//        printf("Unknown operator");
//    }

    while (1) {
        printf("Please enter first num: ");
        scanf("%d", &x);
        printf("Please enter second num: ");
        scanf("%d", &y);
        printf("Please enter operator: ");
        scanf(" %c", &op);
        switch (op) {
            case '+':
                printf("%d + %d = %d", x, y, x + y);
                break;
            case '-':
                printf("%d - %d = %d", x, y, x - y);
                break;
            case '*':
                printf("%d * %d = %d", x, y, x * y);
                break;
            case '/':
                if (y == 0) {
                    printf("Division by zero");
                } else {
                    printf("%d / %d = %d", x, y, x / y);
                }
                break;
            case '%':
                printf("%d %% %d = %d", x, y, x % y);
                break;
            case '0':
                return 0;
            default:
                printf("Unknown operator");
                break;
        }
        printf("\n");
    }
    return 0;
}