#include <stdio.h>
#include <string.h>

int main() {
    char alphabet[26 * 2] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    char Alphabet[26 * 2] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char input[100];
    char output[100];
    memset(input, '\0', 100);
    memset(output, '\0', 100);
    printf("Enter your text: ");
    scanf("%s", input);
    int shift;
    printf("Enter shift: ");
    scanf("%i", &shift);
    shift %= 26;
    for (int i = 0; i < strlen(input); i++) {
        for (int j = 0; j < 26; j++) {
            if (input[i] == alphabet[j]) {
                output[i] = alphabet[j + shift];
                break;
            }
            if (input[i] == Alphabet[j]) {
                output[i] = Alphabet[j + shift];
                break;
            }
        }
    }
    puts(output);
    return 0;
}