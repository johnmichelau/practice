//
// Created by John Michelau on 2019-03-13.
//

#include <iostream>
#include <cstdint>

using namespace std;

bool getBit(uint8_t num, int i) {

    return ((1 << i) & num) > 0;
}

int setBit(uint8_t num, int i) {

    return (1 << i) | num;
}

int clearBit(uint8_t num, int i) {

    return ~(1 << i) & num;
}

int clearBitsLeft(uint8_t num, int i) {

    int numBits = sizeof(uint8_t) * 8 - i;
    int mask = ~0 >> numBits;

    return num & mask;
}

int clearBitsRight(uint8_t num, int i) {

    int mask = UINT8_MAX << (i + 1);

    return num & mask;
}

int updateBit(uint8_t num, int i, bool value) {

    if (value)
        return setBit(num, i);
    else
        return clearBit(num, i);
}

int main() {

    cout << "getBit" << endl;
    cout << getBit(1, 0) << endl;
    cout << getBit(2, 0) << endl;
    cout << getBit(3, 0) << endl;
    cout << getBit(2, 1) << endl;

    cout << "setBit" << endl;
    cout << setBit(0, 0) << endl;
    cout << setBit(0, 1) << endl;
    cout << setBit(0, 2) << endl;
    cout << setBit(0, 3) << endl;

    cout << "clearBit" << endl;
    cout << clearBit(1, 0) << endl;
    cout << clearBit(1, 1) << endl;
    cout << clearBit(2, 0) << endl;
    cout << clearBit(2, 1) << endl;
    cout << clearBit(3, 0) << endl;
    cout << clearBit(3, 1) << endl;

    cout << "clearBitsLeft" << endl;
    cout << clearBitsLeft(UINT8_MAX, 0) << endl;
    cout << clearBitsLeft(UINT8_MAX, 1) << endl;
    cout << clearBitsLeft(UINT8_MAX, 2) << endl;
    cout << clearBitsLeft(UINT8_MAX, 3) << endl;
    cout << clearBitsLeft(UINT8_MAX, 4) << endl;
    cout << clearBitsLeft(UINT8_MAX, 5) << endl;
    cout << clearBitsLeft(UINT8_MAX, 6) << endl;
    cout << clearBitsLeft(UINT8_MAX, 7) << endl;

    cout << "clearBitsRight" << endl;
    cout << clearBitsRight(1, 0) << endl;
    cout << clearBitsRight(2, 0) << endl;
    cout << clearBitsRight(7, 1) << endl;
    cout << clearBitsRight(UINT8_MAX, 0) << endl;
    cout << clearBitsRight(UINT8_MAX, 1) << endl;
    cout << clearBitsRight(UINT8_MAX, 2) << endl;
    cout << clearBitsRight(UINT8_MAX, 3) << endl;
    cout << clearBitsRight(UINT8_MAX, 4) << endl;
    cout << clearBitsRight(UINT8_MAX, 5) << endl;
    cout << clearBitsRight(UINT8_MAX, 6) << endl;
    cout << clearBitsRight(UINT8_MAX, 7) << endl;

    cout << "updateBit" << endl;
    cout << updateBit(1, 0, 0) << endl;
    cout << updateBit(1, 1, 0) << endl;
    cout << updateBit(2, 0, 0) << endl;
    cout << updateBit(2, 1, 0) << endl;
    cout << updateBit(3, 0, 0) << endl;
    cout << updateBit(3, 1, 0) << endl;
    cout << updateBit(0, 0, 1) << endl;
    cout << updateBit(0, 1, 1) << endl;
    cout << updateBit(0, 2, 1) << endl;
    cout << updateBit(0, 3, 1) << endl;
}
