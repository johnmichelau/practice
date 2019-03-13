//
// Created by John Michelau on 2019-01-09.
//

#include <string>
#include <iterator>
#include <iostream>
#include <vector>
#include <sstream>
#include <utility>

using namespace std;

typedef struct Node {
    Node *next = nullptr;
    int data;
} Node;


void printList(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* findTail(Node* head) {
    Node* curr = head;
    Node* tail = nullptr;

    while (curr != nullptr) {
        if (curr->next == nullptr) {
            tail = curr;
        }
        curr = curr->next;
    }

    return tail;
}

Node* partitionList(Node *node, int partition) {

    Node* beforeHead = nullptr;
    Node* beforeTail = nullptr;
    Node* afterHead = nullptr;
    Node* afterTail = nullptr;

    Node* curr = node;

    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = nullptr;

        if (curr->data < partition) {
            if (beforeHead == nullptr) {
                beforeHead = curr;
                beforeTail = curr;
            } else {
                beforeTail->next = curr;
                beforeTail = curr;
            }
        } else {
            if (afterHead == nullptr) {
                afterHead = curr;
                afterTail = curr;
            } else {
                afterTail->next = curr;
                afterTail = curr;
            }
        }

        curr = next;
    }

    if (beforeHead == nullptr) {
        return afterHead;
    }

    beforeTail->next = afterHead;

    return beforeHead;
}

int main() {

    cout << "Enter a sequence of numbers separated by spaces" << endl;
    string input;
    getline(cin, input);
    istringstream inputStream(input);
    istream_iterator<int> begin(inputStream), end;
    vector<int> values(begin, end);
    Node *head = nullptr;
    Node *prev = nullptr;
    for (int value : values) {
        if (head == nullptr) {
            head = new Node();
            head->next = nullptr;
            head->data = value;
            prev = head;
        } else {
            prev->next = new Node();
            prev->next->data = value;
            prev = prev->next;
        }
    }

    printList(head);

    cout << "Enter a partition value" << endl;
    cin >> input;
    int partition = stoi(input, nullptr, 10);

    head = partitionList(head, partition);

    printList(head);
}