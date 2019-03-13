//
// Created by John Michelau on 2019-01-22.
//

#include <iostream>
#include <list>

using namespace std;

class HashTable {
public:

    HashTable() = default;

    ~HashTable() {
        for (uint8_t i = 0; i < NUM_BUCKETS; i++) {
            if (table[i] != nullptr) {
                delete table[i];
            }
        }
    }

    void addItem(uint64_t value) {

        uint8_t hash = hashToBucket(value);

        if (table[hash] == nullptr) {
            table[hash] = new list<uint64_t>();
        }

        // Avoid inserting a duplicate.
        for (auto v : *(table[hash])) {
            if (v == value) {
                return;
            }
        }

        table[hash]->push_back(value);
    }

    void removeItem(uint64_t value) {

        uint8_t hash = hashToBucket(value);

        if (table[hash] == nullptr) {
            return;
        }

        table[hash]->remove(value);
    }

    bool hasItem(uint64_t value) {

        uint8_t hash = hashToBucket(value);

        if (table[hash] == nullptr) {
            return false;
        }

        for (auto v : *(table[hash])) {
            if (v == value) {
                return true;
            }
        }

        return false;
    }

    void printBuckets() {

        for (auto i = 0; i < NUM_BUCKETS; i++) {
            cout << "Bucket " << +i << ": ";

            if (table[i] != nullptr) {
                for (auto value : *(table[i])) {
                    cout << +value << " ";
                }
            }

            cout << endl;
        }
    }

private:
    static const uint8_t NUM_BUCKETS = 10;
    list<uint64_t> *table[NUM_BUCKETS] = {nullptr};

    uint8_t hashToBucket(uint64_t value) {
        return (uint8_t) (value % 10);
    }
};

int main() {

    HashTable table;

    table.addItem(1000);
    table.addItem(2000);
    table.addItem(1);
    table.addItem(45667568);
    table.addItem(12312321);
    table.addItem(7);
    table.addItem(2342423424);
    table.addItem(23445766);

    table.printBuckets();
}