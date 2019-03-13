#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &myVector) {

    sort(myVector.begin(), myVector.end());

    int last = 0;
    bool hasLast = false;
    int count = 0;
    for (int num : myVector) {
        cout << num << endl;

        if (!hasLast || num != last) {
            count++;
            last = num;
            hasLast = true;
        }
    }

    return count;
}

int main() {

    vector<int> input = {0, 1, 77, 0, 12, 2, 34, 34, 123, 13, 4, 123};
    int output = solution(input);
    cout << "Num distinct: " << output << endl;

    return 0;
}