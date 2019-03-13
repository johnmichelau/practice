#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int solution(char *S) {

    unsigned long nestLevel = 0;

    for (unsigned long i = 0; S[i] != '\0'; i++) {
        switch (S[i]) {
            case '(':
                nestLevel++;
                break;
            case ')':
                if (nestLevel <= 0) {
                    return 0;
                }
                nestLevel--;
                break;
            default:
                fprintf(stderr, "Not a valid char: %c\n", S[i]);
                return 0;
        }
    }

    return nestLevel == 0 ? 1 : 0;
}

int main() {

    printf("Enter a string of parens: ");
    char input[65535];
    fscanf(stdin, "%s", input);
    int output = solution(input);
    printf("Result: %d\n", output);

    return 0;
}