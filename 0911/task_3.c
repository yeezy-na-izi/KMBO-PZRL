// check count substring in string
#include <stdio.h>
#include <string.h>


int main() {
    char *str = NULL;
    char *substr = NULL;
    size_t size;
    printf("Enter string: ");
    getline(&str, &size, stdin);
    printf("Enter substring: ");
    getline(&substr, &size, stdin);

    int len_str = strlen(str);
    int len_substr = strlen(substr);
    len_str--;
    len_substr--;
    int count = 0;

    for (int i = 0; i < (len_str - len_substr); i++) {
        int is_substr = 1;
        for (int j = 0; j < len_substr; j++) {
            if (str[i + j] != substr[j]) {
                is_substr = 0;
                break;
            }
        }
        if (is_substr) {
            count++;
        }
    }
    printf("Count: %d", count);
    return 0;
}