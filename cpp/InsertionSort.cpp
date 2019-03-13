//
// Created by John Michelau on 2019-01-22.
//

#include <iostream>
#include <cstddef>

using namespace std;

void insert(int value, int sortedArr[], int i) {

    sortedArr[i] = value;

    for (int j = i - 1; j >= 0; j--) {

        if (value < sortedArr[j]) {
            sortedArr[j+1] = sortedArr[j];
            sortedArr[j] = value;
        }

    }
}

void insertionSort(const int arr[], int sortedArr[], int N) {

    for (int i = 0; i < N; i++) {
        int value = arr[i];

        insert(value, sortedArr, i);
    }
}

void printArr(int arr[], int N) {
    for (auto i = 0; i < N; i++) {
        cout << +arr[i] << " ";
    }

    cout << endl;
}

int main() {
    const int N = 10;
    int arr[N] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    //int arr[N] = {9,8,7,6,5,4,3,2,1,0};

    int sortedArr[N] = {0};

    printArr(arr, N);

    insertionSort(arr, sortedArr, N);

    printArr(sortedArr, N);
}