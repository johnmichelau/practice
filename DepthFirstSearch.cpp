//
// Created by John Michelau on 2019-01-22.
//

#include <iostream>
#include <cstdint>
#include <list>
#include <unordered_set>

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

    list<Vertex<T> *> getAdj() {
        return adj;
    }

    void addEdge(Vertex<T> *vertex) {
        if (vertex == nullptr) {
            throw "vertex cannot be null";
        }

        this->adj.push_back(vertex);
    }

private:
    T value;

    list<Vertex<T> *> adj;
};

Vertex<uint8_t> *findVertexDepthFirst(Vertex<uint8_t> *currVertex, uint8_t value, unordered_set<uint8_t> &visited) {

    if (currVertex == nullptr) {
        throw "vertex cannot be null";
    }

    cout << "Processing \"" << +currVertex->getValue() << "\"" << endl;

    // Mark this node as visited, so that we don't search it again.
    visited.insert(currVertex->getValue());

    // If we've found the value in the current node, just return it.
    if (currVertex->getValue() == value) {
        return currVertex;
    }

    // Search each neighbor recursively.
    for (Vertex<uint8_t> *v : currVertex->getAdj()) {

        if (visited.find(v->getValue()) == visited.end()) {
            Vertex<uint8_t> *foundVertex = findVertexDepthFirst(v, value, visited);

            // If a neighbor found it, we're done and can return it.
            if (foundVertex != nullptr) {
                return foundVertex;
            }
        }
    }

    // We've searched all neighbors and still nothing, so return null.
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

    unordered_set<uint8_t> visited;
    Vertex<uint8_t> *found = findVertexDepthFirst(one, 0, visited);
    cout << endl;
    if (found) {
        cout << "Found \"" << +found->getValue() << "\"" << endl;
    } else {
        cout << "Not found" << endl;
    }
}