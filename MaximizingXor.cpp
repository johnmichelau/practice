//
// Created by John Michelau on 2019-03-13.
//

#include <iostream>
#include <fstream>

using namespace std;

// Complete the maximizingXor function below.
int maximizingXor(int l, int r) {
    int max = 0;

    for (int i = l; i <=r; i++) {
        for (int j = l; j <= r; j++) {
            int val = i ^ j;
            if (val > max) {
                max = val;
            }
        }
    }

    return max;
}

int main()
{
    cout << maximizingXor(10, 15) << endl;

    return 0;
}
