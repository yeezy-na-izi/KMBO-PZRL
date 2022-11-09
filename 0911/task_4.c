// input string delete from string all not letter symbol
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *str = NULL;
    char *output = NULL;
    size_t size;
    printf("Enter your text: ");
    getline(&str, &size, stdin);
    int len = strlen(str);
    output = (char *) malloc(len * sizeof(char));
    memset(output, '\0', len);
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            output[j] = str[i];
            j++;
        }
    }
    puts(output);
    return 0;
}