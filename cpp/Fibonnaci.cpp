//
// Created by John Michelau on 2019-01-22.
//

#include <iostream>
#include <unordered_map>
#include <iterator>

using namespace std;

long fibonacci(int n, unordered_map<int, long> &solutions) {

    if (n == 0 || n == 1) return n;

    long solution;
    auto it = solutions.find(n);
    if (it == solutions.end()) {
        solution = fibonacci(n - 1, solutions) + fibonacci(n - 2, solutions);
        solutions.insert({n, solution});
    } else {
        solution = it->second;
    }

    return solution;
}

int main() {
    cout << "Enter the n for nth Fibonacci: ";
    string input;
    cin >> input;

    unordered_map<int, long> solutions;
    cout << fibonacci(stoi(input), solutions) << endl;

    return 0;
}