// input string unknown length, output sorted string

#include <stdio.h>
#include <string.h>


void sort(char *str, int len) {
    len--;
    char temp;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (str[i] < str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char *str;
    size_t size;

    printf("Enter string: ");
    getline(&str, &size, stdin);

    int len = strlen(str);
    sort(str, len);

    puts(str);
    return 0;
}


