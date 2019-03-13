#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

void rotateNinety(Matrix& input, Matrix& output, int N) {

    for (int x = 0; x < N; x++) {

        //int newY = N - x - 1;
        int newY = x;

        for (int y = 0; y < N; y++) {

            //int newX = y;
            int newX = N - y - 1;

            output[newX][newY] = input[x][y];
        }
    }
}

void printArr(Matrix& matrix, int N) {

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << matrix[x][y] << " ";
        }

        cout << endl;
    }

    cout << endl;
}

int main() {
    const int N = 3;

    Matrix input = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    printArr(input, N);

    Matrix output(N, vector<int>(N, 0));
    rotateNinety(input, output, N);
    printArr(output, N);
}