//
// Created by John Michelau on 2019-01-18.
//
// This class implements breadth-first search on a directed cyclical graph.
//

#include <iostream>
#include <list>
#include <queue>
#include <unordered_set>
#include <cstdint>

using namespace std;

template<class T>

class Vertex {
public:
    explicit Vertex(T value) {
        this->value = value;
    }

    ~Vertex() = default;

    T getValue() {
        return value;
    }

    void addEdge(Vertex<T> *vertex) {
        if (vertex == nullptr) {
            throw "vertex cannot be null";
        }

        adj.push_back(vertex);
    }

    list<Vertex<T> *> getAdj() {
        return adj;
    }

private:
    list<Vertex<T> *> adj;

    T value;
};

Vertex<uint8_t> *findVertexBreadthFirst(Vertex<uint8_t> *startVertex, uint8_t value) {

    if (startVertex == nullptr) {
        throw "startVertex cannot be null";
    }

    queue<Vertex<uint8_t> *> searchQueue;
    unordered_set<uint8_t> visited;

    // Initialize the queue with the startVertex.
    searchQueue.push(startVertex);

    while (!searchQueue.empty()) {

        // Grab the next vertex from the queue.
        Vertex<uint8_t> *currVertex = searchQueue.front();
        searchQueue.pop();

        cout << "Processing \"" << +currVertex->getValue() << "\"" << endl;

        // See if we've found our value, and quit if we have.
        if (currVertex->getValue() == value) {
            return currVertex;
        }

        // Add any unvisited adjacent vertexes to the queue.
        for (Vertex<uint8_t> *adjVertex : currVertex->getAdj()) {
            if (visited.find(adjVertex->getValue()) == visited.end()) {
                searchQueue.push(adjVertex);
                visited.insert(adjVertex->getValue());
            }
        }
    };

    return nullptr;
}

int main() {

    auto *one = new Vertex<uint8_t>(1);
    auto *two = new Vertex<uint8_t>(2);
    auto *three = new Vertex<uint8_t>(3);
    auto *four = new Vertex<uint8_t>(4);
    auto *five = new Vertex<uint8_t>(5);

    one->addEdge(two);
    one->addEdge(five);
    two->addEdge(three);
    two->addEdge(four);
    two->addEdge(five);
    four->addEdge(five);

    Vertex<uint8_t> *found = findVertexBreadthFirst(one, 5);
    cout << endl;
    if (found) {
        cout << "Found \"" << +found->getValue() << "\"" << endl;
    } else {
        cout << "Not found" << endl;
    }
}