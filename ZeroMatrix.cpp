#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

void printMatrix(Matrix &matrix) {
    for (int col = 0; col < matrix[0].size(); col++) {
        for (int row = 0; row < matrix.size(); row++) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void zeroMatrix(Matrix &matrix) {

    printMatrix(matrix);

    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return;
    }

    bool hasZeroRow = false;
    bool hasZeroCol = false;

    for (int row = 0; row < matrix.size(); row++) {

        for (int col = 0; col < matrix[0].size(); col++) {

            if (matrix[row][col] == 0) {

                if (row == 0) {
                    hasZeroRow = true;
                } else {
                    matrix[row][0] = 0;
                }

                if (col == 0) {
                    hasZeroCol = true;
                } else {
                    matrix[0][col] = 0;
                }
            }
        }
    }

    printMatrix(matrix);

    for (int row = 1; row < matrix.size(); row++) {

        for (int col = 1; col < matrix[0].size(); col++) {

            if (matrix[0][col] == 0 || matrix[row][0] == 0) {

                matrix[row][col] = 0;
            }
        }
    }

    printMatrix(matrix);

    // Handle the first row.
    if (hasZeroRow) {
        for (int col = 0; col < matrix[0].size(); col++) {
            matrix[0][col] = 0;
        }
    }

    // Handle the first column.
    if (hasZeroCol) {
        for (int row = 0; row < matrix.size(); row++) {
            matrix[row][0] = 0;
        }
    }

    printMatrix(matrix);
}

int main() {
    Matrix input = {
            {1, 0, 3},
            {4, 5, 6},
            {7, 8, 9},
            {1, 2, 3}
    };

    zeroMatrix(input);
}