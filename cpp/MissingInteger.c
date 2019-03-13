#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

int solution(int A[], int N) {
    bool isFound[N + 1];
    memset(isFound, 0, sizeof(bool) * (N + 1));

    for (unsigned int i = 0; i < N + 1; i++) {
        printf("isFound[%u]=%u\n", i, isFound[i]);
    }

    for (unsigned int i = 0; i < N; i++) {
        if (A[i] > 0 && A[i] < N + 1) {
            printf("Marking %d\n", A[i]);
            isFound[A[i]] = true;
        } else {
            printf("Ignoring %d\n", A[i]);
        }
    }

    // Iterate starting with 1, because 0 isn't a positive integer.
    for (unsigned int i = 1; i < N + 1; i++) {
        printf("isFound[%u]=%u\n", i, isFound[i]);
        if (isFound[i] == false) {
            return i;
        }
    }

    // The numbers are all contiguous, so choose the next largest.
    return N + 1;
}

int main() {

    int input[] = {0, 2, 3};//{0, 1, 77, 0, 12, 2, 34, 34, 123, 13, 4, 123};
    int output = solution(input, 3);
    printf("Missing integer: %d\n", output);

    return 0;
}