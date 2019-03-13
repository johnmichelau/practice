#include <iostream>

using namespace std;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)

    int maxSeq = 0;
    int currSeq = 0;
    bool isSeqStarted = false;

    for (unsigned int i = 0; i < sizeof(N) * 8; i++) {
        bool isOne = N & (1 << i);
        cout << "Position " << i << ": " << isOne << "; currSeq: " << currSeq << "; maxSeq: " << maxSeq << endl;
        if (isOne) {
            if (currSeq > maxSeq) {
                maxSeq = currSeq;
            }

            currSeq = 0;
            isSeqStarted = true;
        } else if (isSeqStarted) {
            currSeq++;
        }
    }

    return maxSeq;
}

int main() {

    cout << "Enter a positive integer: ";
    int input;
    cin >> input;
    int output = solution(input);
    cout << "Binary gap for " << input << ": " << output << endl;

    return 0;
}