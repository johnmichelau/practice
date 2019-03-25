//
// Created by John Michelau on 2019-03-24.
//

#include <iostream>
#include <fstream>
#include <cstdint>

using namespace std;

// Complete the flippingBits function below.
long flippingBits(long n) {

    auto un = (uint32_t) n;
    un = ~un;

    return un;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = flippingBits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
