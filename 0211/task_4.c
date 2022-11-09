#include <stdio.h>
#include <string.h>


int main() {
    char str[20];
    memset(str, '\0', 20);
    printf("Enter string: ");
    scanf("%s", str);
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    printf("%s", str);
    return 0;
}