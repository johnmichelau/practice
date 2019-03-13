#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char* compress(char* s) {

    size_t len = strlen(s);

    if (len <= 1) {
        return s;
    }

    char* o = malloc(len + 1);

    int j = 0;
    int count = 1;

    for (int i = 1; i < len; i++) {

        if (s[i] == s[i-1]) {
            count++;
        } else {

            if ((len - (j + 1)) < 1) {
                return s;
            }
            o[j++] = s[i-1];

            j += snprintf(&(o[j]), len - j, "%d", count);

            count = 1;
        }
    }

    o[j] = '\0';

    return o;
}


int main() {

    printf("Enter a string to compress: ");
    char input[65535];
    fscanf(stdin, "%s", input);
    char* output = compress(input);
    printf("Result: %s\n", output);

    return 0;
}