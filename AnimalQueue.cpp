#include <iostream>
#include <queue>
#include <chrono>
#include <thread>

using namespace std;

class Animal {
private:
    string name;
    chrono::milliseconds timestamp;

public:
    Animal(string name) {
        this->name = name;
    }

    virtual ~Animal() = default;

    string getName() {
        return this->name;
    }

    void setTimestamp(chrono::milliseconds timestamp) {
        this->timestamp = timestamp;
    }

    chrono::milliseconds getTimestamp() {
        return this->timestamp;
    }
};

class Dog : public Animal {
public:
    Dog(string name) : Animal(name) {
    }
};

class Cat : public Animal {
public:
    Cat(string name) : Animal(name) {
    }
};

class AnimalQueue {
private:
    queue<Dog *> dogQueue;
    queue<Cat *> catQueue;

public:
    AnimalQueue() = default;

    virtual ~AnimalQueue() = default;

    void enqueue(Animal *animal) {
        chrono::milliseconds timestamp =
                chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
        animal->setTimestamp(timestamp);

        if (Dog *dog = dynamic_cast<Dog *>(animal)) {
            dogQueue.push(dog);
        } else if (Cat *cat = dynamic_cast<Cat *>(animal)) {
            catQueue.push(cat);
        } else {
            throw "Invalid animal type";
        }
    }

    Animal *dequeueAny() {
        Animal *animal = nullptr;

        if (dogQueue.empty() && !catQueue.empty()) {
            animal = catQueue.front();
            catQueue.pop();
        } else if (!dogQueue.empty() && catQueue.empty()) {
            animal = dogQueue.front();
            dogQueue.pop();
        } else if (dogQueue.empty() && catQueue.empty()) {
            animal = nullptr;
        } else if (dogQueue.front()->getTimestamp() <= catQueue.front()->getTimestamp()) {
            animal = dogQueue.front();
            dogQueue.pop();
        } else {
            animal = catQueue.front();
            catQueue.pop();
        }

        return animal;
    }

    Dog *dequeueDog() {
        Dog *dog = dogQueue.front();
        if (dog != nullptr) {
            dogQueue.pop();
        }

        return dog;
    }

    Cat *dequeueCat() {
        Cat *cat = catQueue.front();
        if (cat != nullptr) {
            catQueue.pop();
        }

        return cat;
    }
};

void sleep() {
    this_thread::sleep_for(chrono::milliseconds(100));
}

string getNameOrNull(Animal *animal) {
    if (animal == nullptr) {
        return "nullptr";
    }

    return animal->getName();
}

int main() {

    AnimalQueue animalQueue;

    animalQueue.enqueue(new Dog("Fido"));
    sleep();
    animalQueue.enqueue(new Cat("Snickers"));
    sleep();
    animalQueue.enqueue(new Cat("Mittens"));
    sleep();
    animalQueue.enqueue(new Cat("Ascher"));
    sleep();
    animalQueue.enqueue(new Dog("Grace"));
    sleep();
    animalQueue.enqueue(new Cat("Onyx"));
    sleep();
    animalQueue.enqueue(new Dog("River"));

    cout << getNameOrNull(animalQueue.dequeueAny()) << endl;
    cout << getNameOrNull(animalQueue.dequeueDog()) << endl;
    cout << getNameOrNull(animalQueue.dequeueAny()) << endl;
    cout << getNameOrNull(animalQueue.dequeueAny()) << endl;
    cout << getNameOrNull(animalQueue.dequeueCat()) << endl;
    cout << getNameOrNull(animalQueue.dequeueAny()) << endl;
    cout << getNameOrNull(animalQueue.dequeueAny()) << endl;
    cout << getNameOrNull(animalQueue.dequeueAny()) << endl;

    cout << getNameOrNull(animalQueue.dequeueDog()) << endl;
    cout << getNameOrNull(animalQueue.dequeueCat()) << endl;
    cout << getNameOrNull(animalQueue.dequeueAny()) << endl;

    return 0;
}