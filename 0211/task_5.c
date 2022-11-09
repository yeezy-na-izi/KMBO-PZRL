// func for reverse string
#include <stdio.h>
#include <string.h>


int reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
    return 0;
}


int main() {
    char str[20];
    memset(str, '\0', 20);
    printf("Enter string: ");
    scanf("%s", str);
    reverse(str);
    printf("%s", str);
    return 0;
}