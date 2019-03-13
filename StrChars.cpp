//
// Created by John Michelau on 2019-01-25.
// This was one of my interview questions on 2019-01-23.
//

#include <iostream>

using namespace std;

const char *strcharsSlow(const char *str, const char *chars) {

    // This is O(N^2) time and O(1) space.

    // Iterate over each char in str, then iterate over each char in chars in an inner loop.
    // Quit when we find a match.

    const char *strPtr = str;
    while (*strPtr != '\0') {

        const char *charsPtr = chars;
        while (*charsPtr != '\0') {

            if (*strPtr == *charsPtr) {
                return strPtr;
            }

            charsPtr++;
        }

        strPtr++;
    }

    return nullptr;
}

const char *strcharsFast(const char *str, const char *chars) {

    // This is O(N + M) time and O(1) space, but the space is still more than strcharsSlow.
    // We've traded space for time.

    // Keep an array of pointers to char positions in str.  We will index this by char.
    const char *strCharPos[256] = {nullptr};

    // Load the array of pointers.  Only store the first instance of each char.
    const char *strPtr = str;
    while (*strPtr != '\0') {

        if (strCharPos[*strPtr] == nullptr) {
            strCharPos[*strPtr] = strPtr;
        }

        strPtr++;
    }

    // Now iterate the chars we want to find.  Don't quit when we find one, because we want to
    // find the earliest one.
    const char *charsPtr = chars;
    strPtr = nullptr;
    while (*charsPtr != '\0') {

        if (strCharPos[*charsPtr] != nullptr) {

            if (strPtr == nullptr) {
                strPtr = strCharPos[*charsPtr];
            } else {
                if (strPtr > strCharPos[*charsPtr]) {
                    strPtr = strCharPos[*charsPtr];
                }
            }
        }

        charsPtr++;
    }

    return strPtr;
}

int main() {
    string str;
    cout << "Enter a string to search: ";
    cin >> str;

    string chars;
    cout << "Enter a string of chars: ";
    cin >> chars;

    const char *result = strcharsFast(str.c_str(), chars.c_str());

    if (result == nullptr) {
        cout << "Not found!" << endl;
    } else {
        cout << "Result is " << result << endl;
    }

    return 0;
}