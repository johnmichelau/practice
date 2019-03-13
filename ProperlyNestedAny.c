#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int solution(char *S) {
    unsigned int sLength = strlen(S);
    char expectedStack[sLength];
    char* expectedStackTop = expectedStack;

    for (unsigned int i = 0; i < sLength; i++) {
        char c = S[i];
        switch (c) {
            case '(':
                expectedStackTop++;
                *expectedStackTop = ')';
                break;
            case '[':
                expectedStackTop++;
                *expectedStackTop = ']';
                break;
            case '{':
                expectedStackTop++;
                *expectedStackTop = '}';
                break;
            default:
                if (expectedStack != expectedStackTop) {
                    char expectedC = *expectedStackTop;
                    expectedStackTop--;

                    if (c != expectedC) {
                        return 0;
                    }
                } else {
                    return 0;
                }
        }
    }

    return expectedStack == expectedStackTop ? 1 : 0;
}

int main() {

    printf("Enter a string of parens/brackets: ");
    char input[65535];
    fscanf(stdin, "%s", input);
    int output = solution(input);
    printf("Result: %d\n", output);

    return 0;
}