#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int solution(vector<int> &A) {
    vector<bool> isFound(A.size() + 1, false);

    for (unsigned int i = 0; i < A.size(); i++) {
        if (A[i] > 0 && A[i] < isFound.size()) {
            cout << "Marking " << A[i] << endl;
            isFound[A[i]] = true;
        } else {
            cout << "Ignoring " << A[i] << endl;
        }
    }

    // Iterate starting with 1, because 0 isn't a positive integer.
    for (unsigned int i = 1; i < isFound.size(); i++) {
        if (isFound[i] == false) {
            return i;
        }
    }

    // The numbers are all contiguous, so choose the next largest.
    return isFound.size();
}

int main() {

    vector<int> input = {0, 2, 3};//{0, 1, 77, 0, 12, 2, 34, 34, 123, 13, 4, 123};
    int output = solution(input);
    cout << "Missing integer: " << output << endl;

    return 0;
}