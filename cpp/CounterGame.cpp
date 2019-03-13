//
// Created by John Michelau on 2019-03-13.
//

#include <iostream>

using namespace std;

#define RICHARD "Richard"
#define LOUISE "Louise"

// Complete the counterGame function below.
string counterGame(long n) {

    bool winner = true;
    unsigned long mask = ~(ULONG_MAX >> 1);

    while (n > 1) {
        if (n == mask) {
            n = n >> 1;
            mask = mask >> 1;
            winner = !winner;
        } else if (n > mask) {
            n = n - mask;
            // Can we safely shift the mask also to save a loop?
            winner = !winner;
        } else /* (n < mask) */ {
            mask = mask >> 1;
        }
    }

    return winner ? RICHARD : LOUISE;
}

int main()
{
    cout << counterGame(6) << endl;
    return 0;
}
