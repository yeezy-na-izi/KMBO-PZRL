#include <stdio.h>
#include <string.h>

char *_strremove(char *str, const char ch) {
    char *p = str;
    while (*p) {
        if (*p == ch) {
            memmove(p, p + 1, strlen(p));
        } else {
            p++;
        }
    }
    return str;
}

int _strcountchar(const char *str, const char ch) {
    if (str == NULL) {
        return -1;
    }
    int count = 0;
    int str_len = strlen(str);
    int cur_index = strchr(str, ch) - &str[0];
    while (cur_index < str_len && cur_index >= 0) {
        count++;
        cur_index = strchr(&str[cur_index + 1], ch) - &str[0];
    }
    if (count == 0) {
        return -1;
    }
    return count;
}

char *_strdelspaces(char *str) {
    int str_len = strlen(str);
    for (int i = 0; i < str_len; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            memmove(&str[i], &str[i + 1], str_len - i);
            i--;
            str_len--;
        }
    }

    return str;
}


int main() {
    printf("Enter string: ");
    char *str = NULL;
    size_t size;
    getline(&str, &size, stdin);
    printf("Enter char: ");
    char ch;
    scanf("%c", &ch);
    int count = _strcountchar(str, ch);
    printf("Count: %d\n", count);
    return 0;
}