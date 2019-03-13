//
// Created by John Michelau on 2019-01-22.
//

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

void print(vector<int> &v) {
    for (auto value : v) {
        cout << value << " ";
    }

    cout << endl;
}

void merge(vector<int> &v, vector<int> &aux, size_t lo, size_t mid, size_t hi) {

    for (size_t k = lo; k <= hi; k++) {
        aux[k] = v[k];
    }

    size_t i = lo;
    size_t j = mid + 1;

    for (size_t k = lo; k <= hi; k++) {

        if (i > mid) {
            v[k] = aux[j++];
        } else if (j > hi) {
            v[k] = aux[i++];
        } else if (aux[i] <= aux[j]) {
            v[k] = aux[i++];
        } else {
            v[k] = aux[j++];
        }
    }
}

void sort(vector<int> &v, vector<int> &aux, size_t lo, size_t hi) {

    if (lo >= hi) {
        return;
    }

    size_t mid = lo + ((hi - lo) / 2);

    sort(v, aux, lo, mid);
    sort(v, aux, mid + 1, hi);

    merge(v, aux, lo, mid, hi);
}

int main() {

    vector<int> v = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    vector<int> aux(v.size());

    print(v);

    sort(v, aux, 0, v.size() - 1);

    print(v);
}