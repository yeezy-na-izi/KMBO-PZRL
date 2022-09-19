#include <stdio.h>
#include <ctype.h>

int main(int argc, char** argv) {
    char str[100];
    int i = 0;
    printf("Enter a string in lower case: ");
    scanf("%s", str);
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
    printf("The string in upper case is: %s\n", str);
    return 0;
}

