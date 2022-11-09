#include <stdio.h>
#include <string.h>


int main() {
    char input[100];
    char output[100];
    memset(input, '\0', 100);
    memset(output, '\0', 100);
    printf("Enter your text: ");
    scanf("%s", input);
    char prev_letter = '\0';
    int counter = 0;
    for (int i = 0; i < 100; ++i) {
        if (input[i] == prev_letter) {
            continue;
        }
        prev_letter = input[i];
        output[counter] = input[i];
        counter++;
    }
    puts(output);
    return 0;
}