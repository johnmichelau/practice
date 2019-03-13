//
// Created by John Michelau on 2019-03-13.
//

#include <iostream>

using namespace std;

vector<string> split_string(string);

// Complete the xorSequence function below.
// Pattern is (1, x-1, 0, x) starting from x = 1
//  x % 4 == 1, x % 4 == 2, x % 4 == 3, x % 4 == 0
long xorSequence(long l, long r) {

    long sum = 0;

    cout << 0;

    for (long x = l; x <= r; x++) {
        long currArrVal;
        switch (x % 4) {
            case 1:
                currArrVal = 1;
                break;
            case 2:
                currArrVal = x + 1;
                break;
            case 3:
                currArrVal = 0;
                break;
            case 0:
                currArrVal = x;
                break;
            default:
                throw "The mod op didn't work!";
        }
        cout << ", " << currArrVal;

        sum ^= currArrVal;
    }

    cout << endl;

    return sum;
}

int main() {
    cout << xorSequence(10, 12) << endl;
}
