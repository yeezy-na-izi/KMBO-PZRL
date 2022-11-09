#include <stdio.h>
#include <string.h>

int main() {
    char str[20];
    memset(str, '\0', 20);
    printf("Enter string: ");
    scanf("%s", str);
    int len = strlen(str);
    int is_palindrome = 1;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            is_palindrome = 0;
            break;
        }
    }
    if (is_palindrome) {
        printf("String is palindrome");
    } else {
        printf("String is not palindrome");
    }
    return 0;
}

